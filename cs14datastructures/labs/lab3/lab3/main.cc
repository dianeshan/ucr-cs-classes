/**
 * cs014_sum20A
 * Sample main with exceptions
 * Stack template
 * main.cc
 * RR
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
 * Assignment: lab3
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <vector>
#include "stack.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <cstring>

using namespace std;

bool is_operand(string s) {
  if (s != "(" && s != ")" && s != "+" && s != "*" && s != "-" && s != "/") {
    return true;
  }
  return false;
}

bool is_operator(string s) {
  if (s == "+" || s == "*" || s == "-" || s == "/") {
    return true;
  }
  return false;
}

int priority(string p) {
  if (p == "^") {
    return 3;
  }
  else if (p == "*" || p == "/") {
    return 2;
  }
  else if (p == "+" || p == "-") {
    return 1;
  }
  else {
    return 0;
  }
}

void takein(string str, vector<string>& input) { //this will take in the line of input from the file and parse it into the characters into a vector
  size_t finding = str.find(' ');
  while (finding != string::npos) {
    input.push_back(str.substr(0, finding)); //get the first character from the string
    str = str.substr(finding + 1); //set the string to be equal to the remaining
    finding = str.find(' '); //look for the next space
  }
  input.push_back(str); //adding the last item into the vector
}

void infix_to_postfix(string oop, vector<string>& input, vector<string>& output) {
  takein(oop, input);
  Stack<string> pengu;
  for (unsigned int i = 0; i < input.size(); i++) {
    if (is_operand(input.at(i))) {
      cout << input.at(i) << " ";
      output.push_back(input.at(i));
    }
    else if (is_operator(input.at(i))) {
      int prio = priority(input.at(i));
      while (!pengu.is_empty() && pengu.top() != "(" && prio <= priority(pengu.top())) {
        cout << pengu.top() << " ";
        output.push_back(pengu.top());
        pengu.pop();
      }
      pengu.push(input.at(i));
    }
    else if (input.at(i) == "(") {
      pengu.push(input.at(i));
    }
    else if (input.at(i) == ")") {
      while (!pengu.is_empty() && pengu.top() != "(") {
        cout << pengu.top() << " ";
        output.push_back(pengu.top());
        pengu.pop();
      }
      pengu.pop();
    }
    
    else {
      cout << "Invalid input" << endl;
    }
  }
  for(int i = 0; i < pengu.size(); i++) {
    cout << pengu.top() << " ";
    output.push_back(pengu.top());
    pengu.pop();
  }
}

void rpn_evaluation(string str) {
  vector<string> input;
  vector<string> output;
  infix_to_postfix(str, input, output);
  Stack<double> S;
  for (unsigned int i; i < output.size(); i++) {
    if (is_operand(output.at(i))) {
      S.push(stod(output.at(i)));
    }
    else if (is_operator(output.at(i))) {
      if (S.is_empty()) {
        cerr << "Stack is empty :(" << endl;
      }
      else {
        double b = S.top();
        S.pop();
        if (S.is_empty()) {
          cerr << "Stack is empty :(" << endl;
        }
        else {
          double a = S.top();
          S.pop();
          double c;
          if (output.at(i) == "+") {
            c = a + b;
          }
          else if (output.at(i) == "*") {
            c = a * b;
          }
          else if (output.at(i) == "-") {
            c = a - b;
          }
          else if (output.at(i) == "/") {
            c = a / b;
          }
          S.push(c);
        }
      }
    }
  }
  double v = S.top();
  S.pop();
  if (!S.is_empty()) {
    cerr << "Stack not empty after processing expression :(" << endl;
  }
  else {
    cout << "= " << v << endl;
  }
}

int main() {

  string name = "Neo";
  Stack<string> s1; // empty Stack of strings

  try {   // try block
    // ternary operator, displays warning if Stack instance is empty
    s1.is_empty() ? cout << "\nNon-Exception check: Empty stack\n" : cout  
      << "Non-Exception check: Non-empty Stack<string>\n";

    s1.push(name);
    s1.push(name);
    s1.push(name);
    s1.push(name);
    s1.push(name);
    // s1.push(name);  // test 1: Raises Stack overflow_error exception, uncomment this line in try block to test

  } catch(overflow_error& e) { // catch block
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
	  cout << s1.top() << endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }
  
  try {
    s1.top(); // test 2: Raises underflow exception, uncomment this line only in try block to test
    s1.push("Trinity"); 
    s1.pop();
    //s1.pop(); // test 3: Raises underflow exception, uncomment this line only in try block to test
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }
  
  Stack<int> s2; // empty Stack of ints
  try {
    // ternary operator, displays warning if Stack instance is empty
    s2.is_empty() ? cout << "\nNon-Exception check: Empty stack\n" : cout  
      << "Non-Exception check: Non-empty Stack<int>\n";
    s2.push(1);
    s2.push(2);
    s2.push(3);
    s2.push(4);
    s2.push(5);
    //s2.push(6);  // test 4: Raises Stack overflow_error exception, uncomment this line in try block to test

  } catch(overflow_error& e) {
    cerr << "Overflow Exception: "<< e.what() << endl;
  } catch(...) {
    cerr << "Whoops! Catch-all block, Stack<int>, terminating program.\n";
  }
  
  try {
	  cout << s2.top() << endl;
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  try {
    //s2.top(); // test 5: Raises underflow exception, uncomment this line only in try block to test
    s2.push(77); 
    s2.pop();
    //s.pop(); // test 6: Raises underflow exception, uncomment this line only in try block to test
  } catch(underflow_error& e) { // catch block
    cerr << "Underflow Exception: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, Stack<int>, terminating program.\n";
  }
  
  /* This code demonstrates that the std::vector m,ember function at()
   * automatically checks whether n is within the bounds of valid elements
   * in the vector, throwing an out_of_range exception if the argument n in
   * v.at(n) is not in range 0 to v.size()-1.
   */
  try {
    // Raises out_of_range exception, uncomment next two lines in try block to test
    // vector<int> myvector(10);
    // cout << myvector.at(20); // vector::at throws an out-of-range
  } catch(out_of_range& e) { // catch block
    cerr << "Out of range error: "<< e.what() << endl;
  } catch(...) { // catch-all block
    cerr << "Whoops! Catch-all block, terminating program.\n";
  }

  cout << "\nThe program flow continues...\n";
  // cout << "The \"return 0;\" statement will cause the program to exit.\n";
  cout << endl;
  
  ifstream inFS;
  string vals;
  inFS.open("input.txt");
  
  if (!inFS.is_open()) {
    cout << "Error opening file" << endl;
    exit(1);
  }
  
  Stack<string> stackky;
  
  while (getline(inFS, vals)) {
    rpn_evaluation(vals);
  }
  
  inFS.close();

  return 0;
}

