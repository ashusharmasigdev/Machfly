#include <SVDocument/SVDocumentParser.h>

namespace Machfly::SVDocumentSpace
{
    
    SVDocumentParser::SVDocumentParser(const std::string& _pFilepath = std::string())
        : Filestream(_pFilepath)
    {}

    void SVDocumentParser::SVParser()
    {
        if(!GetFileStatus())
        {
            OpenFile(StreamingState::IN);
        }

        if(GetStreamStatus() != StreamingState::IN)
        {
            OpenFile(StreamingState::IN);
        }

        /* It will Return all Cells in a stdVector<stdVector<String and then plug this data into dataGrid, it will called by dataGrid, there will be an already function ReadSV thenn datagrid will call here then it will return and dataGrid will fit the data Into self */
        InternalSVParser();

    }

    void SVDocumentParser::InternalSVParser()
    {
        // std::fstream& SVDoc = RetreiveStream();
        // std::string CurrentLine;
        // while (!SVDoc.eof())
        // {
        //     std::getline(SVDoc, CurrentLine);
        //     if(SVDoc.bad() || SVDoc.fail())
        //     {
        //         break;
        //     }

        //     std::cout<<CurrentLine<<std::endl;
        // }

        std::vector<std::string> DocumentLines = GetDocumentLines();

        for (size_t i = 0; i < DocumentLines.size(); i++)
        {
            // std::cout<<DocumentLines.at(i)<<std::endl;

            auto Cells = SVLineParser(DocumentLines.at(i));

            /* Insert Cells to Data grid */
            /* Fitting in Datagrid

            * Create VectorCells by Size of cellsVector in each time
            * Create VectorSeries by Size of LineSIze
            
            */

            std::cout<<Cells.at(0)<<std::endl;
        }
    }

    std::vector<std::string> SVDocumentParser::SVLineParser(const std::string _pLine)
    {
        SVCellState FieldState = SVCellState::UnquotedField;
        std::vector<std::string> Fields {""};
        size_t i = 0;   /* Current Cell Index */

        for (char c : _pLine)
        {
            switch (FieldState)
            {
                case SVCellState::UnquotedField:
                    switch (c)
                    {
                        case ',':
                            Fields.push_back("");
                            i++;
                            break;
                        case '"':
                            FieldState = SVCellState::QuotedField;
                            break;
                        default:
                            Fields[i].push_back(c); /* Complete the Cell if nothing Stops there */
                            break;
                    }
                    break;
                case SVCellState::QuotedField:
                    switch (c)
                    {
                        case '"':   /* If, there is One Quote before found, then now found the It Will move to QuotedQuote, where it will check for comma first, if found it is not double quoted, if there is quote found, then the cell is double quoted */
                            FieldState = SVCellState::QuotedQuote;
                            break;
                        default:
                            Fields[i].push_back(c);
                            break;
                    }
                    break;
                case SVCellState::QuotedQuote:
                    switch (c)
                    {
                        case ',':
                            Fields.push_back("");
                            i++;
                            FieldState = SVCellState::UnquotedField;
                            break;
                        case '"':
                            Fields[i].push_back('"');
                            FieldState = SVCellState::QuotedField;
                            break;
                        default:
                            FieldState = SVCellState::UnquotedField;
                            break;
                    }
            }
        }
        

        return Fields;
    }

} // namespace Machfly::SVDocumentSpace
