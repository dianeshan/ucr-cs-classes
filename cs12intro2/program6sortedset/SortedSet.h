#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <iostream>
using namespace std;

#include "IntList.h"

class SortedSet : public IntList {
    public:
        SortedSet(); //default, initiliaze empty list
        SortedSet(const SortedSet &); //copy constructor
        SortedSet(const IntList &); 
        ~SortedSet(); //destructor
        bool in(int data);
        SortedSet operator|(SortedSet &);
        SortedSet operator&(SortedSet &);
        void add(int data);
        void push_front(int data);
        void push_back(int data);
        void insert_ordered(int data);
        SortedSet operator|=(SortedSet &);
        SortedSet operator&=(SortedSet &);
};

#endif 