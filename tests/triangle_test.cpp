#include <gtest/gtest.h>
#include "../include/triangle.h"

TEST(TriangleTest, DefaultConstructor) {
    Triangle<int> tr;
    EXPECT_NO_THROW(tr.area());
}

TEST(TriangleTest, ValidTriangleCreation) {
    std::vector<Point<int>> points = {{0, 4}, {4, 0}, {0, 0}};
    EXPECT_NO_THROW(Triangle<int> tr(points));
}

TEST(TriangleTest, InvalidTriangleCreation) {
    std::vector<Point<int>> points = {{0, 0}, {1, 0}, {2, 0}};
    EXPECT_THROW(Triangle<int> tr(points), std::invalid_argument);
}


TEST(TriangleTest, CopyConstructor) {
    std::vector<Point<int>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<int> tr1(points);
    Triangle<int> tr2(tr1);
    
    EXPECT_TRUE(tr1 == tr2);
}

TEST(TriangleTest, MoveConstructor) {
    std::vector<Point<int>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<int> tr1(points);
    Triangle<int> tr2(std::move(tr1));
    
    EXPECT_DOUBLE_EQ(tr2.area(), 6.0);
}

TEST(TriangleTest, CopyOperator) {
    std::vector<Point<int>> points1 = {{0, 0}, {4, 0}, {2, 3}};
    std::vector<Point<int>> points2 = {{0, 0}, {5, 0}, {2, 4}};
    
    Triangle<int> tr1(points1);
    Triangle<int> tr2(points2);
    
    tr2 = tr1;
    EXPECT_TRUE(tr1 == tr2);
}

TEST(TriangleTest, EqualityOperator) {
    std::vector<Point<int>> points = {{0, 0}, {2, 0}, {2, 2}};
    Triangle<int> square1(points);
    Triangle<int> square2(points);
    
    EXPECT_TRUE(square1 == square2);
}

TEST(TriangleTest, Area) {
    std::vector<Point<int>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<int> tr(points);
    EXPECT_DOUBLE_EQ(tr.area(), 6.0);
}

TEST(TriangleTest, GeometricCenter) {
    std::vector<Point<int>> points = {{0, 0}, {4, 0}, {2, 3}};
    Triangle<int> tr(points);
    Point<int> center = tr.gcenter();
    EXPECT_EQ(center, Point<int>(2, 1));
}