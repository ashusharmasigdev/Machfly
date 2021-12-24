/* Tests */
#include <iostream>

#include "Datafly/Dataframe.h"
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
    rapidcsv::Document Doc("Datasets/sample.csv");

    std::cout << Doc.GetCell<int>(1,3) << std::endl;


    Datafly::Dataframe df;
    // df[12,34] << fg;
    df.SetRow("gh", rowdata);   /* rowdata will be in string */


    return 0;

}