#pragma once

#include <iostream>
#include <SVDocument/SVDocument.h>
#include <Datagrid/Grid.h>

using namespace Machfly::SVDocumentSpace;

namespace Machfly::DatagridSpace
{
    
    class Dataplain
    {
        
        public:

            Dataplain();

            /* Will Load the Data File */
            void operator>>(const std::string& _pFileName);

        private:

            /* Will Late Initialize with Constructor on getting Its Parameters */
            SVDocument* DocumentMethods;
            Grid*       GridData;

    };
    

} // namespace Machfly
