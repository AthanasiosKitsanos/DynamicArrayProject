#include "headers.h"
#include "DynamicArray.h"

template<typename T>
std::ostream& operator<<(std::ostream& os, DynamicArray<T>& arr)
{
    os << "List: [";
    for(int i = 0; i < arr.Count(); i++)
    {
        os << arr.index(i);

        if( i < arr.Count() - 1)
        {
            os << ", ";
        }
    }

    os << "]";

    return os;
}



template<typename T>
T DynamicArray<T>::index(const T& index)
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
int DynamicArray<T>::items_capacity()
{
    return count * sizeof(T);
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
    if(count == 0)
    {
        std::cout << "The list is empty, there is nothing to remove" << std::endl;
        return;
    }

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
    if(count == 0)
    {
        std::cout << "The list is empty, there is nothing to remove" << std::endl;
        return;
    }

    data->~T();

    memcpy(data, data + 1, (count - 1) * sizeof(T));
    
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
int DynamicArray<T>::find_index(const T& value)
{
    for(int i = 0; i < count; i++)
    {
        if(*(data + i) == value)
        {
            return i;
        }
    }

    return -1;
}

template<typename T>
void DynamicArray<T>::remove_value(const T& value)
{
    if(count == 0)
    {
        std::cout << "The list is empty, there is nothing to remove" << std::endl;
        return;
    }

    int index = 0;
    while(index < count && *(data + index) != value)
    {
        index++;
    }

    if(index == count)
    {
        std::cout << "Value not found" << std::endl;
        return;
    }

    (data + index)->~T();

    memcpy(data + index, data + index + 1, (count - index - 1) * sizeof(T));

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
void DynamicArray<T>::sort(std::function<bool(const T&, const T&)> comp)
{
    T current;
    for(int i = 0; i < count -1; i++)
    {
        for(int j = 0; j < count - 1 - i; j++)
        {
            if(comp(data[j], data[j + 1]))
            {
                current = data[j];
                data[j] = data[j + 1];
                data[j + 1] = current;
            }
        }
    }
}