#include <gtest/gtest.h>
#include "../include/square.h"

TEST(SquareTest, DefaultConstructor) {
    Square<double> sq;
    EXPECT_NO_THROW(sq.area());
    EXPECT_NO_THROW(sq.gcenter());
}

TEST(SquareTest, ValidSquareCreation) {
    std::vector<Point<double>> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    EXPECT_NO_THROW(Square<double> sq(points));
}

TEST(SquareTest, InvalidSquareCreation) {
    std::vector<Point<double>> points = {{0, 0}, {3, 0}, {3, 2}, {0, 2}};
    EXPECT_THROW(Square<double> sq(points), std::invalid_argument);
}

TEST(SquareTest, Area) {
    std::vector<Point<double>> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<double> sq(points);
    EXPECT_DOUBLE_EQ(sq.area(), 4.0);
}

TEST(SquareTest, GeometricCenter) {
    std::vector<Point<double>> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<double> sq(points);
    Point<double> center = sq.gcenter();
    EXPECT_EQ(center.x, 1.0);
    EXPECT_EQ(center.y, 1.0);
}

TEST(SquareTest, CopyConstructor) {
    std::vector<Point<double>> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<double> sq1(points);
    Square<double> sq2(sq1);
    
    EXPECT_DOUBLE_EQ(sq1.area(), sq2.area());
}

TEST(SquareTest, InputOutput) {
    Square<double> sq;
    std::stringstream input("0 0 2 0 2 2 0 2");
    
    EXPECT_NO_THROW(input >> sq);
    EXPECT_DOUBLE_EQ(sq.area(), 4.0);
}