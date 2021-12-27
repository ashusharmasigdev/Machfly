#include <Datagrid/Dataplain.h>

namespace Machfly::DatagridSpace
{
    
    Dataplain::Dataplain()
    {

    }

    void Dataplain::operator>>(const std::string& _pFileName)
    {
        /* Initializing Document Methods */
        *DocumentMethods = SVDocument(_pFileName);
        // GridData = DocumentMethods.ShareAsGrid();
        // DocumentMethods.GetVectorData() will retyun std::vector<std::vector<std::string>>; Then Transformer will return this as std::vector<Series> or It can also transform into grid all other
        // *GridData = Grid(Transformer.transform(DocumentMethods.GetVectorData(), SERIES));
    }

} // namespace Machfly::DatagridSpace
