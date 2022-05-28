#include <iostream>
#include <stdexcept>

using namespace std;
#include "IntVector.h"

IntVector::IntVector() {
    sz = 0;
    cap = 0;
    //dynamically allocate array
    data = nullptr;
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

int & IntVector::at(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

void IntVector::insert(unsigned index, int value) {
    if (index > sz) {
        throw out_of_range("IntVector::insert_range_check");
    }
    else if (index < 0) {
        throw out_of_range("IntVector::insert_range_check");
    }
    else if (index == sz) {
        push_back(value);
    }
    else if (index == 0) {
        expand();
        
        int temp;
        temp = data[0];
        for (unsigned int i = sz; i > index; --i) {
            data[i + 1] = data[i];
        }
        data[1] = temp;
        data[0] = value;
        sz = sz + 1;
    }
    else if (sz + 1 > cap) {
        expand();

        for (unsigned int i = sz; i >= index; --i) {
            data[i + 1] = data[i];
        }

        data[index] = value;
        sz = sz + 1;
    }
    else {
        for (unsigned int i = sz; i >= index; --i) {
            data[i + 1] = data[i];
        }

        data[index] = value;
        sz = sz + 1;
    }
}

void IntVector::erase(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
    }
    else {
        for (unsigned int i = index + 1; i < sz; ++i) {
            data[i - 1] = data[i];
        }
        sz = sz - 1;
    }
}

const int & IntVector::front() const {
    return data[0];
}

int & IntVector::front() {
    return data[0];
}

const int & IntVector::back() const {
    return data[sz - 1];
}

int & IntVector::back() {
    return data[sz - 1];
}

void IntVector::assign(unsigned n, int value) {
    if (n > cap) {
        if (cap * 2 > n) {
            expand();
        }
        else {
            expand(n - cap);
        }  
    }
    delete[] data;
    sz = n;
    data = new int[sz];

    for (unsigned int i = 0; i < sz; ++i) {
        data[i] = value;
    }
}

void IntVector::push_back(int value) {
    if (sz == cap) {
        expand();
    }
    data[sz] = value;
    sz = sz + 1;
}

void IntVector::pop_back() {
    sz = sz - 1;
}

void IntVector::clear() {
    sz = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size <= sz) {
        sz = size;
    }
    else if (size > sz) {
        if (((size - sz) + sz) > cap) {
            if (cap * 2 > size) {
                expand();
            }
            else {
                expand(size - cap);
            }
        }
        for (unsigned int i = sz; i < size; ++i) {
            data[i] = value;
        } 
        sz = size; 
    }
}

void IntVector::reserve(unsigned n) {
    if (cap < n) {
        cap = n;
    }
}

void IntVector::expand() {
    if (cap == 0) {
        cap = 1;
        // delete[] data;
        data = new int[cap];
    }
    else {
        int *temp = new int[2 * cap];
        for (unsigned int i = 0; i < cap; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        cap = cap * 2;
        data = temp;
    }

}

void IntVector::expand(unsigned amount) {
    int *temp = new int[cap + amount];
    for (unsigned int i = 0; i < cap; ++i) {
        temp[i] = data[i];
    }
    delete[] data;
    cap = cap + amount;
    data = temp;
}