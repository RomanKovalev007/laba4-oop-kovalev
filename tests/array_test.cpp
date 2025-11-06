#include <gtest/gtest.h>
#include "../include/rectangle.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/array.h"

TEST(ArrayTest, DefaultConstructor) {
    Array<Triangle<double>> arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, Push) {
    Array<Triangle<double>> arr;
    
    auto triangle1 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints1 = {{0, 0}, {4, 0}, {2, 3}};
    *triangle1 = Triangle<double>(trianglePoints1);
    
    auto triangle2 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints2 = {{0, 0}, {3, 0}, {1, 2}};
    *triangle2 = Triangle<double>(trianglePoints2);
    
    arr.push(triangle1);
    arr.push(triangle2);
    
    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_DOUBLE_EQ(arr[0]->area(), 6.0);
    EXPECT_DOUBLE_EQ(arr[1]->area(), 3.0);
}

TEST(ArrayTest, RemoveElement) {
    Array<Triangle<double>> arr;
    
    auto triangle1 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints1 = {{0, 0}, {4, 0}, {2, 3}};
    *triangle1 = Triangle<double>(trianglePoints1);
    
    auto triangle2 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints2 = {{0, 0}, {3, 0}, {1, 2}};
    *triangle2 = Triangle<double>(trianglePoints2);
    
    arr.push(triangle1);
    arr.push(triangle2);
    
    arr.remove(0);

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_DOUBLE_EQ(arr[0]->area(), 3.0);
}

TEST(ArrayTest, CopyConstructor) {
    Array<Triangle<double>> arr1;
    
    auto triangle = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints = {{0, 0}, {4, 0}, {2, 3}};
    *triangle = Triangle<double>(trianglePoints);
    
    arr1.push(triangle);

    Array<Triangle<double>> arr2(arr1);

    EXPECT_EQ(arr2.getSize(), arr1.getSize());
    EXPECT_DOUBLE_EQ(arr2[0]->area(), arr1[0]->area());
}

TEST(ArrayTest, MoveConstructor) {
    Array<Triangle<double>> arr1;
    
    auto triangle = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints = {{0, 0}, {4, 0}, {2, 3}};
    *triangle = Triangle<double>(trianglePoints);
    
    arr1.push(triangle);

    Array<Triangle<double>> arr2(std::move(arr1));

    EXPECT_EQ(arr2.getSize(), 1);
    EXPECT_DOUBLE_EQ(arr2[0]->area(), 6.0);
    EXPECT_EQ(arr1.getSize(), 0);
}

TEST(ArrayTest, CopyOperator) {
    Array<Triangle<double>> arr1;
    
    auto triangle = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints = {{0, 0}, {4, 0}, {2, 3}};
    *triangle = Triangle<double>(trianglePoints);
    
    arr1.push(triangle);

    Array<Triangle<double>> arr2;
    arr2 = arr1;

    EXPECT_EQ(arr2.getSize(), 1);
    EXPECT_DOUBLE_EQ(arr2[0]->area(), 6.0);
}

TEST(ArrayTest, MoveOperator) {
    Array<Triangle<double>> arr1;
    
    auto triangle1 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints1 = {{0, 0}, {4, 0}, {2, 3}};
    *triangle1 = Triangle<double>(trianglePoints1);
    
    auto triangle2 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints2 = {{0, 0}, {3, 0}, {1, 2}};
    *triangle2 = Triangle<double>(trianglePoints2);
    
    arr1.push(triangle1);
    arr1.push(triangle2);

    Array<Triangle<double>> arr2;
    arr2 = std::move(arr1);

    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_DOUBLE_EQ(arr2[0]->area(), 6.0);
    EXPECT_DOUBLE_EQ(arr2[1]->area(), 3.0);
    EXPECT_EQ(arr1.getSize(), 0);
}

TEST(ArrayTest, TotalArea) {
    Array<Triangle<double>> arr;
    
    auto triangle1 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints1 = {{0, 0}, {4, 0}, {2, 3}};
    *triangle1 = Triangle<double>(trianglePoints1);
    
    auto triangle2 = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints2 = {{0, 0}, {3, 0}, {1, 2}};
    *triangle2 = Triangle<double>(trianglePoints2);
    
    arr.push(triangle1);
    arr.push(triangle2);

    double totalArea = arr.totalArea();
    EXPECT_DOUBLE_EQ(totalArea, 9.0);
}

TEST(ArrayTest, SquareArray) {
    Array<Square<double>> squares;
    
    auto square = std::make_shared<Square<double>>();
    std::vector<Point<double>> squarePoints = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    *square = Square<double>(squarePoints);
    
    squares.push(square);
    
    EXPECT_EQ(squares.getSize(), 1);
    EXPECT_DOUBLE_EQ(squares.totalArea(), 4.0);
}

TEST(ArrayTest, RectangleArray) {
    Array<Rectangle<double>> rectangles;
    
    auto rectangle = std::make_shared<Rectangle<double>>();
    std::vector<Point<double>> rectanglePoints = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    *rectangle = Rectangle<double>(rectanglePoints);
    
    rectangles.push(rectangle);
    
    EXPECT_EQ(rectangles.getSize(), 1);
    EXPECT_DOUBLE_EQ(rectangles.totalArea(), 8.0);
}

TEST(ArrayTest, MixedFigureArray) {
    Array<Figure<double>> figures;
    
    auto triangle = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints = {{0, 0}, {4, 0}, {2, 3}};
    *triangle = Triangle<double>(trianglePoints);
    
    auto square = std::make_shared<Square<double>>();
    std::vector<Point<double>> squarePoints = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    *square = Square<double>(squarePoints);
    
    figures.push(triangle);
    figures.push(square);

    EXPECT_EQ(figures.getSize(), 2);
    EXPECT_DOUBLE_EQ(figures.totalArea(), 10.0);
}

TEST(ArrayTest, Print) {
    Array<Triangle<double>> arr;
    
    auto triangle = std::make_shared<Triangle<double>>();
    std::vector<Point<double>> trianglePoints = {{0, 0}, {4, 0}, {2, 3}};
    *triangle = Triangle<double>(trianglePoints);
    
    arr.push(triangle);

    std::stringstream ss;
    arr.print(ss);
    
    EXPECT_FALSE(ss.str().empty());
    EXPECT_TRUE(ss.str().find("triangle") != std::string::npos);
}