#pragma once

#include <iostream>
#include <vector>

namespace Machfly::DatagridSpace
{
    
    class Gridcell
    {

        public:

            Gridcell(const std::string& _pCellContent);

            /* Convert to Template Later */
            void operator>>(std::string& _pStringPtr);
            void operator<<(std::string& _pStringPtr);

            /* operator[](x,y) to access subcells */

        private:

            // std::vector<std::vector<std::string>> SubCells;
            std::string CellValue;
            unsigned int SeriesXi;  /* Series X Index : Column No.*/
            unsigned int SeriesYi;  /* Series Y Index : Row No.*/
            // unsigned int SeriesZi;  /* Series Z Index : For Later */
            // unsigned int SelectedCellXi = 0;
            // unsigned int SelectedCellYi = 0;
    };
    

} // namespace Machfly::DatagridSpace
