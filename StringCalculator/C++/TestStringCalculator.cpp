#include <gtest/gtest.h>
#include "StringCalculator.h"

class TestStringCalculator : public ::testing::Test {
protected:

    StringCalculator stringCalc;
};

TEST_F(TestStringCalculator, EmptyStringReturnsZero) {
    EXPECT_EQ(stringCalc.add(""), 0);
}
TEST_F(TestStringCalculator, OneStringReturnsInt) {
    EXPECT_EQ(stringCalc.add("1"), 1);
    EXPECT_EQ(stringCalc.add("2"), 2);
    EXPECT_EQ(stringCalc.add("3"), 3);
    EXPECT_EQ(stringCalc.add("4"), 4);
}
TEST_F(TestStringCalculator, TwoStringsReturnsInt) {
    EXPECT_EQ(stringCalc.add("1,2"), 3);
    EXPECT_EQ(stringCalc.add("2,2"), 4);
    EXPECT_EQ(stringCalc.add("5,2"), 7);
    EXPECT_EQ(stringCalc.add("1,3"), 4);
}
TEST_F(TestStringCalculator, UnknownAmountStringsReturnsInt) {
    EXPECT_EQ(stringCalc.add("1,2,3,4,5,6,7"), 28);
    EXPECT_EQ(stringCalc.add("10,10,10,10"), 40);
}
TEST_F(TestStringCalculator, HandleNewLineCharacter) {
    EXPECT_EQ(stringCalc.add("1\\n2\\n3,4"), 10);
}
