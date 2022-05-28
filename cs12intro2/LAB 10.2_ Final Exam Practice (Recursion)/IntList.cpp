#include "IntList.h"

void IntList::distanceFrom(int key) {
   if (head == nullptr) {
      return;
   }
   if (head->data == key) {
      return;
   }
   head->data = searchAndModify(head, key);
}

int IntList::searchAndModify(IntNode *curr, int key) {
   if (curr == nullptr || key == curr->data) {
      return 0;
   }
   if (curr != nullptr && key != curr->data) {
      curr->data = 1 + searchAndModify(curr->next, key);
      return curr->data;
   }

   return 0;
}

