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
            Double  NumInstance = 0;
            Double  NumAttributes = 0;

        public:

            Void
            LoadData(const DString, UNumber, UNumber);

            Void
            ReadFileData();

            UNumber
            InstanceSize();

            UNumber
            AttributeSize();

    };
    

} // namespace Machfly::Datafly
