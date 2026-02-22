#include "narray.h"

template <typename T>
NArray<T>::NArray(int N, int M) : N(N), M(M) {
    this->data = new Array<T>[N];
    for (int i = 0; i < N; i++) {
        this->data[i].resize(M);
        this->data[i] = Array<T>(M);
    };
};

template <typename T>
NArray<T>::NArray(NArray<T>& na) : N(na.rows()), M(na.columns()) {
    this->data = new Array<T>[this->N];
    for (int i = 0; i < this->N; i++) {
        this->data[i] = na[i];
    };
};

template <typename T>
NArray<T>::~NArray() {
    delete[] this->data;
};

template <typename T>
NArray<T> NArray<T>::add(NArray<T>& na) {
    if (!this->shape_comp(na)) {
        throw_error("NArrays have different dimensions.");
    }
    NArray<T> added = NArray<T>(this->N, this->M);
    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < this->M; j++) {
            added[i][j] = this->data[i][j] + na[i][j];
        }
    }
    return added;
};

template <typename T>
NArray<T> NArray<T>::sub(NArray<T>& na) {
    if (!this->shape_comp(na)) {
        throw_error("NArrays have different dimensions.");
    }
    NArray<T> subbed = NArray<T>(this->N, this->M);
    for (int i = 0; i < this->N; i++) {
        for (int j = 0; j < this->M; j++) {
            subbed[i][j] = this->data[i][j] - na[i][j];
        }
    }
    return subbed;
};

template <typename T>
NArray<T> NArray<T>::operator+(NArray<T>& a) {
    return this->add(a);
};

template <typename T>
NArray<T> NArray<T>::operator-(NArray<T>& a) {
    return this->sub(a);
};

template <typename T>
Array<T>& NArray<T>::operator[](int index) {
    return this->data[index];
};

template <typename T>
Array<T>& NArray<T>::operator[](int index) const {
    return this->data[index];
};

template <typename T>
std::ostream& operator<<(std::ostream &strm, const NArray<T>& na) {
    strm << "NArray = [";
    for (int i = 0; i < na.N; i++) {
        strm << "[";
        
        for (int j = 0; j < na.M; j++) {
            strm << na[i][j] << (j == na.M - 1 ? "" : ", ");
        }

        strm << "]" << (i == na.N - 1 ? "" : ",\n");
    
    }
    strm << "]";
    return strm;
};

template <typename T>
int NArray<T>::rows() {
    return N;
};

template <typename T>
int NArray<T>::columns() {
    return M;
};

template <typename T>
std::tuple<int, int> NArray<T>::shape() {
    return std::tuple(this->N, this->M);
};

template <typename T>
bool NArray<T>::shape_comp(NArray<T>& na) {
    std::tuple<int, int> shape1 = this->shape();
    std::tuple<int, int> shape2 = na.shape();
    if ((std::get<0>(shape1) == std::get<0>(shape2)) && (std::get<1>(shape1) == std::get<1>(shape2))) {
        return true;
    };
    return false;
};