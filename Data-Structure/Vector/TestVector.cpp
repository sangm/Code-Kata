#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include "vector.h"

class TestVectorFixture : public ::testing::Test {
protected:
    
    Vector<int> vector;
};

TEST_F(TestVectorFixture, TestBackDoesNotChangeSize)
{
    vector.push_back(1);
    ASSERT_EQ(vector.size(), 1);
    EXPECT_EQ(vector.back(), 1);
    EXPECT_EQ(vector.size(), 1);
}
TEST_F(TestVectorFixture, TestPushBackIncrementsSize)
{
    vector.push_back(1);
    EXPECT_EQ(vector.size(), 1);
}
TEST(TestVector, TestResizeThrowsException)
{
    Vector<int> vector(10);
    vector.push_back(1);
    ASSERT_EQ(vector.capacity(), 10);
    EXPECT_LT(0, vector.size());
    EXPECT_THROW(vector.resize(0), std::range_error);
}
TEST(TestVector, TestVectorOverLoadedConstructor)
{
    Vector<int> vector(10);
    EXPECT_EQ(vector.size(), 0);
    EXPECT_EQ(vector.capacity(), 10);
}
TEST(TestVector, TestVectorConstructor) 
{
    Vector<int> vector;
    EXPECT_EQ(vector.size(), 0);
    EXPECT_EQ(vector.capacity(), 0);
}
TEST(TestVectorTemplate, TestVectorInt) 
{
    Vector<int> vector;
    vector.push_back(1);
    int n = vector.back();
    EXPECT_EQ(n, 1);
}
TEST(TestVectorTemplate, TestVectorString) 
{
    Vector<std::string> vector;
    vector.push_back("1");
    std::string n = vector.back();
    EXPECT_EQ(n, "1");
}
TEST(TestVectorTemplate, TestVectorFloat) 
{
    Vector<float> vector;
    vector.push_back(1.2);
    float n = vector.back();
    EXPECT_EQ(n, 1.2f);
}

GTEST_API_ int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
