#ifndef ARRAY_H
#define ARRAY_H

#include "exceptions.h"

template <typename T>
class Array {
    public:
        Array(int length);
        Array(int length, T* entries);

        // adding/subbing arrays with/from each other
        Array add(Array a);
        Array sub(Array a);
        Array operator+(Array a);
        Array operator-(Array a);

        // element-wise multiplication/division of the arrays
        Array mult(Array a);
        Array div(Array a);
        Array operator*(Array a);
        Array operator/(Array a);

        // multiplication/division with doubles
        Array mult(double d);
        Array div(double d);
        Array operator*(double d);
        Array operator/(double d);
        friend Array operator*(double d, Array& a);

        // read indices
        T operator[](int index) const;

        friend bool check_array_dimensions(Array& a1, Array& a2);

    private:
        T* data;
        const int length;
        void initialize(T* entries);
};

#endif 