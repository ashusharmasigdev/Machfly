#include "SVDocumentClass.h"

#include <algorithm>
#include <fstream>


namespace Machfly::SVDocument
{

    SeparatorArgs::SeparatorArgs(const char _pSeparator = ',',
                                 const bool _pTrim = false,
                                 const bool _pHasCR = false,
                                 const bool _pQuotedLineBreaks = false,
                                 const bool _pAutoQuote = true)
        : Separator(_pSeparator),
          Trim(_pTrim),
          HasCR(_pHasCR),
          QuotedLineBreaks(_pQuotedLineBreaks),
          AutoQuote(_pAutoQuote)
    {}


    LineReaderArgs::LineReaderArgs(const bool _pSkipCommentLines = false,
                                   const char _pCommentPrefix = '#',
                                   const bool _pSkipEmptyLines = false)
        : SkipCommentLines(_pSkipCommentLines),
          CommentPrefix(_pCommentPrefix),
          SkipEmptyLines(_pSkipEmptyLines)
    {}

    LabelArgs::LabelArgs(const int _pColumnNameIdx = 0,
                         const int _pRowNameIdx = -1)
        : ColumnNameIdx(_pColumnNameIdx),
          RowNameIdx(_pRowNameIdx)
    {}


    /**
     * @brief Construct a new Document:: Document object
     */
    Document::Document(const string& _pPath = std::string(),
                       const SeparatorArgs& _pSeparatorArgs = SeparatorArgs(),
                       const LineReaderArgs& _pLineReaderArgs = LineReaderArgs(),
                       const LabelArgs& _pLabelArgs = LabelArgs())
    : DocumentPath(_pPath),
      DocumentSeprator(_pSeparatorArgs),  /* Setters */
      DocumentLineReader(_pLineReaderArgs),
      DocumentLabels(_pLabelArgs)
    {
        if(!DocumentPath.empty())
        {
            /* Start Reading the File */
            ReadDocument();
        }
        else
        {
            std::cerr << "SVDocumentParser[ERROR]:Document::Document()" << std::endl
                      << "DocumentPath Parameter is Empty!" << endl;
        }
    }


    Document::~Document() {}


    void Document::ReadDocument()
    {
        /* Read File */
        std::ifstream fileStream;
        fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fileStream.open(DocumentPath, std::ios::binary);

        if(!fileStream.is_open())
        {
            std::cerr << "SVDocumentParser[ERROR]:Document::ReadDocument()" << std::endl
                      << "Can't Find Given File!" << endl;
        }

        ReadDocumentStream(fileStream);

    }

    void Document::ReadDocumentStream(std::istream& _pStream)
    {
        Clear();

        _pStream.seekg(0, std::ios::end);
        std::streamsize _length = _pStream.tellg();
        _pStream.seekg(0, std::ios::beg);

        /* Check for UTF-8 byte Order mark and skip it when Found */
        if(_length >= 3)
        {
            std::vector<char> Bom3B(3, '\0');
            _pStream.read(Bom3B.data(), 3);
            static const std::vector<char> BomU8 = { '\xef', '\xbb', '\xbf' };
            if(Bom3B != BomU8)
            {
                /* File doesn't start with UTF-8 Byte order mark */
                _pStream.seekg(0, std::ios::beg);
            }
            else
            {
                /* File start with UTF-8 Byte order mark, so skip it */
                _length -= 3;
            }
        }

        SVParser(_pStream, _length);

    }

