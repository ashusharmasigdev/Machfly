#include <Datagrid/Gridcell.h>

namespace Machfly::DatagridSpace
{

    Gridcell::Gridcell(const std::string& _pCellContent = std::string())
        : CellValue(_pCellContent)
    {
        // SubCells.at(SelectedCellXi).at(SelectedCellYi) = _pCellContent;
    }

    void Gridcell::operator>>(std::string& _pStringPtr)
    {
        _pStringPtr = this->CellValue;
    }

    void Gridcell::operator<<(std::string& _pStringPtr)
    {
        this->CellValue = _pStringPtr;
    }
    
} // namespace Machfly::DatagridSpace