#include <gtest/gtest.h>
#include "../include/rectangle.h"

TEST(RectangleTest, DefaultConstructor) {
    Rectangle<double> rec;
    EXPECT_NO_THROW(rec.area());
    EXPECT_NO_THROW(rec.gcenter());
}

TEST(RectangleTest, ValidRectangleCreation) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    EXPECT_NO_THROW(Rectangle<double> rec(points));
}

TEST(RectangleTest, InvalidRectangleCreation) {
    std::vector<Point<double>> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    EXPECT_THROW(Rectangle<double> rec(points), std::invalid_argument);
}

TEST(RectangleTest, Area) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    Rectangle<double> rec(points);
    EXPECT_DOUBLE_EQ(rec.area(), 8.0);
}

TEST(RectangleTest, GeometricCenter) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    Rectangle<double> rec(points);
    Point<double> center = rec.gcenter();
    EXPECT_EQ(center.x, 2.0);
    EXPECT_EQ(center.y, 1.0);
}

TEST(RectangleTest, CopyConstructor) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    Rectangle<double> rec1(points);
    Rectangle<double> rec2(rec1);
    
    EXPECT_DOUBLE_EQ(rec1.area(), rec2.area());
    EXPECT_EQ(rec1.gcenter().x, rec2.gcenter().x);
    EXPECT_EQ(rec1.gcenter().y, rec2.gcenter().y);
}

TEST(RectangleTest, MoveConstructor) {
    std::vector<Point<double>> points = {{0, 0}, {4, 0}, {4, 2}, {0, 2}};
    Rectangle<double> rec1(points);
    Rectangle<double> rec2(std::move(rec1));
    
    EXPECT_DOUBLE_EQ(rec2.area(), 8.0);
}

TEST(RectangleTest, InputOutput) {
    Rectangle<double> rec;
    std::stringstream input("0 0 4 0 4 2 0 2");
    
    EXPECT_NO_THROW(input >> rec);
    EXPECT_DOUBLE_EQ(rec.area(), 8.0);
}