/* Tests */
#include <iostream>

#include <Genric/Filestream.h>
#include <SVDocument/SVDocument.h>

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

    return 0;

}