#include "headers.h"

int main()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();
    return 0;
}