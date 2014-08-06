#ifndef __SINGLELL_H__
#define __SINGLELL_H__

#include <gtest/gtest_prod.h>
#include <iostream>


class SingleLL {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node *n = nullptr) {
            data = d;
            next = n;
        };
    };

    Node *head, *tail;
    void print();

    friend class TestSingleLL;
    FRIEND_TEST(TestSingleLL, Head_And_Tail_Gets_Initialized_To_Null);
    FRIEND_TEST(TestSingleLL, Destructor_Does_Not_Leak_Memory);
public:
    SingleLL();
    ~SingleLL();

    bool empty();
};

#endif
