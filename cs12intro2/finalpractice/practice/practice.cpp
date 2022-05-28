#include <iostream>
#include <string>

using namespace std;

// double adjust(double arr[], int size, double maxposs) {
//     double max = 0;
//     for (int i = 0; i < size; i++) {
//         if (arr[i] >= max) {
//             arr[i] = max;
//         }
//     }
//     double diff;
//     diff = maxposs - max;
//     for (int i = 0; i < size; i++) {
//         arr[i] = arr[i] + diff;
//     }
//     return diff;
// }

int main(int argc, char *argv[]) {
    
    string input = argv[1];
    string output = argv[2];

    ifstream inFS;
    inFS.open(input);
    if (!inFS.is_open()) {
        cout << "Error opening " << input << endl;
        exit(1);
    }
    ofstream outFS;
    outFS.open(output);
    if (!outFS.is_open()) {
        cout << "Error opening " << input << endl;
        exit(1);
    }

    double num1;
    double num2;
    string operation;
    while (inFS >> num1) {
        inFS >> operator;
        inFS >> num2;
        if (operation == "+") {
            outFS << num1 + num2 << endl;
        }
        else if (operation == "-") {
            outFS << num1 - num2 << endl;
        }
    }
    inFS.close();
    outFS.close();

    return 0;
}

//header file
#ifndef _TEAORDER_H_
#define _TEAORDER_H

#include <string>
#include <iostream>

using namespace std;

class TeaOrder {
    public:
        TeaOrder(string, int);
        TeaOrder(string, string);
        string getName() const;
        int getSize() const;
        void setSize(string);
        double getPrice() const;
    private:
        string name;
        int size;
}

#endif

//implementation file

#include "TeaOrder.h"

#include <iostream>
#include <string>

using namespace std;

TeaOrder::TeaOrder(string name, int size) {
    this->name = name;
    this->size = size;
}

TeaOrder::TeaOrder(string name, string size) {
    this->name = name;
    setSize(size);
}

string TeaOrder::getName() const {
    return name;
}

int TeaOrder::getSize() const {
    return size;
}

void TeaOrder::setSize(string size) {
    if (size == "medium") {
        this->size = 14;
    }
    else if (size == "large") {
        this->size = 20;
    }
    else {
        this->size = 10;
    }
}

double TeaOrder::getPrice() const {
    double price;
    price = size * 0.2;

    return price;
}