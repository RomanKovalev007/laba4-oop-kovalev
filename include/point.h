#pragma once
#include <type_traits>
#include <concepts>
#include <iostream>
#include <cmath>

template <typename T>
concept Scalar = std::is_scalar_v<T>;

template <Scalar T>
class Point {
public:
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator==(const Point<T>& other) const {
        return x == other.x && y == other.y;
    }
    
    friend double distance(const Point<T> &p1, const Point<T> &p2) {
        T dx = p1.x - p2.x;
        T dy = p1.y - p2.y;
        return std::sqrt(dx * dx + dy * dy);
    }
    
    friend std::ostream &operator<<(std::ostream &os, const Point<T> &p) {
        os << "(" << p.x << ", " << p.y << ") ";
        return os;
    }
    
    friend std::istream &operator>>(std::istream &is, Point<T> &p) {
        is >> p.x >> p.y;
        return is;
    }
};