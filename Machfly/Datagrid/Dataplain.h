#pragma once

#include <iostream>
#include <SVDocument/SVDocument.h>
#include <Datagrid/Grid.h>

using namespace Machfly::SVDocumentSpace;

namespace Machfly::DatagridSpace
{

    enum class Returning
    {
        _RDocument,
        _RGrid
    };
    
    class Dataplain
    {
        
        public:

            Dataplain();

            /* Will Load the Data File */
            void operator>>(const std::string& _pFileName);

            // template<typename T>
            // void operator<<(T*& _pReturning);
            void operator<<(SVDocument*& _pReturning);
            void operator<<(Grid*& _pReturning);

        private:

            /* Will Late Initialize with Constructor on getting Its Parameters */
            SVDocument* DocumentMethods;
            Grid*       GridData;

    };
    

} // namespace Machfly
