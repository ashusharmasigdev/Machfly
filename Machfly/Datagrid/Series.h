#pragma once

#include <iostream>
#include <vector>
#include <Datagrid/Cell.h>

namespace Machfly::DatagridSpace
{
    
    class Series
    {
        
        public:

            Series(const std::vector<Cell>& _pCells);

            // std::string& RetrieveCell();
            Cell operator[](unsigned int _pIndex);
            

        private:

            std::vector<Cell> CellSeries;

    };
    

} // namespace Machfly::DatagridSpace
