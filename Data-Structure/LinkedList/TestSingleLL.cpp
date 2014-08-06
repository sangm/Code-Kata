#include <gtest/gtest.h>
#include "SingleLL.h"

class TestSingleLL : public ::testing::Test {
protected:
    SingleLL ll;
    SingleLL::Node *head;

    virtual void SetUp() {
        head = ll.head;
    }
};

TEST_F(TestSingleLL, Head_And_Tail_Gets_Initialized_To_Null) { 
    EXPECT_EQ(NULL, ll.head);
    EXPECT_EQ(NULL, ll.tail);
}
TEST_F(TestSingleLL, Destructor_Does_Not_Leak_Memory) {
    SingleLL *l = new SingleLL;
    head = l->head;
    delete l;
    EXPECT_EQ(NULL, head);
}
TEST_F(TestSingleLL, ListShouldBeEmptyWhenInitialized) {
    EXPECT_TRUE(ll.empty());
}
TEST_F(TestSingleLL, Adds_To_Head_Properly) {
    ll.addToHead(2);
    ll.addToHead(1);
    EXPECT_EQ(2, head->data);
    EXPECT_EQ(1, head->next->data);

}

GTEST_API_ int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
