#include <gtest/gtest.h>
#include "../include/rectangle.h"

TEST(RectangleTest, DefaultConstructor) {
    Rectangle<int> rec;
    EXPECT_NO_THROW(rec.area());
    EXPECT_NO_THROW(rec.gcenter());
}

TEST(RectangleTest, ValidRectangleCreation) {
    std::vector<Point<int>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    EXPECT_NO_THROW(Rectangle<int> rec(points));
}

TEST(RectangleTest, InvalidRectangleCreation) {
    std::vector<Point<int>> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    EXPECT_THROW(Rectangle<int> rec(points), std::invalid_argument);
}

TEST(RectangleTest, Area) {
    std::vector<Point<int>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    Rectangle<int> rec(points);
    EXPECT_DOUBLE_EQ(rec.area(), 8.0);
}

TEST(RectangleTest, GeometricCenter) {
    std::vector<Point<int>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    Rectangle<int> rec(points);
    Point<int> center = rec.gcenter();
    EXPECT_EQ(center, Point<int>(2, 1));
}
