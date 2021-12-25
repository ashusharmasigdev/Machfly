#pragma once

#include <Genric/Filestream.h>
#include <fstream>
#include <vector>

using namespace Machfly::Genric;

namespace Machfly::SVDocumentSpace
{

    enum class SVCellState
    {
        QuotedField,
        UnquotedField,
        QuotedQuote
    };
    
    
    class SVDocumentParser : public Filestream
    {

        public:

            SVDocumentParser(const std::string& _pFilepath);

            void SVParser();

        protected:

            void InternalSVParser();

            std::vector<std::string> SVLineParser(const std::string _pLine);

    };

} // namespace Machfly::SVDocumentSpace
