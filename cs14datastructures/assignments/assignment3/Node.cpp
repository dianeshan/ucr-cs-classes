#include "Node.h"
#include <iostream>

using namespace std;

Node::~Node() {

    if (right) {
        delete right;
    }

    if (left) {
        delete left;
    }

}

//------------------------------------------------------------------------

const Node&
Node::operator=(const Node& right) {
    if (&right != this) {
        this->str = right.str;
        this->count = right.count;
    }
    return *this;
}

int Node::getCount() {
    return count;
}

void Node::setCount(int newcount) {
    count = newcount;
}

string Node::getString() {
    return str;
}

void Node::setString(string s) {
    str = s;
}
