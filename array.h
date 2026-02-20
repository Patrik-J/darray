#ifndef ARRAY_H
#define ARRAY_H

#include "exceptions.h"
#include <iostream>

template <typename T>
class Array {
    public:
        Array(int length);
        Array(int length, T* entries);
        Array(Array<T>& a);
        ~Array();

        // adding/subbing arrays with/from each other
        Array<T> add(Array<T>& a);
        Array<T> sub(Array<T>& a);
        Array<T> operator+(Array<T>& a);
        Array<T> operator-(Array<T>& a);

        // element-wise multiplication/division of the arrays
        Array<T> mult(Array<T>& a);
        Array<T> div(Array<T>& a);
        Array<T> operator&(Array<T>& a);
        Array<T> operator/(Array<T>& a);

        // multiplication/division with doubles
        Array<T> mult(double d);
        Array<T> div(double d);
        Array<T> operator*(double d);
        Array<T> operator/(double d);
        template<class U>
        friend Array<U> operator*(double d, Array<U>& a);

        // copy and assignment
        Array<T> operator=(const Array<T>& a);

        // read indices
        T& operator[](int index);
        T& operator[](int index) const;

        template<class U>
        friend bool check_array_dimensions(Array<U> a1, Array<U> a2);

        // print array
        template<class U>
        friend std::ostream& operator<<(std::ostream &strm, const Array<U>& a);

        int len();
        T* get_data();

    private:
        T* data;
        const int length;
        void initialize(T* entries);
        T* empty_array(int length);
};

#include "array.cpp"

#endif 