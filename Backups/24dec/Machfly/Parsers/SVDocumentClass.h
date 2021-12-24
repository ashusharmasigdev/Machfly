/// @name SVDocumentClass.h
/// @author Ashu Sharma
/// @brief Seprated Values Document Parser Class
/// @date @from:December 23 2021 @to:December 23 2021
/// @version 1
/// @copyright This is Distributed under Machfly Liscence as Not Allowed for Commercial use Without Permission. [Copyright 2021] All rights reserved.

#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace Machfly::SVDocument
{

    struct SeparatorArgs
    {
        SeparatorArgs(const char _pSeparator,
                      const bool _pTrim,
                      const bool _pHasCR,
                      const bool _pQuotedLineBreaks,
                      const bool _pAutoQuote);

        char Separator;
        char Trim;
        bool HasCR;
        bool QuotedLineBreaks;
        bool AutoQuote;
    };


    struct LineReaderArgs
    {
        LineReaderArgs(const bool _pSkipCommentLines,
                       const char _pCommentPrefix,
                       const bool _pSkipEmptyLines);

        bool SkipCommentLines;
        char CommentPrefix;
        bool SkipEmptyLines;
    };
    

    struct LabelArgs
    {
        LabelArgs(const int _pColumnNameIdx,
                  const int _pRowNameIdx);

        int ColumnNameIdx;
        int RowNameIdx;
    };
    
    
    
    /**
     * @brief Class to Represent a CSV Document
     * 
     */
    class Document
    {

        private:

            string DocumentPath;
            SeparatorArgs DocumentSeprator;
            LineReaderArgs DocumentLineReader;
            LabelArgs DocumentLabels;
            std::vector<std::vector<std::string>>   DocumentData;
            std::map<std::string, size_t>   DocumentColumnNames;
            std::map<std::string, size_t>   DocumentRowNames;

        public:
        
            /**
             * @brief Construct a new Document object
             * 
             * @param _pPath Seprated Document Path
             */
            Document(const string& _pPath,
                     const SeparatorArgs& _pSeparatorArgs,
                     const LineReaderArgs& _pLineReaderArgs,
                     const LabelArgs& _pLabelArgs);


            void ReadDocument();
            void ReadDocumentStream(std::istream& _pStream);
            void Clear();

            void SVParser(std::istream& _pStream, std::streamsize _pFileLength);

            std::string Unquote(const std::string& _pStr);
            std::string Trim(const std::string& _pStr);

            void ReplaceString(std::string& _pStr, const std::string& _pSearch, const std::string& _pReplace);

            ~Document();
    
    };
    


} // namespace Machfly::SVDoc
