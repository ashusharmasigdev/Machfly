#include <SVDocument/SVDocument.h>

namespace Machfly::SVDocumentSpace
{
    
    SVDocument::SVDocument(const std::string& _pFilepath = std::string())
        : SVDocumentParser(_pFilepath)
    {}

} // namespace Machfly::SVDocumentSpace
