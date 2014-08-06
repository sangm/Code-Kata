#ifndef __SINGLELL_H__
#define __SINGLELL_H__

#include <gtest/gtest_prod.h>
#include <iostream>


class SingleLL {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node *n = NULL) {
            data = d;
            next = n;
        };
    };

    Node *head, *tail;
    void print();

    FRIEND_TEST(TestSingleLL, HeadAndTailGetsInitializedToNull);
    FRIEND_TEST(TestSingleLL, DestructorDoesNotLeakMemory);
public:
    SingleLL();
    ~SingleLL();
};

#endif
