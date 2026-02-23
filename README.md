# Dynamic C++ Arrays

This repository is part of a fun side project to create physics simulations. For that, a custom class for dynamic N-dimensional arrays was created. 

## Usage

```cpp
    Array<double> arr = Array<double>(3);
    arr[0] = 1.0;
    arr[1] = 2.0;
    arr[2] = 3.0;

    NArray<double> n_arr = NArray<double>(3, 3);
    n_arr[0][0] = 1.0;
    n_arr[0][1] = 2.0;
    n_arr[0][2] = 3.0;

    n_arr[1][0] = 1.0;
    n_arr[1][1] = 2.0;
    n_arr[1][2] = 3.0;    
    
    n_arr[2][0] = 1.0;
    n_arr[2][1] = 2.0;
    n_arr[2][2] = 3.0;
```

## 'Array<T>'-class methods

### Constructors

```cpp
    Array<T>(int length)
    Array<T>(int length, T* entries)
    Array<T>(Array<T>& a)
```

### Math

```cpp
    Array<double> arr_1 = Array<double>(2)
    Array<double> arr_2 = Array<double>(2)
    double d = 1.0;

    // addition/subtraction
    arr_1.add(arr_2) or arr_1 + arr_2
    arr_1.sub(arr_2) or arr_1 - arr_2

    // element-wise multiplication/division
    arr_1.mult(arr_2) or arr_1 * arr_2
    arr_1.div(arr_2) or arr_1 / arr_2

    // dot product
    arr_1.dot(arr_2)

    // scalar multiplication/division
    arr_1 * d or d * arr_1
    arr_1 / d
```

### Logic
```cpp
    // assignment
    arr_2 = arr_1

    // comparison
    arr_1 == arr_2
    arr_1 != arr_2
```

### Operations on arrays
```cpp
    arr_1.append(2.0)
    arr_2.append(arr_1)

    arr_1.resize(3)
    arr_2.resize(2)
```

### Other
```cpp
    // print array
    std::cout << arr_1 << std::endl

    // length
    arr_1.len()

    // get data
    arr_1.get_data()

    // read/write indices
    arr_1[0] = -1.0
    double d = arr_1[2]

```

## 'NArray<T>'-class methods

### Constructors

```cpp
    NArray<T>(int N, int M)
    NArray<T>(int N, int M, T** entries)
    NArray<T>(T &entries[N][M])
    NArray<T>(NArray<T>& na)
```

### Math

```cpp
    NArray<double> arr_1 = NArray<double>(2, 2)
    NArray<double> arr_2 = NArray<double>(2, 2)
    double d = 1.0;

    // addition/subtraction
    arr_1.add(arr_2) or arr_1 + arr_2
    arr_1.sub(arr_2) or arr_1 - arr_2

    // matrix multiplication
    arr_1.matmult(arr_2) or arr_1 * arr_2

    // element-wise multiplication/division
    arr_1.elmult(arr_2)
    arr_1.eldiv(arr_2)

    // dot product
    arr_1.dot(arr_2)

    // scalar multiplication/division
    arr_1 * d or d * arr_1
    arr_1 / d
```

### Logic
```cpp
    // assignment
    arr_2 = arr_1

    // comparison
    arr_1 == arr_2
    arr_1 != arr_2
```

### Operations on arrays
```cpp
    arr_1.transpose()
```

### Other
```cpp
    // print array
    std::cout << arr_1 << std::endl

    // dimensions
    arr_1.rows()
    arr_1.columns()
    arr_1.shape()

    // read/write indices
    arr_1[0][1] = -1.0
    double d = arr_1[1][0]
    double* row = arr_1[0]

```