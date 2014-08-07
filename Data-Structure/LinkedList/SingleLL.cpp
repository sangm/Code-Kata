#include "SingleLL.h"

SingleLL::SingleLL() : head(nullptr), tail(nullptr), numNodes(0) {}
SingleLL::~SingleLL() {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void SingleLL::addToHead(int data)
{
    head = new Node(data, head);
    if (tail == nullptr) 
        tail = head;
    ++numNodes;
}
void SingleLL::addToTail(int data)
{
    if (empty())
        head = tail = new Node(data);
    else {
        tail->next = new Node(data);
        tail = tail->next;
    }
    ++numNodes;
}
int SingleLL::deleteFromHead() {
    if (empty())
        throw std::runtime_error("Cannot delete from head. List is empty");
    Node *temp = head;
    int tempVal = temp->data;
    if (head == tail)
        head = tail = nullptr;
    else
        head = head->next;
    delete temp;
    --numNodes;
    return tempVal;
}
int SingleLL::deleteFromTail() {
    if (empty()) 
        throw std::runtime_error("Cannot delete from tail. List is empty");
    Node *temp;
    int tempVal = tail->data;
    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    }
    else {
        for (temp = head; temp->next != tail; temp = temp->next);
        delete tail;
        tail = temp;
        tail -> next = nullptr;
    }
    --numNodes;
    return tempVal;
}
void SingleLL::deleteNode(int pos) {
    
    if (empty()) 
        throw std::runtime_error("Cannot delete from list. List is empty");
    if (pos == 0)
        deleteFromHead();
    else if (numNodes - 1 == pos)
        deleteFromTail();
    else if (pos > numNodes - 1)
        throw std::out_of_range("Not enough nodes in the list");
    else {
        Node *prev;
        Node *curr;
        int i;
        for (i = 0, prev = nullptr, curr = head; i < pos; ++i, prev = curr, curr = curr->next);
        prev->next = curr->next;
        delete curr;
    }

}

bool SingleLL::empty() 
{
    return head == nullptr;
}

