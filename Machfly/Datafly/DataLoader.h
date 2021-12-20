#pragma once

#include <Core/Defs.h>

namespace Machfly::Datafly
{
    
    class DataLoader
    {
        private:

            /* data */

        public:

            DataLoader(/* args */);

            /// @param _pFileName       : Path and name of the File containing the Data
            /// @param _pMaxColumns     : Will Limit the Maximum Selection of Columns, If 0, then All
            /// @param _pMaxRows        : Will Limit the Maximum Selection of Rows, If 0, then All

            Void
            LoadData(const DString _pFileName, Number _pMaxRows, Number _MaxColumns);

            ~DataLoader();

    };
    

} // namespace Machfly::Datafly
