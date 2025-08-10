#pragma once

template<typename T>
class DynamicArray
{   
    private:
        T* data;
        int count;
        size_t capacity;
        

    public:
        DynamicArray();
        ~DynamicArray();
        
        int Count();
        int items_capacity();
        int Capacity();
        int find_index(const T& value);

        T index(const T& index);
        
        void push_back(const T& value);
        void pop_back();
        void pop_front();
        void remove_value(const T& value);
};

#include "DynamicArray.tpp"