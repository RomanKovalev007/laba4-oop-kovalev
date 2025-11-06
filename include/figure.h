#pragma once
#include "point.h"
#include <memory>
#include <iostream>

template <typename T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual Point<T> gcenter() const = 0;
    virtual double area() const = 0;

    virtual operator double() const { 
        return area(); 
    }
    
    virtual bool operator==(const Figure &other) const { 
        return area() == other.area(); 
    }

    virtual void print(std::ostream &out) const = 0;
    virtual void read(std::istream &in) = 0;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Figure<T> &figure) {
    figure.print(os);
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, Figure<T> &figure) {
    figure.read(is);
    return is;
}

