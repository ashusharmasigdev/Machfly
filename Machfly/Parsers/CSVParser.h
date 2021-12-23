#pragma once

#include <Core/Defs.h>
#include <fstream>

namespace Machfly::Parsers
{
    
    class CSVParserClass
    {

        protected:

            DString FileName;
            std::fstream File;

        public:

            Void
            OpenFile(DString _fileName);


    };
    

} // namespace Machfly::Parsers
