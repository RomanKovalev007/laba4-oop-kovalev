#include <gtest/gtest.h>
#include "../include/triangle.h"

TEST(TriangleTest, DefaultConstructor) {
    Triangle<double> tr;
    EXPECT_NO_THROW(tr.area());
}

TEST(TriangleTest, ValidTriangleCreation) {
    std::vector<Point<double>> points = {{0, 4}, {4, 0}, {0, 0}};
    EXPECT_NO_THROW(Triangle<double> tr(points));
}

TEST(TriangleTest, InvalidTriangleCreation) {
    std::vector<Point<double>> points = {{0, 0}, {1, 0}, {2, 0}};
    EXPECT_THROW(Triangle<double> tr(points), std::invalid_argument);
}

TEST(TriangleTest, CopyConstructor) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<double> tr1(points);
    Triangle<double> tr2(tr1);
    
    EXPECT_DOUBLE_EQ(tr1.area(), tr2.area());
}

TEST(TriangleTest, MoveConstructor) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<double> tr1(points);
    Triangle<double> tr2(std::move(tr1));
    
    EXPECT_DOUBLE_EQ(tr2.area(), 6.0);
}

TEST(TriangleTest, CopyOperator) {
    std::vector<Point<double>> points1 = {{0, 0}, {4, 0}, {2, 3}};
    std::vector<Point<double>> points2 = {{0, 0}, {5, 0}, {2, 4}};
    
    Triangle<double> tr1(points1);
    Triangle<double> tr2(points2);
    
    tr2 = tr1;
    EXPECT_DOUBLE_EQ(tr1.area(), tr2.area());
}

TEST(TriangleTest, Area) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<double> tr(points);
    EXPECT_DOUBLE_EQ(tr.area(), 6.0);
}

TEST(TriangleTest, GeometricCenter) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<double> tr(points);
    Point<double> center = tr.gcenter();
    EXPECT_EQ(center.x, 2.0);
    EXPECT_EQ(center.y, 1.0);
}

TEST(TriangleTest, InputOutput) {
    Triangle<double> tr;
    std::stringstream input("0 0 4 0 2 3");
    
    EXPECT_NO_THROW(input >> tr);
    EXPECT_DOUBLE_EQ(tr.area(), 6.0);
}