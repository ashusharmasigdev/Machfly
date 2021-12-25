#include <Datagrid/Cell.h>

namespace Machfly::DatagridSpace
{

    Cell::Cell(const std::string& _pCellContent = std::string())
        : CellValue(_pCellContent)
    {
        // SubCells.at(SelectedCellXi).at(SelectedCellYi) = _pCellContent;
    }

    void Cell::operator>>(std::string& _pStringPtr)
    {
        if(CellValue.empty())
        {
            _pStringPtr = "";
        }
        else
        {
            _pStringPtr = this->CellValue;
        }
    }

    void Cell::operator<<(std::string& _pStringPtr)
    {
        this->CellValue = _pStringPtr;
    }
    
} // namespace Machfly::DatagridSpace