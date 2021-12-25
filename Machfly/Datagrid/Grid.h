#pragma once

#include <vector>
#include <Datagrid/Series.h>

namespace Machfly::DatagridSpace
{
    
    class Grid
    {
        
        public:

            Grid(const std::vector<Series>& _pSeriesGroup);

            Series operator[](unsigned int _pIndex);
        
        private:
        
            std::vector<Series> SeriesGrid;

    };
    

} // namespace Machfly::DatagridSpace
