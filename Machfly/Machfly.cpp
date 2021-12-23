/* Tests */
#include <iostream>

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

    return 0;

}