#pragma once

template<typename T>
struct DynamicArray
{   
    T* data;
    size_t size;
    size_t capacity;

    DynamicArray();
    ~DynamicArray();

    void push_back(T element);
    void pop_back();
};

#include "DynamicArray.tpp"