#include "IntList.h"

#include <ostream>

using namespace std;

IntList::IntList() : head(0) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

ostream & operator<<(ostream &o, const IntList &list) {
   if (list.head == nullptr) {
      return o;
   }
   else {
      IntNode *temp = list.head;
      o << temp->data;
      if (temp->next != nullptr) {
         o << " ";
      }
      operator<<(o, temp->next);
   }

   return o;
}

ostream & operator<<(ostream &o, IntNode *temp) {
   if (temp == nullptr) {
      return o;
   } 
   else {
      o << temp->data;
      if (temp->next != nullptr) {
         o << " ";
      }
      operator<<(o, temp->next);
   }
   
   return o;
}

bool IntList::exists(int n) const { //WORKS
   if (head == nullptr) {
      return false;
   }
   if (head->data == n) {
      return true;
   }
   else {
      IntNode *temp = head;
      return exists(temp->next, n);
   }
}

bool IntList::exists(IntNode *temp, int n) const { //WORKS
   if (temp == nullptr) {
      return false;
   }
   if (temp->next == nullptr && temp->data != n) {
      return false;
   }
   if (temp->data == n) {
      return true;
   }
   else {
      return exists(temp->next, n);
   }
}
