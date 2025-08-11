#include "headers.h"
#include "DynamicArray.h"

int main()
{
    void* rawMemory = _aligned_malloc(sizeof(DynamicArray<int>), alignof(DynamicArray<int>));

    DynamicArray<int>* intList = new(rawMemory) DynamicArray<int>();

    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cin.get();

    intList->push_back(4);
    intList->push_back(3);
    intList->push_back(2);
    intList->push_back(1);
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Items Capacity: " << intList->items_capacity() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    intList->sort();
    std::cout << "After sorting" << std::endl;
    std::cout << *intList << std::endl;

    std::cout << "Pop Front value 1:" << std::endl;
    intList->pop_front();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Items Capacity: " << intList->items_capacity() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    std::cout << "Removing value 2" << std::endl;
    intList->remove_value(2);
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Items Capacity: " << intList->items_capacity() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    int value = 3;
    std::cout << "Index of " << value << ": " << intList->find_index(value) << std::endl;
    value = 4;
    std::cout << "Index of " << value << ": " << intList->find_index(value) << std::endl;
    
    std::cout << "Pop Back value: 4" << std::endl;
    intList->pop_back();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Items Capacity: " << intList->items_capacity() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    

    std::cout << "Pop Back value: 3" << std::endl;
    intList->pop_back();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Items Capacity: " << intList->items_capacity() << std::endl;
    std::cout << "Blocks Occupied: " << intList->Capacity() << std::endl;
    std::cout << *intList << std::endl;
    std::cin.get();

    

    std::cout << "Pop Front (empty list)" << std::endl;
    intList->pop_front();
    std::cout << "Items: " << intList->Count() << std::endl;
    std::cout << "Items Capacity: " << intList->items_capacity() << std::endl;
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