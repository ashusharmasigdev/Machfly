#include <Datagrid/Grid.h>

namespace Machfly::DatagridSpace
{
    
    Grid::Grid(const std::vector<Series>& _pSeriesGroup)
        : SeriesGrid(_pSeriesGroup)
    {}

    Series Grid::operator[](unsigned int _pIndex)
    {
        if(SeriesGrid.size() < _pIndex)
        {
            std::out_of_range("Given Series Index doesn't Exist!");
            exit(1);
        }

        return SeriesGrid.at(_pIndex);
    }

} // namespace Machfly::DatagridSpace
