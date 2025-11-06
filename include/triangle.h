#pragma once
#include "figure.h"
#include <vector>
#include <cmath>
#include <stdexcept>

template<typename T>
class Triangle : public Figure<T> {
    Point<T> points[3];

public:
    Triangle() {
        for (size_t i = 0; i < 3; ++i)
            points[i] = Point<T>();
    }

    Triangle(const std::vector<Point<T>> &newPoints) {
        if (newPoints.size() != 3)
            throw std::invalid_argument("it is not a triangle");
        for (size_t i = 0; i < 3; ++i)
            points[i] = newPoints[i];
        if (!isTriangle()){
            throw std::invalid_argument("it is not a triangle");
        }
        sort();
    }

    Triangle(const Triangle& other) {
        for (size_t i = 0; i < 3; i++) {
            points[i] = other.points[i];
        }
    }

    Triangle(Triangle&& other) noexcept {
        for (size_t i = 0; i < 3; i++) {
            points[i] = std::move(other.points[i]);
        }
    }

    Triangle& operator=(const Triangle& other) {
        if (this != &other) {
            for (size_t i = 0; i < 3; i++) {
                points[i] = other.points[i];
            }
        }
        return *this;
    }

    Triangle& operator=(Triangle&& other) noexcept {
        if (this != &other) {
            for (size_t i = 0; i < 3; i++) {
                points[i] = std::move(other.points[i]);
            }
        }
        return *this;
    }

    bool operator==(const Triangle& other) const {
        for (size_t i = 0; i < 3; i++) {
            if (points[i].x != other.points[i].x || points[i].y != other.points[i].y) {
                return false;
            }
        }
        return true;
    }

    Point<T> gcenter() const override {
        T x = 0, y = 0;
        for (size_t i = 0; i < 3; i++) {
            x += points[i].x;
            y += points[i].y;
        }
        return Point<T>(x / 3, y / 3);
    }

    double area() const override {
        double a = distance(points[0], points[1]);
        double b = distance(points[0], points[2]);
        double c = distance(points[1], points[2]);
        
        double p = (a+b+c) * 0.5;
        return std::sqrt(p*(p-a)*(p-b)*(p-c));
    }

    void print(std::ostream& out) const override {
        out << "triangle: ";
        for (size_t i = 0; i < 3; i++) {
            out << points[i];
        }
    }

    void read(std::istream& in) override {
        for (size_t i = 0; i < 3; i++) {
            in >> points[i];
        }
        if (!isTriangle()){
            throw std::invalid_argument("it is not a triangle");
        }
        sort();
    }

private:
    void sort(){
        for (int j = 0; j < 2; j++){
            for (int i = 0; i < 2 - j; i++){
                if (points[i].x > points[i+1].x || ((points[i].x == points[i+1].x)&&(points[i].y > points[i+1].y))){
                    Point<T> t = points[i];
                    points[i] = points[i+1];
                    points[i+1] = t;
                }
            }
        }
    }

    bool isTriangle(){
        double a = distance(points[0], points[1]);
        double b = distance(points[0], points[2]);
        double c = distance(points[1], points[2]);

        if ((a+b <= c) || (a+c <= b) || (c+b <= a)){
            return false;
        }
        return true;
    }
};