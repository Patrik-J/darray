#include "array.h"

template <typename T>
Array<T>::Array(int length) : length(length) {
    this->data = new T[length];
};

template <typename T>
Array<T>::Array(int length, T* entries) : length(length) {
    this->data = new T[length];
    this->initialize(entries);
};

template <typename T>
void Array<T>::initialize(T* entries) {
    for (int i = 0; i < this->length; i++) {
        this->data[i] = entries[i];
    };
};

template <typename T>
Array<T> Array<T>::add(Array<T> a) {
    if (!check_array_dimensions(this, a)) {
        throw_error("Invalid operation: arrays do not have same dimensions.");
    }
    T* added = new T[this->length];
    for (int i = 0; i < this->length; i++) {
        added[i] = this->data[i] + a[i];
    };
    return Array<T>(this->length, added);    
};

template <typename T>
Array<T> Array<T>::sub(Array<T> a) {
    if (!check_array_dimensions(this, a)) {
        throw_error("Invalid operation: arrays do not have same dimensions.");
    }
    T* subbed = new T[this->length];
    for (int i = 0; i < this->length; i++) {
        subbed[i] = this->data[i] - a[i];
    };
    return Array<T>(this->length, subbed);  
};

template <typename T>
Array<T> Array<T>::operator+(Array<T> a) {
    return this->add(a);
};

template <typename T>
Array<T> Array<T>::operator-(Array<T> a) {
    return this->sub(a);
};

template <typename T>
Array<T> Array<T>::mult(Array<T> a) {
    if (!check_array_dimensions(this, a)) {
        throw_error("Invalid operation: arrays do not have same dimensions.");
    }
    T* multiplied = new T[this->length];
    for (int i = 0; i < this->length; i++) {
        multiplied[i] = this->data[i]*a[i];
    };
    return Array<T>(this->length, multiplied);
};

template <typename T>
T Array<T>::operator[](int index) const {
    return this->data[index]; 
}

template <typename T>
bool check_array_dimensions(Array<T>& a1, Array<T>& a2) {
    return (a1.length == a2.length);
}; 