#ifndef __INTLIST_H__
#define __INTLIST_H__

#include <ostream>

using namespace std;

struct IntNode {
    int data;
    IntNode *next;
    IntNode(int data) : data(data), next(nullptr) {}
};


class IntList {

 private:
   IntNode *head;

 public:

   /* Initializes an empty list.
   */
   IntList() : head(nullptr) {}

   /* Inserts a data value to the front of the list.
   */
   void push_front(int val) {
      if (!head) {
         head = new IntNode(val);
      } else {
         IntNode *temp = new IntNode(val);
         temp->next = head;
         head = temp;
      }  
   }
   
   /* Outputs to a single line all of the int values stored in the list, each separated by a space. 
      This function does NOT output a newline or space at the end.
   */
   friend ostream & operator<<(ostream &out, const IntList &rhs) {
      if (rhs.head) {
         IntNode *curr = rhs.head;
         out << curr->data;
         for (curr = curr->next ; curr ; curr = curr->next) {
            out << ' ' << curr->data;
         }
      }
      return out;
   }
   
   
   /* Removes the 1st instance of the largest integer from the list,
      keeping all other integers in the same relative order.
   */
   void removeLargest();

 private:


   /* Recursive helper function that passes in a node (actually the address of a node)
      and the largest integer that exists from the head to curr (inclusive).
      This function should remove the node after curr if that node contains the first instance
      of the largest integer within the entire list.
      This function returns the largest integer that exists (or existed if removed) after the curr node.
   */
  //2  8  14 12 5  6  9  3  14  og
  //2  8  14 14 14 14 14 14 14  left
  //14 14 14 14 14 14 14 14     right

  //9 2 5
   int removeIfLargest(IntNode *curr, int leftLargestInt);
   //    if (curr == nullptr) {
   //       return leftLargestInt;
   //    }
   //    int largest;

   //    if (leftLargestInt < curr->data) {
   //       largest = curr->data;
   //    }
   //    else {
   //       largest = leftLargestInt;
   //    }
      
   //    int rightLargestInt = removeIfLargest(curr->next, largest);
   //    // if (curr->next == rightLargestInt) {
   //    //    IntNode *temp = curr->next;
   //    //    curr->next = temp->next;
   //    //    delete temp;
   //    // }
      
   //    if (leftLargestInt == rightLargestInt) {
   //       IntNode *temp = curr->next;
   //       curr->next = temp->next;
   //       delete temp;
   //       return rightLargestInt;
   //    }
   // }
};



#endif