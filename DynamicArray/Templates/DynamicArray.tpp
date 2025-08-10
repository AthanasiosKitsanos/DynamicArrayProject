#include "headers.h"
#include "DynamicArray.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, DynamicArray<T>& arr)
{
    os << "List: [";
    for(int i = 0; i < arr.Count(); i++)
    {
        os << arr.Data(i);

        if( i < arr.Count() - 1)
        {
            os << ", ";
        }
    }

    os << "]";

    return os;
}

template<typename T>
T DynamicArray<T>::Data(int& index)
{
    return *(data + index);
}

template<typename T>
int DynamicArray<T>::Count()
{
    return count;
}

template<typename T>
int DynamicArray<T>::Capacity()
{
    return capacity * sizeof(T);
}

template<typename T>
DynamicArray<T>::DynamicArray():data(nullptr), count(0), capacity(2)
{
    data = static_cast<T*>(_aligned_malloc(capacity * sizeof(T), alignof(T)));

    if(data)
    {
        std::cout << "Memory Allocation for data was a success" << std::endl;
    }
    else
    {
        std::cout << "Memory Allocation failed" << std::endl;
    }
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    if(data)
    {
        _aligned_free(data);
        data = nullptr;
    }

    count = 0;
    capacity = 0;

    std::cout << "Destructor was successful" << std::endl;
}

template<typename T>
void DynamicArray<T>::push_back(const T& value)
{   
    if(count >= capacity)
    {
        size_t newCapacity = capacity + 2;
        T* newData = static_cast<T*>(_aligned_realloc(data, newCapacity * sizeof(T), alignof(T)));
        if(!newData)
        {
            std::cout << "Reallocation failed" << std::endl;
            return;
        }

        data = newData;
        capacity = newCapacity;
    }

    new(data + count) T(value);

    count++;
}

template<typename T>
void DynamicArray<T>:: pop_back()
{   
    (data + count - 1)->~T();

    if(capacity - count == 2)
    {
        size_t newCapacity = capacity - 2;

        if(newCapacity == 0)
        {
            newCapacity = 2;
        }

        T* newData = static_cast<T*>(_aligned_realloc(data, newCapacity * sizeof(T), alignof(T)));
        if(!newData)
        {
            std::cout << "Pop Back failed" << std::endl;
            return;
        }

        data = newData;
        capacity = newCapacity;
        newData = nullptr;
    }

    count--;
}

template<typename T>
void DynamicArray<T>::pop_front()
{
    data->~T();

    memcpy(data, data + 1, (count - 1) * sizeof(T));

    if(capacity - count == 2)
    {
        size_t newCapacity = capacity - 2;

        if(newCapacity == 0)
        {
            newCapacity = 2;
        }

        T* newData = static_cast<T*>(_aligned_realloc(data, newCapacity * sizeof(T), alignof(T)));
        if(!newData)
        {
            std::cout << "Pop Back failed" << std::endl;
            return;
        }

        data = newData;
        capacity = newCapacity;
        newData = nullptr;
    }

    count--;
}