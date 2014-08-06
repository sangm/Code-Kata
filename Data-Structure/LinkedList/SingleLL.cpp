#include "SingleLL.h"

SingleLL::SingleLL() : head(0), tail(0) {}
SingleLL::~SingleLL() {
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
