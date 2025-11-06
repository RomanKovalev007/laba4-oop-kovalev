#include <gtest/gtest.h>
#include "../include/point.h"

TEST(PointTest, Constructor) {
    Point<double> p(3.6, 2.2);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ(ss.str(), "(3.6, 2.2) ");
}

TEST(PointTest, DistanceCalc) {
    Point<int> p1(0, 0);
    Point<int> p2(3, 4);
    EXPECT_DOUBLE_EQ(distance(p1, p2), 5.0);
}

TEST(PointTest, InputOutput) {
    Point<int> p;
    std::stringstream input("10 20");
    std::stringstream output;
    
    input >> p;
    output << p;
    
    EXPECT_EQ(output.str(), "(10, 20) ");
}

TEST(PointTest, ScalarConcept) {
    EXPECT_TRUE(Scalar<int>);
    EXPECT_TRUE(Scalar<double>);
    EXPECT_TRUE(Scalar<float>);
}