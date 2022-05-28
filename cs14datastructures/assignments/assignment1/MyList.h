#include "Node.h"
#include <iostream>

using namespace std;

#ifndef MYLIST_H_
#define MYLIST_H_

class MyList
{
private:
  Node *head;

public:
  MyList();                  //done
  MyList(const MyList &str); //done
  MyList(const string &str); //done
  MyList(const char *str);   //done
  ~MyList();                 //done

  /* Mutators */
  void push_front(char value);           //done
  void push_back(char value);            //done
  void pop_front();                      //done
  void pop_back();                       //done
  void swap(int i, int j);               //done
  void insert_at_pos(int i, char value); //done
  void reverse();                        //done

  /* Accessors */
  int size() const;                  //done
  void print() const;                //done
  int find(char value) const;        //done
  int find(MyList &query_str) const; //done

  /* Operator overloaders */
  MyList &operator=(const MyList &str); //done
  char &operator[](const int i);        //done
  MyList operator+(const MyList &str);  //done

  /* Challenge functions */
  bool is_palindrome() const; //done
  void merge_list(MyList A, MyList B);
  bool remove_char(char c); //done
  /* provide access to first node's value */
  char front() const; //done
};

#endif
