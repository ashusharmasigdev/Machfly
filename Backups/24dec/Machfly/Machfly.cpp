/* Tests */
#include <iostream>

#include "Datafly/Machframe.h"
#include "Parsers/SVDocumentClass.h"
#include "Parsers/rapidcsv.h"

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


    // SVDocument::Document MySVDocument("Datasets/sample.csv", SVDocument::SeparatorArgs(',', true, false, false, true), SVDocument::LineReaderArgs(false, '#', false), SVDocument::LabelArgs(0, -1));
    // rapidcsv::Document Doc("Datasets/sample.csv");

    // std::cout << Doc.GetCell<int>(1,3) << std::endl;

    Machframe df;

    // df.SetSize(8,60);   /* ColName, RowName */
    // df.SetCell<std::string>(0, 0, "aa");
    // df.LoadSVDocument("Datasets/sample.csv", ",");
    df.LoadSVDocument("Datasets/sample.csv");

    df.GetCell(1,1);

    df.PrintDataGrid();
    

    return 0;

}