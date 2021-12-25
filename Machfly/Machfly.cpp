/* Tests */
#include <iostream>

#include <Genric/Filestream.h>
#include <SVDocument/SVDocument.h>
#include <Datagrid/Cell.h>
#include <Datagrid/Series.h>
#include <Datagrid/Grid.h>

#ifdef MACHFLY_VERSION
#define MACH_VERSION    MACHFLY_VERSION
#else
#define MACH_VERSION    0
#endif

using namespace Machfly;

void AppHeader()
{
    std::cout << "\n\nMachfly Test v" << MACH_VERSION << "\n" << std::endl;
}

int main()
{

    AppHeader();

    /* Filestream Test */
    // Genric::Filestream MyFile("../Datasets/sample.csv");
    // MyFile.OpenFile(Genric::StreamingState::IN);
    // MyFile.GetDocumentLines();

    SVDocumentSpace::SVDocument MyDocument("../Datasets/sample.csv");
    MyDocument.OpenFile(Genric::StreamingState::IN);

    MyDocument.SVParser();

    /* Datacell Test */
    // DatagridSpace::Cell MyCell("Hello");
    // DatagridSpace::Cell MyCell2("OHO");
    // DatagridSpace::Cell MyCell3("OGO");
    DatagridSpace::Cell MyCell3 = DatagridSpace::Cell("");

    std::string C;

    // /* Get Value of Cell In C */
    MyCell3 >> C;

    // C = "OPP";

    // /* Set Value of Cell In C */
    // MyCell << C;

    // /* Get Value */
    // MyCell >> C;

    // std::cout<<C<<std::endl;

    /* DataSeries Test */

    // std::vector<DatagridSpace::Cell> _Row;
    // _Row.push_back(MyCell);
    // _Row.push_back(MyCell2);
    // _Row.push_back(MyCell3);

    // DatagridSpace::Series MySeries(_Row);
    // DatagridSpace::Series MySeries2(_Row);
    // DatagridSpace::Series MySeries3(_Row);
    // DatagridSpace::Series MySeries4(_Row);

    // MySeries[2] >> C;

    // std::cout<<C<<std::endl;


    // /* Datagrid Test */
    // std::vector<DatagridSpace::Series> SeriesGroup;
    // SeriesGroup.push_back(MySeries);
    // SeriesGroup.push_back(MySeries2);
    // SeriesGroup.push_back(MySeries3);
    // SeriesGroup.push_back(MySeries4);

    // DatagridSpace::Grid MyGrid(SeriesGroup);

    // MyGrid[0][0] >> C;
    
    // std::cout<<C<<std::endl;

    return 0;

}