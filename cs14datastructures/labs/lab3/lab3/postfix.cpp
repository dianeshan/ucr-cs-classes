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
 * Filename : postfix.cpp
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
#include <sstream>
#include <string>
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

void takein(string str, vector<string>& input) { //this will take in the line of input from the file and parse it into the characters into a vector
  size_t finding = str.find(' ');
  while (finding != string::npos) {
    input.push_back(str.substr(0, finding)); //get the first character from the string
    str = str.substr(finding + 1); //set the string to be equal to the remaining
    finding = str.find(' '); //look for the next space
  }
  input.push_back(str); //adding the last item into the vector
}

void rpn_evaluation(string str) {
  if (str.size() == 0) {
    return;
  }
  vector<string> output;
  takein(str, output);
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
    cout << v << endl;
  }
}

int main(int argc, char *argv[]) {
  string inputfile;
  
  (void)argc;
  inputfile = argv[1];
  ifstream inFS;
  string expr;
  inFS.open(inputfile);
  
  if (!inFS.is_open()) {
    cout << "Error opening file" << endl;
    exit(1);
  }
  
  Stack<string> stackky;
  
  while (getline(inFS, expr)) {
    rpn_evaluation(expr);
    cout << endl;
  }
  
  inFS.close();
  
  return 0;

}

