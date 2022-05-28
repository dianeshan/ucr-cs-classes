/**
 * cs014_sum20A
 * lab4-5
 * main.cc
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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <mode>" << endl;
    exit(1);
  }
  
  string cmd = "";
  int key = -1;
  BST t;
  string mode = argv[1];
  
  // ofstream you will use to write to file output.dot
  // currently an empty output.dot gets written into pwd
  ofstream ofs("output.dot");
  if(!ofs) {
    cout << "output.dot could not be opened." << endl;
    exit(1);
  }
  
  for(;;) {
    cin >> cmd;
    if(cmd == "insert") {
      cin >> key;
      t.insert(key);
    }
    else if(cmd == "remove") {
      cin >> key;
      t.remove(key);
    }
    else if(cmd == "dotty") {
      // cout << "mode = " << mode << endl; //remove once mode used in program
      string mode;
      cout << "Choose mode: height, preorder, inorder, or postorder" << endl;
      cin >> mode;
      if (mode == "height") {
        t.outputb(ofs);
        t.heightDotNode(ofs, t.GetRoot());
        ofs << endl;
        t.dotEdge(ofs, t.GetRoot());
        t.outpute(ofs);
      }
      else if (mode == "preorder") {
        t.outputb(ofs);
        t.preorderDotNode(ofs, t.GetRoot());
        ofs << endl;
        t.dotEdge(ofs, t.GetRoot());
        t.outpute(ofs);
      }
      else if (mode == "inorder") {
        t.outputb(ofs);
        t.inorderDotNode(ofs, t.GetRoot());
        ofs << endl;
        t.dotEdge(ofs, t.GetRoot());
        t.outpute(ofs);
      }
      else if (mode == "postorder") {
        t.outputb(ofs);
        t.postorderDotNode(ofs, t.GetRoot());
        ofs << endl;
        t.dotEdge(ofs, t.GetRoot());
        t.outpute(ofs);
      }
      else {
        cout << "Invalid mode!" << endl;
      }
      // implement code here that will produce the correct dot file
      // based on the user's preference (mode), i.e., preorder, postorder,
      // inorder, node height
    }
    else if(cmd == "display") t.display();
    // else if(cmd == "height") t.height();
    // else if(cmd == "inorder") t.inorder();
    // else if(cmd == "preorder") t.preorder();
    // else if(cmd == "postorder") t.postorder();
    else if(cmd == "end") break;
    else
      cout << cmd << ", not found, try again." << endl;
  }
  // close ofstream
  ofs.close();
  cout << "Good bye!" << endl;
  return 0;
}
