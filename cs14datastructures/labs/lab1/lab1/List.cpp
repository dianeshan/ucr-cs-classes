/**
 * UCR CS&E
 * CS014 Lab 1
 * List.cpp
 */
 /**
 * Course: CS014 Summer 2018
 *
 * First Name: Diane
 * Last Name: Shan
 * Username: dshan017
 * email address: dshan017@ucr.edu
 *
 *
 * Assignment: lab1
 * Filename : List.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}


// insert sorted value into list
void List::sorted_insert(int value) {
	
	if (head == nullptr) {
    	push_back(value);
	}
	else if (value <= this->head->get_value()) {
		push_front(value);
	}
	else if (value >= this->tail->get_value()) {
		push_back(value);
	}
	else {
		Node *temp = new Node(value);
		Node *i = head;
        Node *prev = this->head;
        Node *curr = this->head->get_next();
        while (temp->get_next() != curr) {
            prev = i;
            curr = i->get_next();
            if (temp->get_value() <= curr->get_value()) {
                prev->set_next(temp);
                temp->set_next(curr);
            }
            else {
                i = i->get_next();
            }
        }
	}
}

// prints contents of list backwards
void List::print_reverse() const {
	if (head == NULL) {
		cout << "List empty.\n";
		return;
	}
	Iterator x = end();
	x.set_curr_pos(get_tail());
	Iterator y = begin();
	y.set_curr_pos(NULL);
	for(Iterator temp = x; !temp.is_equal(y); temp.prev_pos()) {
		cout << temp.get_value() << ", ";
	}
	cout << endl;
}

// inserts new node with value at position i + 1 in list
void List::insert_after(int i, int value) {
	if (head == nullptr) {
		cout << "\nList is empty" << endl;
		return;
	}
	int size = 0;
	for (Node* j = head; j != nullptr; j = j->get_next()) {
		size = size + 1;
	}
	
	if (i < 0) {
		cout << "\nInvalid Position " << i << " inserting at beginning of list" << endl;
		push_front(value);
		return;
	}
	if (i > size - 1) {
		cout << "\nInvalid Position " << i << " inserting at end of list" << endl;
		push_back(value);
		return;
	}
	int counter = 0; //to go through and see when position = i
	Node* temp = new Node(value);
	for(Node* curr = head; curr != nullptr; curr = curr->get_next()) {
		if (counter == i) {
			temp->set_next(curr->get_next());
			curr->set_next(temp);
			return;
		}
		counter++;
	}
}

void List::insert_before(int i, int value) {
	if (head == nullptr) {
		cout << "\nList is empty" << endl;
		return;
	}
	int size = 0;
	for (Node* j = head; j != nullptr; j = j->get_next()) {
		size = size + 1;
	}
	
	if (i < 0) {
		cout << "\nInvalid Position " << i << " inserting at beginning of list" << endl;
		push_front(value);
		return;
	}
	if (i > size - 1) {
		cout << "\nInvalid Position " << i << " inserting at end of list" << endl;
		push_back(value);
		return;
	}
	if (i == 0 || i == 1) {
		push_front(value);
		return;
	}
	int counter = 2; //to go through and see when position = i
	Node* temp = new Node(value);
	Node* prev2 = head;
	Node* prev = prev2->get_next();
	for(Node* curr = prev->get_next(); curr != nullptr; curr = curr->get_next()) {
		if (counter == i) {
			prev2->set_next(temp);
			temp->set_next(prev);
			return;
		}
		prev2 = prev;
		prev = curr;
		counter++;
	}
}	

int List::count(int value) const {
	if (head == nullptr) {
		cout << "\nList is empty" << endl;
		return 0;
	}
	else {
		int counter = 0;
		for (Node* temp = head; temp != nullptr; temp = temp->get_next()) {
			if (temp->get_value() == value) {
				counter++;
			}
		}
		return counter;
	}
	
}


