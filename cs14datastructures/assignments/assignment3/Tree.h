#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

using namespace std;

class Tree {

private:
    Node *root;

private:
    void insert(Node *, const string &);
    bool search(Node *, const string &);
    void inOrder(Node *);
    void postOrder(Node *);
    void preOrder(Node *);
    string largest(Node *);
    string smallest(Node *);
    int height(Node *, const string &);
    void remove(Node *, const string &, Node *n);
    Node* find(Node *, const string &);
    void printTreeSideways(Node *);

public:
    void insert(const string &);
    bool search(const string &);
    void inOrder();
    void postOrder();
    void preOrder();
    string largest();
    string smallest();
    int height(const string &);
    void remove(const string &);
    void printTreeSideways();

    // Add any additional variables/functions here

};

#endif
