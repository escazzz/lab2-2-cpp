#include "Vector.h"
#include <cstring>

Vector::Vector() : arr(nullptr), size(0) {}

Vector::Vector(int n) : arr(new int[n]), size(n) {}

Vector::Vector(const int* a, int n) : arr(new int[n]), size(n) {
    std::memcpy(arr, a, n * sizeof(int));
}

Vector::Vector(const Vector& v) : arr(new int[v.size]), size(v.size) {
    std::memcpy(arr, v.arr, v.size * sizeof(int));
}

Vector::Vector(Vector&& v) noexcept : arr(v.arr), size(v.size) {
    v.arr = nullptr;
    v.size = 0;
}

Vector::~Vector() {
    delete[] arr;
}

int Vector::getSize() const {
    return size;
}


const int& Vector::operator[](int i) const {
    return arr[i];
}

Vector& Vector::operator=(const Vector& v) {
    if (this != &v) {
        delete[] arr;
        arr = new int[v.size];
        size = v.size;
        std::memcpy(arr, v.arr, v.size * sizeof(int));
    }
    return *this;
}

Vector& Vector::operator=(Vector&& v) noexcept {
    if (this != &v) {
        delete[] arr;
        arr = v.arr;
        size = v.size;
        v.arr = nullptr;
        v.size = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    for (int i = 0; i < v.size; i++) {
        os << v.arr[i] << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Vector& v) {
    int n;
    is >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        is >> a[i];
    }
    delete[] v.arr;
    v.arr = a;
    v.size = n;
    return is;
}

bool Vector::operator<(const Vector& v) const {
    int minSize = size < v.size ? size : v.size;
    for (int i = 0; i < minSize; i++) {
        if (arr[i] < v.arr[i]) {
            return true;
        }
        else if (arr[i] > v.arr[i]) {
            return false;
        }
    }
    return size < v.size;
}
