/* Tests */
#include <iostream>

#include "Parsers/SVDocumentClass.h"

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


    SVDocument::Document MySVDocument("Datasets/sample.csv", SVDocument::SeparatorArgs(',', true, false, false, true), SVDocument::LineReaderArgs(false, '#', false), SVDocument::LabelArgs(0, -1));


    return 0;

}