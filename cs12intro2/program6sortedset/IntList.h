#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include <algorithm>
using namespace std;

struct IntNode {
	int data;
	IntNode *next;
	IntNode(int data) : data(data), next(nullptr) { }
};

class IntList {
 protected:
	IntNode *head;
	IntNode *tail;
 public:
	IntList();
	~IntList();
	IntList(const IntList &);
	IntList & operator=(const IntList &);
	void push_front(int);
	void push_back(int);
	void pop_front();
	void clear();
	void selection_sort();
	void insert_ordered(int);
	void remove_duplicates();
	bool empty() const;
	const int & front() const;
	const int & back() const;
	friend ostream & operator<<(ostream &, const IntList &);
};

#endif

