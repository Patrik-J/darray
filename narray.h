#ifndef NARRAY_H
#define NARRAY_H

#include "array.h"
#include <tuple>

template <typename T>
class NArray {
    public:
        NArray(int N, int M);
        NArray(NArray<T>& na);
        ~NArray();

        // adding/subbing narrays 
        NArray<T> add(NArray<T>& na);
        NArray<T> sub(NArray<T>& na);
        NArray<T> operator+(NArray<T>& a);
        NArray<T> operator-(NArray<T>& a);        

        // index operators
        Array<T>& operator[](int index);
        Array<T>& operator[](int index) const;

        // print array
        template<class U>
        friend std::ostream& operator<<(std::ostream &strm, const NArray<U>& na);

        int rows();
        int columns();

        std::tuple<int, int> shape();

    private:
        int N;
        int M;
        Array<T>* data;
        
        bool shape_comp(NArray<T>& na);
};

#include "narray.cpp"

#endif