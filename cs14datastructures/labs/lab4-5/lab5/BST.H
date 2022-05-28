/**
 * cs014_sum20A
 * lab4-5
 * BST.H
 * RR
 */
   /**
 * Course: CS014 Summer 2020
 *
 * First Name: Diane
 * Last Name: Shan
 * Username: dshan017
 * email address: dshan017@ucr.edu
 *
 *
 * Assignment: lab5
 * Filename : BST.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

char ch = 'a';
int i = 1;

class BST {

private:
  struct BinaryNode {

    int value;
    char label;
    BinaryNode* left;
    BinaryNode* right;
    int depth;
    int height;
    int inorder_num;
    int preorder_num;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {
      label = ch;
      ch++;
    }
    
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	      t = new BinaryNode(v);
      }
      else if (v < t->value)
	      t->left = insert(v, t->left);
      else if (v > t->value)
	      t->right = insert(v, t->right);
	    else if (v == t->value) {
	      cout << "ERROR! " << v << " is already in the tree." << endl;
	    }
      else
	      t->value = v;
      return t;
    }
    
    static BinaryNode* remove(int v, BinaryNode* t) {
      if(t) {
	      if(v < t->value)
	        t->left = remove(v, t->left);
	      else if(t->value < v)
	        t->right = remove(v, t->right);
	      else if(t->left != NULL && t->right != NULL) {
	        t->value = find_min(t->right)->value;
	        t->right = remove(t->value, t->right);
	      }
	      else if (t->value != v) {
	        cout << "ERROR! " << v << " is not in the tree." << endl; 
	      }
	      else {
	       BinaryNode* oldNode = t;
	       t = (t->left != NULL) ? t->left : t->right;
	       delete oldNode;
	      }
      }
      return t;
    }
    
    static BinaryNode* find_min(BinaryNode* t) {
      if(t == NULL)
	      return NULL;
      if(t->left == NULL)
	      return t;
      return find_min(t->left);
    }

  };

public:
  BST(): root(NULL) {}
  
  ~BST() {
    deleter(root);
  }
  
  void deleter(BinaryNode* t) {
    if (t) {
      deleter(t->right);
      deleter(t->left);
      delete t;
    }
  }
  
  void insert(int v) { root = BinaryNode::insert(v, root); }
  
  void remove(int v) { root = BinaryNode::remove(v, root); }
  
  void display() { display(root); }
  
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }
  
  BinaryNode* GetRoot() {
    return root;
  }
  
  int getHeight(BinaryNode* n) {
    if (n == nullptr) {
      return -1;
    }
    int lefth = getHeight(n->left);
    int righth = getHeight(n->right);
    n->height = max(lefth, righth) + 1;
    return max(lefth, righth) + 1;
  }
  
  void outputb(ofstream& o) {
    o << "digraph G {" << endl;
    o << endl;
  }
  
  void outpute(ofstream& o) {
    o << endl;
    o << "}" << endl;
  }
  
  void heightDotNode(ofstream& o, BinaryNode* n) {
    if (n == nullptr) {
      return;
    }
    if (n) {
      o << "  " << n->label << " [color = lightblue, style = filled, label=\"key=" << n->value << ", h=" << n->height << "\"];" << endl;
      heightDotNode(o, n->left); 
      heightDotNode(o, n->right); 
    }
  }
  
  void dotEdge(ofstream& o, BinaryNode* n) {
    if (n == nullptr) {
      return;
    }
    if (n) {
      if (n->left != nullptr) {
        o << "  " << n->label << " -> " << n->left->label << ";"<< endl;
        dotEdge(o, n->left);
      }
      if (n->right != nullptr) {
        o << "  " << n->label << " -> " << n->right->label << ";" << endl;
        dotEdge(o, n->right);
      }
    }
  }
  
  void preorderDotNode(ofstream& o, BinaryNode* n) {
    if (n == nullptr) {
      return;
    }
    if (n) {
      o << "  " << n->label << " [color = orange, peripheries=2, style = filled, label=\"key=" << n->value << ", pre=" << i << "\"];" << endl;
      i++; 
      preorderDotNode(o, n->left);
      preorderDotNode(o, n->right);
    }
  }
  
  void inorderDotNode(ofstream& o, BinaryNode* n) {
    if (n == nullptr) {
      return;
    }
    if (n) {
      inorderDotNode(o, n->left);
      o << "  " << n->label << " [color = red, peripheries=2, style = filled, label=\"key=" << n->value << ", in=" << i << "\"];" << endl;
      i++; 
      inorderDotNode(o, n->right);
    }
  }
  
  void postorderDotNode(ofstream& o, BinaryNode* n) {
    if (n == nullptr) {
      return;
    }
    if (n) {
      postorderDotNode(o, n->left);
      postorderDotNode(o, n->right);
      o << "  " << n->label << " [color = purple, peripheries=2, style = filled, label=\"key=" << n->value << ", post=" << i << "\"];" << endl;
      i++;
    }
  }
  
  private:
    BinaryNode* root;
};

#endif /* BST_H_ */

