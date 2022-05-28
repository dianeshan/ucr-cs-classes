#include "IntList.h"
#include <iostream>

// void IntList::removeLargest() {
//    int largest;
//    int large;
//    if (head == nullptr) {
//       return;
//    }
//    if (head->next == nullptr) {
//       head = nullptr;
//       return;
//    }
//    else {
//       largest = -1;
//       largest = removeIfLargest(head, largest);
//       large = removeIfLargest(head, largest);
//    }
// }

// int IntList::removeIfLargest(IntNode *curr, int leftLargestInt) {
//    int found;
//    int nextfound;
//    int removing;
//    if (leftLargestInt == -1) {//finding the largest number
//       if (curr) {
//          found = curr->data;
//          nextfound = removeIfLargest(curr->next, leftLargestInt);
//          if (found > nextfound){
//             return found;
//          }
//          return nextfound;
//       }
//    }
//    else {
//       if (curr->data == leftLargestInt) {
//          if (curr == head) {
//             head = curr->next;
//             return head->data;
//          }
//          else if (curr->next == nullptr) {
//             return -100;//indicating that we are removing the tail value so set next pointers carefully
//          }
//          else {
//             return -200;//indicating that we are removing an internal node value so set next pointers carefully
//          }
//       }
//       removing = removeIfLargest(curr->next, leftLargestInt);
//       if (removing == -100) {
//          curr->next = nullptr;
//       }
//       else if (removing == -200) {
//          curr->next = curr->next->next;
//       }  
//    }

//    return 0;
// }

void IntList::removeLargest() {
    if (head) {
      // if (head->next == nullptr) {
      //    head = nullptr;
      // }
      
         removeIfLargest(head, head->data);
   }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int IntList::removeIfLargest(IntNode *curr, int leftLargestInt) {
    if (curr == nullptr) {
        return leftLargestInt;
    }
    int rightLargestInt = removeIfLargest(curr->next, max(curr->next->data, leftLargestInt));
    if (rightLargestInt > leftLargestInt) {
        if (curr->next->data == rightLargestInt) {
            IntNode *tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        }
        return rightLargestInt;
    }
    
    if (curr == head) {
        IntNode *tmp = curr;
        head = head->next;
        delete tmp;
    }
    return leftLargestInt;
}
