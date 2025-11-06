#include <gtest/gtest.h>
#include "../include/square.h"

TEST(SquareTest, DefaultConstructor) {
    Square<int> sq;
    EXPECT_NO_THROW(sq.area());
    EXPECT_NO_THROW(sq.gcenter());
}

TEST(SquareTest, ValidSquareCreation) {
    std::vector<Point<int>> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    EXPECT_NO_THROW(Square<int> sq(points));
}

TEST(SquareTest, InvalidSquareCreation) {
    std::vector<Point<int>> points = {{0, 0}, {3, 0}, {3, 2}, {0, 2}};
    EXPECT_THROW(Square<int> sq(points), std::invalid_argument);
}

TEST(SquareTest, Area) {
    std::vector<Point<int>> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<int> sq(points);
    EXPECT_DOUBLE_EQ(sq.area(), 4.0);
}

TEST(SquareTest, GeometricCenter) {
    std::vector<Point<int>> points = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    Square<int> sq(points);
    Point<int> center = sq.gcenter();
    EXPECT_EQ(center, Point<int>(1, 1));
}
