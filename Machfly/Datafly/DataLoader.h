#pragma once

#include <Core/Defs.h>

namespace Machfly::Datafly
{
    
    class DataLoader
    {
        private:

            DString _DataFilePath;
            Number  MaxRows = 0;
            Number  MaxColumns = 0;

        public:

            DataLoader(/* args */);

            Void
            LoadData(const DString, Number, Number);

            ~DataLoader();

    };
    

} // namespace Machfly::Datafly
