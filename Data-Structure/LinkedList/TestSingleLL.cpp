#include <gtest/gtest.h>
#include "SingleLL.h"

class TestSingleLL : public ::testing::Test {
protected:
    SingleLL ll;
};

TEST_F(TestSingleLL, HeadAndTailGetsInitializedToNull) { 
    EXPECT_EQ(NULL, ll.head);
    EXPECT_EQ(NULL, ll.tail);
}
TEST_F(TestSingleLL, DestructorDoesNotLeakMemory) {
    SingleLL *l = new SingleLL;
    SingleLL::Node *head = l->head;
    delete l;
    EXPECT_EQ(NULL, ll.head);
}

GTEST_API_ int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
