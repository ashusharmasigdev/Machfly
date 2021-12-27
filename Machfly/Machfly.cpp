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

    

    return 0;

}