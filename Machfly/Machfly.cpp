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

    // _MyData.GetData("col:%d/row:%d",3,4);
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t k = 0; k < 2; k++)
        {
            std::cout << i << " =" << _MyData.GetCellFromFeatureX(i, k) << std::endl;
            std::cout << i << " =" << _MyData.GetCellFromFeatureY(i*k) << std::endl; 
        }
        
    }

    // _MyData.OpenFile("Datasets/sample.csv");
    // _MyData.ReadCSVData();
    
    return 0;

}