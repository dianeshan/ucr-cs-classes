#include <iostream>
#include <stdexcept>

using namespace std;
#include "IntVector.h"

int main() {
    IntVector v; //default constructor
    IntVector v2(5); //second constructor

    unsigned size;
    unsigned cap;

    size = v.size();    //test size and deafult constructor
    cap = v.capacity(); //test capacity and default constructor

    cout << "Size: " << size << endl;
    cout << "Capacity: " << cap << endl;

    //testing constructor with parameter size passed in
    size = v2.size();
    cap = v2.capacity();

    cout << "Size: " << size << endl;
    cout << "Capacity: " << cap << endl;
    //outputting the values of the vector
    for (unsigned int i = 0; i < size; ++i) {
        cout << v2.at(i) << " "; //also tests at function
    }
    cout << endl;

    //testing empty function
    if (v.empty()) {
        cout << "Vector is empty" << endl;
    }
    else {
        cout << "Vector is not empty" << endl;
    }

    if (v2.empty()) {
        cout << "Vector is empty" << endl;
    }
    else {
        cout << "Vector is not empty" << endl;
    }

    //testing at function
    // IntVector v3(10);

    // cout << v3.at(12) << endl;

    //testing front function and back function

    // cout << v3.front() << endl;
    // cout << v3.back() << endl;

    return 0;
}