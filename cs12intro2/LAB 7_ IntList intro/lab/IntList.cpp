#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    this->head = nullptr; //sets head to nullptr
    this->tail = nullptr; //sets tail to nullptr
}

IntList::~IntList() {
    // cout << "Destructor called" << endl;
    while (head) {
      IntNode *next = head->next;
      delete head;
      head = next;
   }
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val); //allocates a node on the heap & returns the address, need a temp variable to store 
    temp->next = this->head; //temp->next gives us address of next pointer, addresses the location, puts address of what head is storing into temp->next
    head = temp;
    if (tail == nullptr) {
        tail = head;
    }
}

void IntList::pop_front() {
    if (empty()) {
    }
    else {
        IntNode *next = head->next;
        delete head;
        head = next;
    }
}

bool IntList::empty() const {
    if (head == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

const int & IntList::front() const {
    return head->data;
}

const int & IntList::back() const {
    return tail->data;
}

ostream & operator<<(ostream &o, const IntList &list1) {
    IntNode *temp = list1.head;
    while (temp != nullptr) {
        o << temp->data;
        temp = temp->next;
        if (temp != nullptr) {
            o << " ";
        }
    }

    return o;
}