#include <SVDocument/SVDocument.h>

namespace Machfly::SVDocumentSpace
{
    
    SVDocument::SVDocument(const std::string& _pFilepath = std::string())
        : Filestream(_pFilepath)
    {}

} // namespace Machfly::SVDocumentSpace
