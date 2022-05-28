#include <iostream>
#include <stdexcept>

using namespace std;
#include "IntVector.h"

int main() {
    // IntVector v; //default constructor
    // IntVector v2(5); //second constructor

    // unsigned size;
    // unsigned cap;

    // size = v.size();    //test size and deafult constructor
    // cap = v.capacity(); //test capacity and default constructor

    // cout << "Size: " << size << endl;
    // cout << "Capacity: " << cap << endl;

    // //testing constructor with parameter size passed in
    // size = v2.size();
    // cap = v2.capacity();

    // cout << "Size: " << size << endl;
    // cout << "Capacity: " << cap << endl;
    // //outputting the values of the vector
    // for (unsigned int i = 0; i < size; ++i) {
    //     cout << v2.at(i) << " "; //also tests at function
    // }
    // cout << endl;

    // //testing empty function
    // if (v.empty()) {
    //     cout << "Vector is empty" << endl;
    // }
    // else {
    //     cout << "Vector is not empty" << endl;
    // }

    // if (v2.empty()) {
    //     cout << "Vector is empty" << endl;
    // }
    // else {
    //     cout << "Vector is not empty" << endl;
    // }

    //testing at function
    // IntVector v3(10);

    // cout << v3.at(12) << endl;

    //testing front function and back function

    // cout << v3.front() << endl;
    // cout << v3.back() << endl;

    //testing mutator functions, at, front, and back
    // IntVector v4(10);

    // v4.at(0) = 5;
    // v4.at(1) = 2;
    // v4.back() = 8;

    // cout << v4.front() << " " << v4.at(9) << endl;

    //testing insert and erase functions
    IntVector v5(5);
    IntVector v9;

    v5.at(0) = 3;
    v5.at(1) = 4;
    v5.at(2) = 5;
    v5.at(3) = 7;
    v5.at(4) = 6;

    v5.insert(2, 2);

    for (unsigned int i = 0; i < v5.size(); ++i) {
        cout << v5.at(i) << " "; 
    }
    cout << endl;


    v5.insert(6, 3);
    for (unsigned int i = 0; i < v5.size(); ++i) {
        cout << v5.at(i) << " "; 
    }
    cout << endl;

    v9.insert(0, 2);

    for (unsigned int i = 0; i < v9.size(); ++i) {
        cout << v9.at(i) << " "; 
    }
    cout << endl;

    v5.insert(0, 4);
    for (unsigned int i = 0; i < v5.size(); ++i) {
        cout << v5.at(i) << " "; 
    }
    cout << endl;

    // v5.erase(2);

    // for (unsigned int i = 0; i < v5.size(); ++i) {
    //     cout << v5.at(i) << " "; 
    // }
    // cout << endl;

    //testing assign function
    // IntVector v6(7);

    // v6.at(0) = 2;
    // v6.at(1) = 1;
    // v6.at(4) = 5;
    // v6.at(6) = 3;

    // v6.assign(9, 2);

    // for (unsigned int i = 0; i < v6.size(); ++i) {
    //     cout << v6.at(i) << " "; 
    // }
    // cout << endl;

    //testing push_back and pop_back function and clear
    // IntVector v7(3);

    // v7.at(0) = 2;
    // v7.at(1) = 6;
    // v7.at(2) = 9;

    // v7.push_back(3);

    // for (unsigned int i = 0; i < v7.size(); ++i) {
    //     cout << v7.at(i) << " "; 
    // }
    // cout << endl;

    // v7.pop_back();

    // for (unsigned int i = 0; i < v7.size(); ++i) {
    //     cout << v7.at(i) << " "; 
    // }
    // cout << endl;

    // v7.clear();

    // for (unsigned int i = 0; i < v7.size(); ++i) {
    //     cout << v7.at(i) << " "; 
    // }
    // cout << endl;

    //test resize and reserve function
    // IntVector v8(4);

    // v8.resize(9);

    // cout << "size: " << v8.size() << endl;
    // cout << "cap: " << v8.capacity() << endl;

    // v8.reserve(12);

    // cout << "size: " << v8.size() << endl;
    // cout << "cap: " << v8.capacity() << endl;

    return 0;
}