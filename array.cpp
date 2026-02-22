#include "array.h"

template <typename T>
Array<T>::Array(int length) : length(length) {
    this->data = new T[length];
    this->initialize(this->empty_array(length));
};

template <typename T>
Array<T>::Array(int length, T* entries) : length(length) {
    this->data = new T[length];
    this->initialize(entries);
};

template <typename T>
Array<T>::Array(Array<T>& a) : length(a.len()) {
    this->data = new T[a.len()];
    for (int i = 0; i < a.len(); i++) {
        this->data[i] = a[i];
    };
};

template <typename T>
Array<T>::~Array() {
    delete[] this->data;
};

template <typename T>
void Array<T>::initialize(T* entries) {
    for (int i = 0; i < this->length; i++) {
        this->data[i] = entries[i];
    };
};

template <typename T>
Array<T> Array<T>::add(Array<T>& a) {
    if (!check_array_dimensions(*this, a)) {
        throw_error("Arrays have different dimensions.");
    }
    Array<T> a_new = Array<T>(this->length);
    for (int i = 0; i < this->length; i++) {
        a_new[i] = this->data[i] + a[i];
    };
    return a_new;    
};

template <typename T>
Array<T> Array<T>::sub(Array<T>& a) {
    if (!check_array_dimensions(*this, a)) {
        throw_error("Arrays have different dimensions.");
    }
    Array<T> a_new = Array<T>(this->length);
    for (int i = 0; i < this->length; i++) {
        a_new[i] = this->data[i] - a[i];
    };
    return a_new;  
};

template <typename T>
Array<T> Array<T>::operator+(Array<T>& a) {
    return this->add(a);
};

template <typename T>
Array<T> Array<T>::operator-(Array<T>& a) {
    return this->sub(a);
};

template <typename T>
Array<T> Array<T>::mult(Array<T>& a) {
    if (!check_array_dimensions(*this, a)) {
        throw_error("Arrays have different dimensions.");
    }
    Array<T> a_new = Array<T>(this->length);
    for (int i = 0; i < this->length; i++) {
        a_new[i] = this->data[i]*a[i];
    };
    return a_new;
};

template <typename T>
Array<T> Array<T>::div(Array<T>& a) {
    if (!check_array_dimensions(*this, a)) {
        throw_error("Arrays have different dimensions.");
    }
    Array<T> a_new = Array<T>(this->length);
    for (int i = 0; i < this->length; i++) {
        a_new[i] = this->data[i]/a[i];
    };
    return a_new;
};

template <typename T>
Array<T> Array<T>::operator*(Array<T>& a) {
    return this->mult(a);
};

template <typename T>
Array<T> Array<T>::operator/(Array<T>& a) {
    return this->div(a);
};

template <typename T>
Array<T> Array<T>::mult(double d) {
    Array<T> a_new = Array<T>(this->length);
    for (int i = 0; i < this->length; i++) {
        a_new[i] = this->data[i]*d;
    };
    return a_new;
};

template <typename T>
Array<T> Array<T>::div(double d) {
    Array<T> a_new = Array<T>(this->length);
    for (int i = 0; i < this->length; i++) {
        a_new[i] = this->data[i]/d;
    };
    return a_new;
};

template <typename T>
Array<T> Array<T>::operator*(double d) {
    return this->mult(d);
};

template <typename T>
Array<T> Array<T>::operator/(double d) {
    return this->div(d);
};

template <typename T>
T& Array<T>::operator[](int index) {
    return this->data[index]; 
}

template <typename T>
T& Array<T>::operator[](int index) const {
    return this->data[index]; 
}

template <typename T>
Array<T> operator*(double d, Array<T>& a) {
    return a*d;
};

template <typename T>
Array<T> Array<T>::operator=(const Array<T>& a) {
    if (this != &a) {
        if (this->length != a.len()) {
            throw_error("Cannot assign arrays of different lengths.");
        }
        for (int i = 0; i < this->length; i++) {
            this->data[i] = a[i];
        }
    }
    return *this;
};

template <typename T>
bool Array<T>::operator==(const Array<T>& a) {
    if (this != &a) {
        if (this->length != a.len()) {
            return false;
        }
        for (int i = 0; i < this->length; i++) {
            if (this->data[i] != a[i]) {
                return false;
            }
        }
    }
    return true;
};

template <typename T>
bool Array<T>::operator!=(const Array<T>& a) {
    return not (*this == a);
};

template <typename T>
std::ostream& operator<<(std::ostream &strm, const Array<T>& a) {
    strm << "Array = [";
    for (int i = 0; i < a.length; i++) {
        strm << a[i] << (i == a.length - 1 ? "" : ", ");
    }
    strm << "]";
    return strm;
};

template <typename T>
int Array<T>::len() {
    return this->length;
};

template <typename T>
T* Array<T>::get_data() {
    return this->data;
};

template <typename T>
bool check_array_dimensions(Array<T> a1, Array<T> a2) {
    return (a1.len() == a2.len());
};

template <typename T>
T* Array<T>::empty_array(int length) {
    T* zero = new T[length];
    for (int i = 0; i < length; i++) {
        zero[i] = (T) 0.0;
    }
    return zero;
};

template <typename T>
void Array<T>::resize(int new_length) {
    if (new_length >= 1) {
        T* new_data = new T[new_length];
        int old_length = this->len();

        if (new_length > old_length) {
            for (int i = 0; i < old_length; i++) {
                new_data[i] = this->data[i];
            }
            for (int i = old_length; i < new_length; i++) {
                new_data[i] = (T) 0.0;
            }   
        } else if (new_length < old_length) {
            for (int i = 0; i < new_length; i++) {
                new_data[i] = this->data[i];
            }  
        };

        this->length = new_length;
        this->data = new_data;
    };
};