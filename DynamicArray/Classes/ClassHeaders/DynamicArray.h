#pragma once

template<typename T>
class DynamicArray
{   
    private:
        T* data;
        int count;
        size_t capacity;
        
    public:
        T& operator[](size_t index) const;
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
        void sort(std::function<bool(const T&, const T&)> comp = [](const T& a, const T& b) { return a > b; });
};

#include "DynamicArray.tpp"