#include <gtest/gtest.h>
#include <iostream>
#include <string.h>

std::string fizzBuzz(int num)
{
    if (num % 3 == 0 && num % 5 == 0) return "FizzBuzz";
    if (num % 3 == 0) return "Fizz";
    if (num % 5 == 0) return "Buzz";
    std::stringstream ss;
    ss << num;
    return ss.str();
}

TEST(TestFizzBuzz, ReturnsFizz) {
    EXPECT_EQ(fizzBuzz(3), "Fizz");
}
TEST(TestFizzBuzz, ReturnsBuzz) {
    EXPECT_EQ(fizzBuzz(5), "Buzz");
}
TEST(TestFizzBuzz, ReturnsFizzBuzz) {
    EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
}
TEST(TestFizzBuzz, FizzBuzzLoop) {
    EXPECT_EQ(fizzBuzz(1), "1");
    EXPECT_EQ(fizzBuzz(2), "2");
    EXPECT_EQ(fizzBuzz(3), "Fizz");
    EXPECT_EQ(fizzBuzz(4), "4");
    EXPECT_EQ(fizzBuzz(5), "Buzz");
    EXPECT_EQ(fizzBuzz(6), "Fizz");
    EXPECT_EQ(fizzBuzz(7), "7");
    EXPECT_EQ(fizzBuzz(8), "8");
}

GTEST_API_ int main(int argc, char **argv) {
      std::cout << "Running main() from testmain.cc\n";
       
        testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
