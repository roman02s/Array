#pragma once
#include <iostream>
#include <cstdlib>


template<typename T>
class Array {
private:
    T*     arr;
    size_t num;
public:
    Array(): arr(nullptr), num(0) {}
    Array(const Array& a):arr(nullptr), num(0) {*this = a;}
    Array(Array&& a):arr(nullptr), num(0) {*this = std::forward<decltype(a)>(a);}
    explicit Array(size_t n, const T& v = T()):arr(nullptr), num(0) {resize(n, v);}
    ~Array(){ clear(); }
public:

    size_t size() const { return num; }
    T* begin() { return arr; }
    T* end() { return arr + num; }
    const T* cbegin() const { return arr; }
    const T* cend() const { return arr + num; }


    // поиск элемента
    T* find_element(T& element) {
        T *i = arr, *end = arr + num;
        T *p = i;
        for (; i != end; ++i) {
            if (*p == element) {
                p = i;
                return p;
            }
        }
        return end;
    }


//    пирамидальная сортировка
    template<typename Cmp>
    void sort(Cmp cmp){
        if(num <= 1)
            return;

        for(size_t i = num / 2 + 1; i > 0; --i)
            _heapify(i - 1, cmp, num);

        for(size_t j = num - 1; j > 0; --j){
            std::swap(arr[0], arr[j]);
            _heapify(0, cmp, j);
        }
    }

    Array& operator = (const Array& a){
        if(this != &a){
            resize(a.num);
            std::copy(a.cbegin(), a.cend(), this->arr);
        }
        return *this;
    }

    Array& operator = (Array&& a){
        if(this != &a){
            clear();
            arr = a.arr;
            num = a.num;
            a.arr = nullptr;
            a.num = 0;
        }
        return *this;
    }

    T& operator [] (size_t i){ return arr[i]; }
    const T& operator [] (size_t i) const { return arr[i]; }

    void clear(){
        if(arr != nullptr)
            delete[] arr;
        arr = nullptr;
        num = 0;
    }
private:
    template<typename Cmp>
    void _heapify(size_t i, Cmp cmp, size_t cnt){
        size_t l, r, h;
        while(true){
            l = 2 * i + 1;
            r = l + 1;
            if((l < cnt) && cmp(arr[i], arr[l]))
                h = l;
            else
                h = i;

            if((r < cnt) && cmp(arr[h], arr[r]))
                h = r;

            if(h != i){
                std::swap(arr[i], arr[h]);
                i = h;
            } else
                break;
        }
    }
    // изменение размера
    void resize(size_t n, const T& v = T()) {
        clear();
        arr  = new T[n];
        T* e = arr + n;
        for(T* p = arr; p != e; ++p)
            *p = v;
        num = n;
    }
};