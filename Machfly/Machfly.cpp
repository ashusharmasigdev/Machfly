/* Tests */
#include <iostream>
// #include <Datafly/DataLoader.h>
#include <Datafly/DataPlain.h>

using namespace Machfly::Datafly;

void AppHeader()
{
    std::cout << "\n\nMachfly Test v0.1\n" << std::endl;
}

int main()
{

    AppHeader();

    DataPlain _MyData;

    _MyData.LoadData("Datasets/sample.dat", 0, 0);
    _MyData.ReadFileData();

    return 0;

}