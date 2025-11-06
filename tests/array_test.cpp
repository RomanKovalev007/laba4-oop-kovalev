#include <gtest/gtest.h>
#include "../include/rectangle.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/array.h"

TEST(ArrayTest, DefaultConstructor) {
    Array<int> arr;
    EXPECT_EQ(arr.getSize(), 0);
    EXPECT_EQ(arr.getCapacity(), 0);
    EXPECT_TRUE(arr.isEmpty());
}

TEST(ArrayTest, Push) {
    Array<int> arr;
    arr.push(11);
    arr.push(22);
    arr.push(33);
    
    EXPECT_EQ(arr.getSize(), 3);
    EXPECT_EQ(arr[0], 11);
    EXPECT_EQ(arr[1], 22);
    EXPECT_EQ(arr[2], 33);
}

TEST(ArrayTest, PushWihtMove) {
    Array<std::string> arr;
    std::string str = "test";
    arr.push(std::move(str));

    EXPECT_EQ(arr.getSize(), 1);
    EXPECT_EQ(arr[0], "test");
    EXPECT_TRUE(str.empty());
}



TEST(ArrayTest, RemoveElement) {
    Array<int> arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);

    arr.remove(1);

    EXPECT_EQ(arr.getSize(), 2);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
}

TEST(ArrayTest, CopyConstructor) {
    Array<int> arr1;
    arr1.push(1);
    arr1.push(2);

    Array<int> arr2(arr1);

    EXPECT_EQ(arr2.getSize(), arr1.getSize());
    EXPECT_EQ(arr2[0], arr1[0]);
    EXPECT_EQ(arr2[1], arr1[1]);

}

TEST(ArrayTest, MoveConstructor) {
    Array<int> arr1;
    arr1.push(1);
    arr1.push(2);

    Array<int> arr2(std::move(arr1));

    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr1.getSize(), 0);

}

TEST(ArrayTest, CopyOperator) {
    Array<int> arr1;
    arr1.push(1);
    arr1.push(2);

    Array<int> arr2;
    arr2 = arr1;

    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
}

TEST(ArrayTest, MoveOperator) {
    Array<int> arr1;
    arr1.push(1);
    arr1.push(2);

    Array<int> arr2;
    arr2 = std::move(arr1);

    EXPECT_EQ(arr2.getSize(), 2);
    EXPECT_EQ(arr2[0], 1);
    EXPECT_EQ(arr2[1], 2);
    EXPECT_EQ(arr1.getSize(), 0);
}

TEST(ArrayTest, TotalArea) {
    Array<std::shared_ptr<Figure<int>>> arr;
    std::vector<Point<int>> trianglePoints = {{0, 0}, {4, 0}, {2, 3}};
    std::vector<Point<int>> squarePoints = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    arr.push(std::make_shared<Triangle<int>>(trianglePoints));
    arr.push(std::make_shared<Square<int>>(squarePoints));

    double totalArea = arr.totalArea();
    EXPECT_DOUBLE_EQ(totalArea, 10.0);
}