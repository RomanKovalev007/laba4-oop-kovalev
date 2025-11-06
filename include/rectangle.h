#pragma once
#include "figure.h"
#include <vector>
#include <cmath>
#include <memory>

template<typename T>
class Rectangle : public Figure<T> {
    std::unique_ptr<Point<T>[]> points;

public:
    Rectangle() : points(std::make_unique<Point<T>[]>(4)) {
        for (size_t i = 0; i < 4; ++i)
            points[i] = Point<T>();
    }

    Rectangle(const std::vector<Point<T>> &newPoints) : points(std::make_unique<Point<T>[]>(4)) {
        if (newPoints.size() != 4)
            throw std::invalid_argument("it is not a rectangle");
        for (size_t i = 0; i < 4; ++i)
            points[i] = newPoints[i];
        sort();
        if (!isRectangle()){
            throw std::invalid_argument("it is not a rectangle");
        }
    }

    Rectangle(const Rectangle& other) : points(std::make_unique<Point<T>[]>(4)) {
        for (size_t i = 0; i < 4; i++) {
            points[i] = other.points[i];
        }
    }

    Rectangle(Rectangle&& other) noexcept : points(std::move(other.points)) {}
    
    Rectangle& operator=(const Rectangle& other){
        if (this != &other) {
            points = std::make_unique<Point<T>[]>(4);
            for (size_t i = 0; i < 4; i++) {
                points[i] = other.points[i];
            }
        }
        return *this;
    }

    Rectangle& operator=(Rectangle&& other) noexcept{
        if (this != &other) {
            points = std::move(other.points);
        }
        return *this;
    }

    bool operator==(const Rectangle& other) const{
        for (size_t i = 0; i < 4; i++) {
            if (points[i].x != other.points[i].x || points[i].y != other.points[i].y) {
                return false;
            }
        }
        return true;
    }
    
    Point<T> gcenter() const override{
        T x = 0, y = 0;
        for (size_t i = 0; i < 4; i++) {
            x += points[i].x;
            y += points[i].y;
        }
        return Point<T>(x / 4, y / 4);
    }

    double area() const override {
        double a = distance(points[0], points[1]);
        double b = distance(points[0], points[2]);
        return a*b;
    }
    
    void print(std::ostream& out) const override{
        out << "rectangle: ";
        for (size_t i = 0; i < 4; i++) {
            out << points[i];
        }
    }

    void read(std::istream& in) override{
        for (size_t i = 0; i < 4; i++) {
            in >> points[i];
        }
        sort();
        if (!isRectangle()){
            throw std::invalid_argument("it is not a rectangle");
        }
    }

    virtual std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Rectangle>(*this);
    }

private:
    void sort(){
        for (int j = 0; j < 3; j++){
            for (int i = 0; i < 3 - j; i++){
                if (points[i].x > points[i+1].x || ((points[i].x == points[i+1].x)&&(points[i].y > points[i+1].y))){
                    Point<T> t = points[i];
                    points[i] = points[i+1];
                    points[i+1] = t;
                }
            }
        }
    }

    bool isRectangle(){
        double eps = 1e-9;

        double side1 = distance(points[0], points[1]);
        double side2 = distance(points[0], points[2]);
        double side3 = distance(points[1], points[3]);
        double side4 = distance(points[2], points[3]);

        double d1 = distance(points[0], points[3]);
        
        if ((std::abs(std::sqrt(side1*side1 + side2*side2) - d1) > eps) || (std::abs(std::sqrt(side3*side3 + side4*side4) - d1) > eps)){
            return false;
        }
        
        return true;
    }
};