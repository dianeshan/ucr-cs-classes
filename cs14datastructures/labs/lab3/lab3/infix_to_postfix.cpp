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
 * Filename : infix_to_postfix.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>
#include <vector>
#include "Stack.H"
#include <stdexcept>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <cstring>

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

string paren(string str) {
  string newstr = str;
  int j = 0;
  for (unsigned int i = 0; i < str.size(); i++) {
    if (str.at(i) == '(') {
      newstr.at(j) = str.at(i);
      newstr.resize(newstr.size() + 1);
      newstr.at(j + 1) = ' ';
      j = j + 2;
    }
    else if (str.at(i) == ')') {
      newstr.at(j) = ' ';
      newstr.resize(newstr.size() + 1);
      newstr.at(j + 1) = str.at(i);
      j = j + 2;
    }
    else {
      newstr.at(j) = str.at(i);
      j++;
    }
  }
  return newstr;
}

void takein(string str, vector<string>& input) { //this will take in the line of input from the file and parse it into the characters into a vector
  str = paren(str);
  size_t finding = str.find(' ');
  while (finding != string::npos) {
    input.push_back(str.substr(0, finding)); //get the first character from the string
    str = str.substr(finding + 1); //set the string to be equal to the remaining
    finding = str.find(' '); //look for the next space
  }
  input.push_back(str); //adding the last item into the vector
}

// string checking(string str) {
//     for (unsigned int i = 0; i < str.size(); i++) {
//       if (str.at(i) == '(' || str.at(i) == ')') {
//         str.erase(str.begin() + i);
//         i--;
//       }
//     }
//     return str;
// }

void infix_to_postfix(string str) {
  vector<string> input;
  takein(str, input);
  Stack<string> store;
  for (unsigned int i = 0; i < input.size(); i++) {
    if (is_operand(input.at(i))) {
      cout << input.at(i) << " ";
    }
    else if (is_operator(input.at(i))) {
      int prio = priority(input.at(i));
      while (!store.is_empty() && store.top() != "(" && prio <= priority(store.top())) {
        cout << store.top() << " ";
        store.pop();
      }
      store.push(input.at(i));
    }
    else if (input.at(i) == "(") {
      store.push(input.at(i));
    }
    else if (input.at(i) == ")") {
      while (!store.is_empty() && store.top() != "(") {
        cout << store.top() << " ";
        store.pop();
      }
      store.pop();
    }
    else {
      cout << "Invalid input" << endl;
    }
  }
  for (int i = 0; i < store.size(); i++) {
    if (store.top() == "(") {
      store.pop();
    }
    else {
      cout << store.top() << " ";
      store.pop();
    }
  }
}

int main(int argc, char *argv[]) {
  string inputfile;
  
  inputfile = argv[1];
  (void)argc;
  ifstream inFS;
  string expr;
  inFS.open(inputfile);
  
  if (!inFS.is_open()) {
    cout << "Error opening file" << endl;
    exit(1);
  }
  
  while (getline(inFS, expr)) {
    infix_to_postfix(expr);
    cout << endl;
  }
  
  inFS.close();
  
  return 0;
}