    void Document::SVParser(std::istream& _pStream, std::streamsize _pFileLength)
    {
        const std::streamsize _BufferLength = 64 * 1024;
        std::vector<char> Buffer(_BufferLength);
        std::vector<std::string> row;
        std::string cell;
        bool Quoted = false;
        int cr = 0;
        int lf = 0;

        while (_pFileLength)
        {
            std::streamsize readLength = std::min<std::streamsize>(_pFileLength, _BufferLength);
            
            /* Problem is in Buffer, is uninited */
            _pStream.read(Buffer.data(), readLength);

            /* Loop to whole File Length */
            for (int i = 0; i < readLength; ++i)
            {
                /* If Quote Found, then this is for Cell */
                if(Buffer[i] == '"')
                {
                    /* If there is found a Quote('"') then Quoted = true and if refound as closing Quote then Quoted = false */
                    if(cell.empty() || cell[0] == '"')
                    {
                        Quoted = !Quoted;
                    }
                    cell += Buffer[i];
                }
                /* If Seprator(,,;,.,etc) found then */
                else if(Buffer[i] == DocumentSeprator.Separator)
                {
                    if(!Quoted)
                    {
                        row.push_back(Unquote(Trim(cell)));
                        cell.clear();   /* empty the cell */
                    }
                    else
                    {
                        cell += Buffer[i];
                    }
                }
                else if(Buffer[i] == '\r')
                {
                    if(DocumentSeprator.QuotedLineBreaks && Quoted)
                    {
                        cell += Buffer[i];
                    }
                    else
                    {
                        ++cr;
                    }
                }
                else if(Buffer[i] == '\n')
                {
                    if(DocumentSeprator.QuotedLineBreaks && Quoted)
                    {
                        cell += Buffer[i];
                    }
                    else
                    {
                        ++lf;
                        if(DocumentLineReader.SkipEmptyLines && row.empty() && cell.empty())
                        {
                            /* Skip Empty Lines */
                        }
                        else
                        {
                            row.push_back(Unquote(Trim(cell)));
                            if(DocumentLineReader.SkipCommentLines && !row.at(0).empty() &&
                                (row.at(0)[0] == DocumentLineReader.CommentPrefix))
                            {
                                /* Comment Found, Skip */
                            }
                            else
                            {
                                DocumentData.push_back(row);
                            }

                            cell.clear();
                            row.clear();
                            Quoted = false;
                        }
                    }
                }
                else
                {
                    cell += Buffer[i];
                }
            }

            _pFileLength -= readLength;
            
        }

        /* Handle last Line without linebreak */
        if(!cell.empty() || !row.empty())
        {
            row.push_back(Unquote(Trim(cell)));
            cell.clear();
            DocumentData.push_back(row);
            row.clear();
        }

        /* Assume CR/LF if at least half the linebreaks have CR */
        DocumentSeprator.HasCR = (cr > (lf / 2));

        /* Set up Column Labels */
        if((DocumentLabels.ColumnNameIdx >= 0) &&
            (static_cast<ssize_t>(DocumentData.size()) > DocumentLabels.ColumnNameIdx))
        {
            int i = 0;
            for (auto& _ColName : DocumentData[DocumentLabels.ColumnNameIdx])
            {
                DocumentColumnNames[_ColName] = i++;
            }
        }

        /* Set up Row labels */
        
        if((DocumentLabels.RowNameIdx >= 0) &&
            (static_cast<ssize_t>(DocumentData.size()) >
            (DocumentLabels.ColumnNameIdx + 1)))
        {
            int i = 0;
            for (auto& _DataRow : DocumentData)
            {
                if(static_cast<ssize_t>(_DataRow.size()) > DocumentLabels.RowNameIdx)
                {
                    DocumentRowNames[_DataRow[DocumentLabels.RowNameIdx]] = i++;
                }
            }
            
        }
        
    }

    std::string Document::Unquote(const std::string& _pStr)
    {
        if(DocumentSeprator.AutoQuote && (_pStr.size() >= 2) && (_pStr.front() == '"') && (_pStr.back() == '"'))
        {
            /* Remove start end Quotes */
            std::string str = _pStr.substr(1, _pStr.size() - 2);

            /* Unescape quotes in string */
            ReplaceString(str, "\"\"", "\"");

            return str;
        }
    }

    std::string Document::Trim(const std::string& _pStr)
    {
        if(DocumentSeprator.Trim)
        {
            std::string str = _pStr;

            // ltrim
            str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) { return !isspace(ch); }));

            // rtrim
            str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) { return !isspace(ch); }).base(), str.end());

            return str;
        }
        else
        {
            return _pStr;
        }
    }

    void Document::ReplaceString(std::string& _pStr, const std::string& _pSearch, const std::string& _pReplace)
    {
        size_t pos = 0;
        while ((pos = _pStr.find(_pSearch, pos)) != std::string::npos)
        {
            _pStr.replace(pos, _pSearch.size(), _pReplace);
            pos += _pReplace.size();
        }
    }

    void Document::Clear()
    {
        DocumentData.clear();
        DocumentRowNames.clear();
        DocumentColumnNames.clear();
    }

    
} // namespace Machfly::SVDoc
