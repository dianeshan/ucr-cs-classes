/**
 * UCR CS&E
 * CS014 Lab 1
 * main.cpp
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
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include "List.h"
#include "Iterator.h"
#include "Node.h"

#define fibo_number 11

int fibonacci(int n);

using namespace std;

int main()
{
	/* Instantiate two Lists */
	List myList;
	List myList2;
	List myList3;
	
	/* Try to print an empty List */
	cout << "\nTest printing an empty list:";
	myList.print();
	
	cout << "\nPushing back first " << fibo_number << " Fibonacci numbers:";
	for(int i = 0; i < fibo_number; i++)
	{
		myList.push_back(fibonacci(i));
		myList.print();
	}
	
	cout << "\nReverse myList pushing front contents of myList into myList2:";
	for(Iterator iter = myList.begin(); !iter.is_equal(myList.end()); iter.next_pos())
	{
		myList2.push_front(iter.get_value());
		myList2.print();
	}
	
	cout << "\nTesting sorted_insert";
	myList3.push_back(1);
	myList3.push_back(2);
	myList3.push_back(7);
	myList3.push_back(8);
	myList3.push_back(9);
	
	myList3.sorted_insert(6);
	myList3.print();
	
	cout << "\nReversing List\n";
	myList3.print_reverse();
	
	cout << "\nTesting insert_after";
	cout << "\nInsert 5 after position 2";
	myList3.insert_after(2, 5);
	myList3.print();
	cout << "\nInsert 5 after position -1";
	myList3.insert_after(-1, 5);
	myList3.print();
	cout << "\nInsert 11 after position 10";
	myList3.insert_after(10, 11);
	myList3.print();
	
		
	cout << "\nTesting insert_before";
	cout << "\nInsert 5 before position 2";
	myList3.insert_before(2, 5);
	myList3.print();
	cout << "\nInsert 5 before position -1";
	myList3.insert_before(-1, 5);
	myList3.print();
	cout << "\nInsert 13 before position 13";
	myList3.insert_before(13, 13);
	myList3.print();
	
	cout << "\nTesting count\n";
	cout << "Input a value:" << endl;
	int val;
	cin >> val;
	cout << "There are " << myList3.count(val) << " " << val << "'s." << endl;
	
		
	return 0;
}

/**
 * Local Fibonacci function for filling and testing Lists 
 * @param n the Fibonacci number to calculate
 * @return fibonacci(n)
 */
int fibonacci(int n)
{
	if((n == 0) | (n == 1))
	{
		return n;
	}
	else
	{
		return fibonacci(n-2) + fibonacci(n-1);
	}
}
