#include <iostream>
#include <stdexcept>

using namespace std;
#include "IntVector.h"

IntVector::IntVector() {
    sz = 0;
    cap = 0;
    //do something with the pointer thing
    //dynamically allocate array
    data = new int[sz];
}

IntVector::IntVector(unsigned size, int value) {
    sz = size;
    cap = size;
    //allocate array of that size
    data = new int[sz];
    for (unsigned int i = 0; i < sz; ++i) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
    cout << "Inside destructor" << endl;
    delete[] data;
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    if (sz == 0) {
        return true;
    }
    else {
        return false;
    }
}

const int & IntVector::at(unsigned index) const {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

const int & IntVector::front() const {
    return data[0];
}

const int & IntVector::back() const {
    return data[sz - 1];
}