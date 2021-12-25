#include <Datagrid/Series.h>

namespace Machfly::DatagridSpace
{
    
    Series::Series(const std::vector<Cell>& _pCells)
        : CellSeries(_pCells)
    {}

    Cell Series::operator[](unsigned int _pIndex)
    {
        if(CellSeries.size() < _pIndex)
        {
            std::out_of_range("Given Cell Index doesn't Exist!");
            exit(1);
        }
        return CellSeries.at(_pIndex);
    }

} // namespace Machfly::DatagridSpace
