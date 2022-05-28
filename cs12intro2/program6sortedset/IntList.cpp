#include <iostream>
#include <algorithm>
using namespace std;

#include "IntList.h"

//constructor
IntList::IntList() {
    this->head = nullptr; //sets head to nullptr
    this->tail = nullptr; //sets tail to nullptr
}

//destructor
IntList::~IntList() {
    // cout << "Destructor called" << endl;
    while (head) {
      IntNode *next = head->next;
      delete head;
      head = next;
   }
}

//copy constructor
IntList::IntList(const IntList &cpy) {
    head = nullptr;
    IntNode *temp = cpy.head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}

// copy assignment operator
IntList & IntList::operator=(const IntList &rhs) {
    if(!rhs.empty()) {
        if (this == &rhs) {
        }
        else {
            this->clear();
            for(IntNode *temp = rhs.head; temp != nullptr; temp = temp->next) {
                push_back(temp->data);
            }
        }
    }
    else {
        head = nullptr;
        tail = nullptr;
    }
    return *this;
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val); //allocates a node on the heap & returns the address, need a temp variable to store 
    temp->next = this->head; //temp->next gives us address of next pointer, addresses the location, puts address of what head is storing into temp->next
    head = temp;
    if (tail == nullptr) {
        tail = head;
    }
}

void IntList::push_back(int val) {
    IntNode *temp = new IntNode(val);
    if (head == nullptr) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
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
    // if (head != nullptr) {
    //     IntNode *temp = head;
    //     head = head->next;
    //     delete temp;
    //     if (head == nullptr) {
    //         tail = head;
    //     }
    // }
}

void IntList::clear() {
    while (head != nullptr) {
        IntNode *temp = head->next;
        delete head;
        head = temp;
    }
    head = nullptr;
    tail = nullptr;
}

void IntList::selection_sort() {
    if (head == nullptr) {
        return;
    }
    else {
        int temp;
        for (IntNode *i = head; i != tail; i = i->next) {
            IntNode *min = i;
            for (IntNode *j = i->next; j != nullptr; j = j->next) {
                if (j->data <= min->data) {
                    min = j;
                }
            }
            temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
}

void IntList::insert_ordered(int val) {
    IntNode *temp = new IntNode(val);
    if (head == nullptr) {
        push_back(temp->data);
    }
    else if (temp->data <= head->data) {
        push_front(temp->data);
    }
    else if (temp->data >= tail->data) {
        push_back(temp->data);
    }
    else {
        IntNode *i = head;
        IntNode *prev = i;
        IntNode *curr = i->next;
        while (temp->next != curr) {
            prev = i;
            curr = i->next;
            if (temp->data <= curr->data) {
                prev->next = temp;
                temp->next = curr;
            }
            else {
                i = i->next;
            }
        }
    }
}

void IntList::remove_duplicates() {
    IntNode *i = head;
    IntNode *j;
    IntNode *temp;
    while (i != nullptr && i->next != nullptr) { 
        j = i; 
        while (j->next != nullptr) { 
            if (i->data == j->next->data) { 
                temp = j->next; 
                if (temp == tail) {
                    tail = j;
                }
                j->next = j->next->next; 
                delete temp; 
            } 
            else {
                j = j->next; 
            }
        } 
        i = i->next; 
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
    if (head == nullptr) {
        exit(1);
    }
    else {
        return head->data;
    }
}

const int & IntList::back() const {
    if (head == nullptr) {
        exit(1);
    }
    else {
        return tail->data;
    }
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