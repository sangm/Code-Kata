#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include "vector.h"

/*
 * Vector Functions Tests
 **/
class TestVectorFunction : public ::testing::Test {
protected: 
    Vector<int> vector;
};

TEST_F(TestVectorFunction, PopBackDecrementsSize)
{
    vector.push_back(10);
    vector.push_back(20);
    ASSERT_EQ(vector.back(), 20);
    vector.pop_back();
    EXPECT_EQ(vector.back(), 10);
}
TEST_F(TestVectorFunction, PopBackThrowsExceptionWhenVectorIsEmpty)
{
    EXPECT_THROW(vector.pop_back(), std::out_of_range);
}
TEST_F(TestVectorFunction, DataReturnsPointerAndCanModify)
{
    int *p = vector.data();
    *p = 0;
    *++p = 20;
    EXPECT_EQ(vector[0], 0);
    EXPECT_EQ(vector[1], 20);
}
TEST_F(TestVectorFunction, EmptyReturnsCorrectValue)
{
    EXPECT_TRUE(vector.empty());
    vector.push_back(1);
    EXPECT_FALSE(vector.empty());
}
TEST_F(TestVectorFunction, FrontReturnsFirstElement)
{
    vector.push_back(20);
    vector.push_back(40);
    vector.push_back(60);
    EXPECT_EQ(vector.front(), 20);
}
TEST_F(TestVectorFunction, BackReturnsLastElement)
{
    vector.push_back(20);
    vector.push_back(40);
    vector.push_back(60);
    EXPECT_EQ(vector.back(), 60);
}
TEST_F(TestVectorFunction, PushBackAddsAnElementAtEnd)
{
    for(int i = 0; i < 10; ++i)
        vector.push_back(i);
    EXPECT_EQ(vector[0], 0);
    EXPECT_EQ(vector[1], 1);
    EXPECT_EQ(vector[2], 2);
    EXPECT_EQ(vector[3], 3);
    EXPECT_EQ(vector[4], 4);
    EXPECT_EQ(vector[5], 5);
}
TEST_F(TestVectorFunction, PushBackIncrementsSize)
{
    ASSERT_EQ(vector.size(), 0);
    for(int i = 0; i < 10; ++i)
        vector.push_back(i);
    EXPECT_EQ(vector.size(), 10);
}
TEST_F(TestVectorFunction, ReserveIncreasesCapacityOnlyIfNGreaterThanCapacity)
{
    vector.reserve(10);
    EXPECT_EQ(vector.capacity(), 10);
    vector.reserve(1);
    EXPECT_EQ(vector.capacity(), 10);
}
/*
 * Constructor Tests
 **/
TEST(TestVectorConstructor, OverLoadConstructorSetsCapacity)
{
    Vector<int> vector(10); // Capacity should be 10
    EXPECT_EQ(vector.capacity(), 10);
    EXPECT_EQ(vector.size(), 0);
}
TEST(TestVectorConstructor, ConstructorSetsSizeCapacityToZero)
{
    Vector<int> vector;
    EXPECT_EQ(vector.size(), 0);
    EXPECT_EQ(vector.capacity(), 0);
}

GTEST_API_ int main(int argc, char *argv[]) 
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
