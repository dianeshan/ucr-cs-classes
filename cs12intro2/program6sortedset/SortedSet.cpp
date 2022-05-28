#include <iostream>

using namespace std;

#include "SortedSet.h"

//constructor
SortedSet::SortedSet() : IntList() { }

//copy constructor
SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) { 
    this->selection_sort();
    this->remove_duplicates();
}

//constructor with intlist passed in
SortedSet::SortedSet(const IntList &cpy) : IntList(cpy) {
    this->remove_duplicates();
    this->selection_sort();
}

//destructor
SortedSet::~SortedSet() {
    // cout << "Destructor called";
    while (head) {
        IntNode *next = head->next;
        delete head;
        head = next;
   }
}

bool SortedSet::in(int data) {
    for (IntNode *i = head; i != nullptr; i = i->next) {
        if (i->data == data) {
            return true;
        }
    }

    return false;
}

SortedSet SortedSet::operator|(SortedSet &rhs) {
    SortedSet tog; //union of two sortedsets

    IntNode *i = head;
    IntNode *j = rhs.head;

    while (i != nullptr && j != nullptr) {
        if (i->data < j->data) {
            tog.push_back(i->data);
            i = i->next;
        }
        else if (i->data == j->data) {
            tog.push_back(i->data);
            i = i->next;
            j = j->next;
        }
        else {
            tog.push_back(j->data);
            j = j->next;
        }
    }

    // If this is not empty, add remaining elements
    while (i != nullptr) {
        tog.push_back(i->data);
        i = i->next;
    }

    // If right is not empty, add remaining elements
    while (j != nullptr) {
        tog.push_back(j->data);
        j = j->next;
    }

    return tog;
}

SortedSet SortedSet::operator&(SortedSet &rhs) {
    SortedSet inter;

    for (IntNode *i = head; i != nullptr; i = i->next) {
        for (IntNode *j = rhs.head; j != nullptr; j = j->next) {
            if (j->data == i->data) {
                inter.push_back(i->data);
            }
        }
    }

    // while (i != nullptr && j != nullptr) {
    //     if (i->data == j->data) {
    //         inter.push_back(i->data);
    //         i = i->next;
    //         j = j->next;
    //     }
    //     else {
    //         i = i->next;
    //         j = j->next;
    //     }
    // }

    return inter;
}

void SortedSet::add(int data) {
    IntNode *temp = new IntNode(data); 
    if (head == nullptr) {
        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    else if (temp->data == head->data || temp->data == tail->data) {
        return;
    }
    else if (temp->data < head->data) {
        temp->next = this->head; //temp->next gives us address of next pointer, addresses the location, puts address of what head is storing into temp->next
        head = temp;
        if (tail == nullptr) {
            tail = head;
        }
    }
    else if (temp->data > tail->data) {
        if (head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    else {
        IntNode *i = head;
        IntNode *prev = i;
        IntNode *curr = i->next;
        while (temp->next != curr) {
            prev = i;
            curr = i->next;
            if (temp->data < curr->data) {
                prev->next = temp;
                temp->next = curr;
            }
            else if (temp->data == curr->data) {
                return;
            }
            else {
                i = i->next;
            }
        }
    }
}

void SortedSet::push_front(int data) {
    add(data);
}

void SortedSet::push_back(int data) {
    add(data);
}

void SortedSet::insert_ordered(int data) {
    add(data);
}

SortedSet SortedSet::operator|=(SortedSet &rhs) {
    SortedSet tog;
    tog = *this | rhs;
    *this = tog;
    return tog;
}

SortedSet SortedSet::operator&=(SortedSet &rhs) {
    SortedSet tog;
    tog = *this & rhs;
    *this = tog;
    return tog;
}


