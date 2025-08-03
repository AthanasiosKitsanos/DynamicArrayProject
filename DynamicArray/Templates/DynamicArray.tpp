#include "headers.h"
#include "DynamicArray.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, const DynamicArray<T>& arr)
{
    for(size_t i = 0; i < arr.size; i++)
    {
        os << arr.data[i];
    }

    return os;
}

template<typename T>
DynamicArray<T>::DynamicArray():data(nullptr), size(0), capacity(0)
{
    std:: cout << "Memory allocated" << std::endl; 
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    if(data)
    {
        _aligned_free(data);
        data = nullptr;
        std::cout << "Data pointer is null" << std::endl;
    }
    
    size = 0;
    capacity = 0;
    std::cout << "Dynamic Array Destructor was successful" << std::endl;
}

template<typename T>
void DynamicArray<T>::push_back(T element)
{
    if(size >= capacity)
    {
        size_t newCapacity = capacity >  0 ? capacity * 2 : 4;

        T* newData = static_cast<T*>(_aligned_malloc(alignof(T), newCapacity * sizeof(T)));

        if(!newData)
        {
            std::cout << "Reallocation failed" << std::endl;
            return;
        }

        if(data)
        {
            memcpy(newData, data, size * sizeof(T));
            _aligned_free(data);
        }

        data = static_cast<T*>(newData);
        capacity = newCapacity;
        newData = nullptr;
    }

    *(data + size) = element;

    size++;
}

template<typename T>
void DynamicArray<T>::pop_back()
{
    if(size == 0)
    {
        std::cout << "There is nothing to delete";
        return;
    }
    size--;

    *(data + size) = ~T();
}