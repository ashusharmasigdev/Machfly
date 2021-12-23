/* Tests */
#include <iostream>
// #include <Datafly/DataLoader.h>
#include <Datafly/DataPlain.h>

using namespace Machfly::Datafly;

#ifdef MACHFLY_VERSION
#define MACH_VERSION    MACHFLY_VERSION
#else
#define MACH_VERSION    0
#endif

void AppHeader()
{
    std::cout << "\n\nMachfly Test v" << MACH_VERSION << "\n" << std::endl;
}

int main()
{

    AppHeader();

    DataPlain _MyData;

    _MyData.LoadData("Datasets/sample.dat", 0, 0);
    _MyData.ReadFileData();

    return 0;

}