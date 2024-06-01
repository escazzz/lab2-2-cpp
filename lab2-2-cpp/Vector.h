#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
private:
    int* arr;
    int size;

public:
    Vector();
    Vector(int n);
    Vector(const int* a, int n);
    Vector(const Vector& v); // copy constructor
    Vector(Vector&& v) noexcept; // move constructor
    ~Vector();

    int getSize() const;

    int& operator[](int i);
    const int& operator[](int i) const;

    Vector& operator=(const Vector& v); // copy assignment
    Vector& operator=(Vector&& v) noexcept; // move assignment

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    friend std::istream& operator>>(std::istream& is, Vector& v);

    bool operator<(const Vector& v) const;
};

#endif // VECTOR_H
