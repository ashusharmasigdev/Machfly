#pragma once

#include <Core/Defs.h>
#include <fstream>

namespace Machfly::Datafly
{
    
    class DataLoader
    {
        protected:

            DString _DataFilePath;
            Number  MaxRows = 0;
            Number  MaxColumns = 0;
            Double  NumInstance = 0;
            Double  NumAttributes = 0;
            
            std::fstream    _DataFile;

        public:

            Void
            LoadData(const DString, UNumber, UNumber);

            Void
            CloseDataFile();

            UNumber
            InstanceSize();

            UNumber
            AttributeSize();

    };
    

} // namespace Machfly::Datafly
