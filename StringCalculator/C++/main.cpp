#include <gtest/gtest.h>
#include <iostream>

GTEST_API_ int main(int argc, char **argv) {
      std::cout << "Running main() from testmain.cc\n";

        testing::InitGoogleTest(&argc, argv);
          return RUN_ALL_TESTS();
}
