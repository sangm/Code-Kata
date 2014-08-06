#include "SingleLL.h"

SingleLL::SingleLL() : head(nullptr), tail(nullptr) {}
SingleLL::~SingleLL() {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

bool SingleLL::empty() {
    return head == nullptr;
}

