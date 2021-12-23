/// @name SVDocumentClass.h
/// @author Ashu Sharma
/// @brief Seprated Values Document Parser Class
/// @date @from:December 23 2021 @to:December 23 2021
/// @version 1
/// @copyright This is Distributed under Machfly Liscence as Not Allowed for Commercial use Without Permission. [Copyright 2021] All rights reserved.

#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace Machfly::SVDocument
{

    struct SeparatorArgs
    {
        SeparatorArgs(const char _pSeparator,
                      const bool _pTrim);

        char Separator;
        char Trim;
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
            std::vector<std::vector<std::string>>   DocumentData;

        public:
        
            /**
             * @brief Construct a new Document object
             * 
             * @param _pPath Seprated Document Path
             */
            Document(const string& _pPath,
                     const SeparatorArgs& _pSeparatorArgs);


            void ReadDocument();
            void ReadDocument(std::istream& _pStream);
            void Clear();

            ~Document();
    
    };
    


} // namespace Machfly::SVDoc
