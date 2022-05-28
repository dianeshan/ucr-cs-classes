#include <iostream>
#include "Tree.h"
#include "Node.h"

using namespace std;

void Tree::insert(const string &s) {
    insert(root, s);
}

bool Tree::search(const string &s) {
    return search(root, s);
}

string Tree::largest() {
    if (root == nullptr) {
        return "";
    }
    return largest(root);
}

string Tree::smallest() {
    if (root == nullptr) {
        return "";
    }
    return smallest(root);
}

int Tree::height(const string &s) {
    if (root == nullptr) {
        return -1;
    }
    if (!search(s)) {
        return -1;
    }
    Node* temp = find(root, s);
    if (temp->left == nullptr && temp->right == nullptr) {
        return 0;
    }
    return height(temp, s);
}

void Tree::remove(const string &s) {
    if (!search(s)) {
        return;
    }
    Node* temp = find(root, s);
    if (temp->getCount() > 1) {
        temp->setCount(temp->getCount() - 1);
        return;
    }
    Node* parent = nullptr;
    remove(root, s, parent);
}

void Tree::preOrder() {
    preOrder(root);
}

void Tree::inOrder() {
    inOrder(root);
}

void Tree::postOrder() {
    postOrder(root);
}

void Tree::printTreeSideways() {
    printTreeSideways(root);
}

void Tree::insert(Node* n, const string &s) {
    if (n == nullptr) {
        n = new Node(s);
        root = n;
        return;
    }
    else if (n->getString() == s) {
        int counter;
        counter = n->getCount();
        n->setCount(counter + 1);
        return;
    }
    else if (s < n->getString()) {
        if (n->left != nullptr) {
            insert(n->left, s);
        }
        else {
            Node* t = new Node(s);
            n->left = t;
            return;
        }
    }
    else if (s > n->getString()) {
        if (n->right != nullptr) {
            insert(n->right, s);
        }
        else {
            Node* t = new Node(s);
            n->right = t;
            return;
        }
    }
    else {
        n->getString() = s;
    }
    return;
}

bool Tree::search(Node* n, const string &s) {
    if (n == nullptr) {
        return false;
    }
    if (n->getString() == s) {
        return true;
    }
    else if (n->getString() < s) {
        return search(n->right, s);
    }
    else if (n->getString() > s) {
        return search(n->left, s);
    }
    return false;
}

string Tree::largest(Node* n) {
    if (n == nullptr) {
        return "";
    }
    if (n->right == nullptr) {
        return n->getString();
    }
    return largest(n->right);
}

string Tree::smallest(Node* n) {
    if (n == nullptr) {
        return "";
    }
    if (n->left == nullptr) {
        return n->getString();
    }
    return smallest(n->left);
}

int Tree::height(Node* n, const string &s) {
    if (n == nullptr) {
        return -1;
    }
    int lheight = height(n->left, s);
    int rheight = height(n->right, s);
    return max(lheight, rheight) + 1;
}

void Tree::remove(Node* n, const string &s, Node* parent) {
    if (n == nullptr) {
        return;
    }
    if (n->getString() == s) {
        if (n->left == nullptr && n->right == nullptr) {
            if (parent == nullptr) {
                root = nullptr;
            }
            else if (parent->left == n) {
                parent->left = nullptr;
            }
            else {
                parent->right = nullptr;
            }
        }
        else if (n->left != nullptr && n->right == nullptr) {
            if (parent == nullptr) {
                root = n->left;
            }
            else if (parent->left == n) {
                parent->left = n->left;
            }
            else {
                parent->right = n->left;
            }
        }
        else if (n->left == nullptr && n->right != nullptr) {
            if (parent == nullptr) {
                root = n->right;
            }
            else if (parent->left == n) {
                parent->left = n->right;
            }
            else {
                parent->right = n->right;
            }
        }
        else {
            Node* pre = n->left;
            while (pre->right != nullptr) {
                pre = pre->right;
            }
            string temps = pre->getString();
            int counts = pre->getCount();
            remove(root, pre->getString(), parent);
            n->setString(temps);
            n->setCount(counts);
        }
        return;
    }
    else if (n->getString() < s) {
        remove(n->right, s, n);
    }
    else {
        remove(n->left, s, n);
    }
    return;
}

void Tree::preOrder(Node* n) {
    if (n == nullptr) {
        return;
    }
    if (n) {
        cout << n->getString() << "(" << n->getCount() << ")" << ", ";
        preOrder(n->left);
        preOrder(n->right);
    }
}

void Tree::inOrder(Node* n) {
    if (n == nullptr) {
        return;
    }
    if (n) {
        inOrder(n->left);
        cout << n->getString() << "(" << n->getCount() << ")" << ", ";
        inOrder(n->right);
    }
}

void Tree::postOrder(Node* n) {
    if (n == nullptr) {
        return;
    }
    if (n) {
        postOrder(n->left);
        postOrder(n->right);
        cout << n->getString() << "(" << n->getCount() << ")" << ", ";
    }
}

Node* Tree::find(Node* n, const string &s) {
    if (root == nullptr) {
        return nullptr;
    }
    if (n) {
        if (s == n->getString()) {
            return n;
        }
        else if (s < n->getString()) {
            if (n->left != nullptr) {
                return find(n->left, s);
            }
        }
        else if (s > n->getString()) {
            if (n->right != nullptr) {
                return find(n->right, s);
            }
        }
        else {
            return n;
        }
    }
    return n;
}

void Tree::printTreeSideways(Node* n) {
    if (n == nullptr) {
        return;
    }
    static int d = 0;
    ++d;
    if (n->right != nullptr) {
        printTreeSideways(n->right);
    }
    for (int i = 0; i < d; ++i) {
        cout << " ";
    }
    cout << n->getString() << "(" << n->getCount() << ")" << endl << endl;
    if (n->left != nullptr) {
        printTreeSideways(n->left);
    }
    --d;

}
