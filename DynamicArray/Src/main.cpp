#include "headers.h"
#include "DynamicArray.h"

int main()
{
    void* rawMemory = malloc(sizeof(DynamicArray<int>));

    DynamicArray<int>* intPtr = new(rawMemory) DynamicArray<int>();

    intPtr->push_back(4);
    intPtr->push_back(5);

    std::cout << "\nPush_Back:" << std::endl;

    for(size_t i = 0; i < intPtr->size ; i++)
    {
        std::cout << intPtr->data[i] << std::endl;
    }

    intPtr->pop_back();

    std::cout << "\nPop_Back:" << std::endl;
    for(size_t i = 0; i < intPtr->size ; i++)
    {
        std::cout << intPtr->data[i] << std::endl;
    }

    intPtr->push_back(5);

    std::cout << "\nPush_Back:" << std::endl;

    for(size_t i = 0; i < intPtr->size ; i++)
    {
        std::cout << intPtr->data[i] << std::endl;
    }

    intPtr->~DynamicArray();
    free(rawMemory);
    intPtr = nullptr;
    rawMemory = nullptr;


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();
    return 0;
}