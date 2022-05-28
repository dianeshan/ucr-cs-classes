#include "IntList.h"

void IntList::removeOdds() {
    if (head == nullptr) {
        return;
    }
    IntNode *i = head;
    IntNode *prev = i;
    IntNode *curr = i->next;
    IntNode *temp;
    while (prev != nullptr && curr != nullptr) {
        if (curr->data % 2 != 0) {
            temp = curr;
            prev->next = temp->next;
            delete temp;
            curr = prev->next;
        }
        else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    if (head->data % 2 != 0) {
        head = head->next;
    }
}