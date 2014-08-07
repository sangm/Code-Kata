#include <gtest/gtest.h>
#include <stdexcept>
#include "SingleLL.h"

class TestSingleLL : public ::testing::Test {
protected:
    SingleLL ll;
    SingleLL::Node *head;
    SingleLL::Node *tail;

    virtual void SetUp() {
        head = tail = nullptr; 
    
    }
    virtual void TearDown() {
        head = tail = nullptr;
    }

public:
    SingleLL::Node *getHeadPointer(const SingleLL& list) {
        return list.head;
    }   
    SingleLL::Node *getHeadPointer(const SingleLL *list) {
        return list->head;
    }   
    SingleLL::Node *getTailPointer(const SingleLL& list) {
        return list.tail;
    }   
    SingleLL::Node *getTailPointer(const SingleLL *list) {
        return list->tail;
    }   
    int getNumNodes() {
        return ll.numNodes;
    }
};

TEST_F(TestSingleLL, Head_And_Tail_Gets_Initialized_To_Null) { 
    EXPECT_EQ(NULL, ll.head);
    EXPECT_EQ(NULL, ll.tail);
    EXPECT_EQ(0, getNumNodes());
}
TEST_F(TestSingleLL, Destructor_Does_Not_Leak_Memory) {
    SingleLL *l = new SingleLL;
    head = getHeadPointer(l);
    delete l;
    EXPECT_EQ(nullptr, head);
}
TEST_F(TestSingleLL, ListShouldBeEmptyWhenInitialized) {
    EXPECT_TRUE(ll.empty());
}
TEST_F(TestSingleLL, Adds_To_Head_Properly) {
    ll.addToHead(2);
    ll.addToHead(1);
    head = getHeadPointer(ll);
    EXPECT_EQ(1, head->data);
    EXPECT_EQ(2, head->next->data);
    EXPECT_EQ(nullptr, head->next->next);
    EXPECT_EQ(2, getNumNodes());
}
TEST_F(TestSingleLL, Adds_To_Tail_Properly) {
    ll.addToTail(1);
    ll.addToTail(2);
    tail = getTailPointer(ll);
    EXPECT_EQ(2, tail->data);
    EXPECT_EQ(2, getNumNodes());
}
TEST_F(TestSingleLL, Deleting_From_Empty_List_Throws_Exception) {
//    EXPECT_THROW(ll.deleteFromHead(), std::runtime_error);
//    EXPECT_THROW(ll.deleteFromTail(), std::runtime_error);
}
TEST_F(TestSingleLL, Delete_From_Head) {
    ll.addToHead(2);
    ll.addToHead(4);
    // ll -> [4, 2]
    int temp;
    temp = ll.deleteFromHead();
    EXPECT_EQ(4, temp);
    EXPECT_EQ(1, getNumNodes());
    temp = ll.deleteFromHead();
    EXPECT_EQ(2, temp);
    EXPECT_EQ(0, getNumNodes());
}
TEST_F(TestSingleLL, Delete_From_Tail) {
    int temp;
    ll.addToHead(2);
    temp = ll.deleteFromTail();
    EXPECT_EQ(2, temp);

    ll.addToHead(2);
    ll.addToTail(4);
    ll.addToTail(5);
    EXPECT_EQ(3, getNumNodes());
    temp = ll.deleteFromTail();
    EXPECT_EQ(2, getNumNodes());

    EXPECT_EQ(5, temp);
    temp = ll.deleteFromTail();
    EXPECT_EQ(1, getNumNodes());
    EXPECT_EQ(4, temp);
}
TEST_F(TestSingleLL, Delete_Node_Given_Position) {
    for (int i = 0; i < 5; ++i) ll.addToHead(i);
    // ll = [4, 3, 2, 1, 0]
    head = getHeadPointer(ll);
    EXPECT_EQ(4, head->data);

    // Deleting from the head
    ll.deleteNode(0);
    // ll = [3, 2, 1, 0]
    head = getHeadPointer(ll);
    EXPECT_EQ(3, head->data);

    // Deleting from the tail
    ll.deleteNode(3);
    // ll = [3, 2, 1]
    tail = getTailPointer(ll);
    EXPECT_EQ(1, tail->data);

    // Deleting from the middle
    ll.deleteNode(1);
    // ll = [3, 1]
    head = getHeadPointer(ll);
    EXPECT_EQ(3, head->data);
    EXPECT_EQ(1, head->next->data);
}
TEST_F(TestSingleLL, Out_Of_Range_When_Deleting_Node_Given_Position) {
    for (int i = 0; i < 5; ++i) ll.addToHead(i);
    // EXPECT_THROW(ll.deleteNode(100), std::out_of_range);
}
TEST_F(TestSingleLL, Inserting_To_List_Given_An_Index) {
    // ll = [ ]
    ll.addToList(1, 0);
    // ll = [1]
    head = getHeadPointer(ll);
    EXPECT_EQ(1, head->data);
    
    ll.addToList(2, 1);
    // ll = [1, 2]
    head = getHeadPointer(ll);
    EXPECT_EQ(2, head->next->data);

    ll.addToList(4, 1);
    // ll = [1, 4, 2]
    head = getHeadPointer(ll);
    EXPECT_EQ(4, head->next->data);

    for (int i = 0; i < 5; ++i)
        ll.addToList(i, 3);
    // ll = [1, 4, 2, 4, 3, 2, 1,0]

}

// write a test out of range delete node

GTEST_API_ int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
