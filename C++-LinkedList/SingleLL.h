#ifndef __SINGLELL_H__
#define __SINGLELL_H__

#include <gtest/gtest_prod.h>
#include <iostream>
#include <stdexcept>



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
    int numNodes;

    friend class TestSingleLL;
    FRIEND_TEST(TestSingleLL, Head_And_Tail_Gets_Initialized_To_Null);
    FRIEND_TEST(TestSingleLL, Destructor_Does_Not_Leak_Memory);
public:
    SingleLL();
    ~SingleLL();

    void addToHead(int data);
    void addToTail(int data);

    void addToList(int data, int pos);

    int deleteFromHead();
    int deleteFromTail(); 

    void deleteNode(int pos);

    bool empty();
};

#endif
