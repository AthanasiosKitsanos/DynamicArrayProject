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
        int Capacity();
        T Data(int& index);
        
        void push_back(const T& value);
        void pop_back();
        void pop_front();
};

#include "DynamicArray.tpp"