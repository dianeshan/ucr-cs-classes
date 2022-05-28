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
 * Assignment: lab3
 * Filename : Stack.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
 #ifndef STACK_H_
 #define STACK_H_
 
 #define MAX_SIZE 20
 #include <stdexcept>
 
 using namespace std;
 
 template<typename T>
 class Stack {
    private:
        int next;
        T* data;
        
    public:
        Stack() { 
            data = new T[MAX_SIZE];
            next = -1; 
        }
        
        ~Stack() {
            delete [] data;    
        }
        
        void push(const T& x) {
            if (size() == MAX_SIZE) {
                throw overflow_error("stack overflow");
            }
            else {
                next++;
                data[next] = x;
            }
        }
        
        void pop() {
            if (is_empty()) {
                throw underflow_error("stack underflow");
            }
            next--;
        }
        
        T& top() {
            if (is_empty()) {
                throw underflow_error("stack underflow");
            }
            else {
                return data[next];
            }
        }
        
        int size() { return next + 1; }
        
        bool is_empty() const {
            if (next + 1 <= 0) {
                return true;
            }
            return false;
        }
 };
 
 
 #endif
 