#include <Datagrid/Dataplain.h>

#include <typeinfo>

namespace Machfly::DatagridSpace
{
    
    Dataplain::Dataplain()
    {

    }

    void Dataplain::operator>>(const std::string& _pFileName)
    {
        /* Initializing Document Methods */
        DocumentMethods = new SVDocument(_pFileName);
        // GridData = DocumentMethods.ShareAsGrid();
        // DocumentMethods.GetVectorData() will retyun std::vector<std::vector<std::string>>; Then Transformer will return this as std::vector<Series> or It can also transform into grid all other
        // *GridData = Grid(Transformer.transform(DocumentMethods.GetVectorData(), SERIES));
    }

    void Dataplain::operator<<(SVDocument*& _pReturning)
    {
        _pReturning = DocumentMethods;
    }

    void Dataplain::operator<<(Grid*& _pReturning)
    {
        _pReturning = GridData;
    }

    // template<typename T>
    // void Dataplain::operator<<(T*& _pReturning)
    // {
    //     switch (typeid(T))
    //     {
    //         case typeid(SVDocument):
    //             _pReturning = DocumentMethods;
    //             break;
    //         case typeid(Grid):
    //             _pReturning = GridData;
    //             break;
    //         default:
    //             break;
    //     }
    // }

} // namespace Machfly::DatagridSpace
