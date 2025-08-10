#include "headers.h"
#include "DynamicArray.h"

int main()
{
    void* rawMemory = _aligned_malloc(sizeof(DynamicArray<int>), alignof(DynamicArray<int>));

    DynamicArray<int>* intList = new(rawMemory) DynamicArray<int>();

    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cin.get();

    intList->push_back(1);
    intList->push_back(2);
    intList->push_back(3);
    intList->push_back(4);
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();
    
    std::cout << "Pop Back" << std::endl;
    intList->pop_back();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    std::cout << "Pop Back" << std::endl;
    intList->pop_back();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    std::cout << "Pop Front" << std::endl;
    intList->pop_front();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    std::cout << "Pop Front" << std::endl;
    intList->pop_front();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    intList->~DynamicArray();
    _aligned_free(intList);
    intList = nullptr;


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Press any key to exit...";
    std::cin.get();
    return 0;
}