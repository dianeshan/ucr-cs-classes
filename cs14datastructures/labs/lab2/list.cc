// CS14
// This file contains all of the functions for the list class
 /**
 * Course: CS014 Summer 2018
 *
 * First Name: Diane
 * Last Name: Shan
 * Username: dshan017
 * email address: dshan017@ucr.edu
 *
 *
 * Assignment: lab2
 * Filename : list.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "list.h"
#include <cstdlib>
#include <iostream>

using namespace std;

List::List ( ) {

  head = NULL;

}

//------------------------------------------------------------------------

List::~List ( ) {

  // ADD: to avoid memory leaks, make sure you delete all allocated memory
  Node* next;
  for ( Node* temp = head; temp != NULL; temp = next ) {
    next = temp->next;
    delete temp;
  }

}

List::List(const List &rhs){
  for(Node* temp = rhs.head; temp != nullptr; temp = temp->next){
    push_back(temp->value);
  }
}

//------------------------------------------------------------------------

int 
List::size ( ) {
  int size = 0;
  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    size ++;
  }
  return size;
}

//------------------------------------------------------------------------

void 
List::push_front ( int value ) {

  Node* insert = new Node;
  insert->value = value;
  insert->next = head;
  head = insert;

}

//------------------------------------------------------------------------

void
List::push_back ( int value ) {

  if ( size ( ) == 0 ) {
    push_front ( value );
  }
  else {
    Node* tail;
    for ( tail = head; tail->next != NULL; tail = tail->next );
    Node* insert = new Node;
    insert->value = value;
    insert->next = NULL;
    tail->next = insert;
  }

}

//------------------------------------------------------------------------

void 
List::print ( ) {

  if ( size ( ) == 0 ) {
    cout << "No elements in the array" << endl;
    return;
  }

  for ( Node* temp = head; temp != NULL; temp = temp->next ) {
    cout << temp->value << " ";
  }
  cout << endl;
}

List &List::operator=(const List &rhs) {
   if (rhs.head != nullptr) //rhs is not empty
    {
        if (this == &rhs) //if this and rhs are equal to each other then do nothing
        {
        }
        else
        {
             while (head != nullptr) //while list is not empty, go through and delete everything; once list is empty, go to for loop
            {
                Node *temp = head->next; 
                delete head;
                head = temp;
            }
            for (Node *temp = rhs.head; temp != nullptr; temp = temp->next) //run through the rhs list and push_back the value of rhs into *this
            {
                push_back(temp->value); //push_bacl value of rhs to this
            }
        }
    }
    else
    {
        head = nullptr;
    }
    return *this;
}
