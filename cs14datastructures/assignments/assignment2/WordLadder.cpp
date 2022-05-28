/**
* Course: CS014 Summer 2018
*
* First Name: Diane
* Last Name: Shan
* Username: dshan017
* email address: dshan017@ucr.edu
*
*
* Assignment: assignment3
* Filename : WordLadder.cpp
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>

#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder() {}

WordLadder::WordLadder(const string& listFile) {
    ifstream inFS;
    string word;

    inFS.open(listFile);
    if (!inFS.is_open()) {
        cerr << "Error opening " << listFile << endl;
    }
    else {
        while (inFS >> word) {
            dict.push_back(word);
        }
    }
    inFS.close();
}

WordLadder::~WordLadder() {}

void WordLadder::outputLadder(const string& start, const string& end) {
    if (start.size() != end.size()) {
        return;
    }

    if (start == end) {
        cout << start << endl;
        cout << end << endl;
        return;
    }

    stack<string> s;
    s.push(start);
    queue< stack<string> > q;
    q.push(s);                                                  //enqueue this stack

    list<string>::iterator iter;
    while (!q.empty()) {                                        //while the queue is not empty
        for (iter = dict.begin(); iter != dict.end(); iter++) { //for each word in the dictionary
            if (offByOne(q.front().top(), *iter)) {             //if a word is exactly 1 letter different than top string of front stack in queue
                if (*iter == end) {                             //if this word is end word
                    q.front().push(*iter);                      //word ladder found
                    while (!q.front().empty()) {
                        cout << q.front().top() << endl;        //outputting word ladder
                        q.front().pop();                        //pop off stack to get to next one
                    }
                    return;
                }
                else {
                    stack<string> cpy = q.front();              //else make a copy of the front stack
                    cpy.push(*iter);                            //push found word onto copy
                    q.push(cpy);                                //enqueue copy
                    iter = dict.erase(iter);                    //erase the original value so does not go back to it again
                    iter--;                                     //erase makes iter jump forward so need to go back
                }
            }
        }
        q.pop(); //dequeue front stack
    }

    cout << "No ladder found!" << endl; //if get to end of while loop, cout no ladder found

}

void WordLadder::outputLadder(stack<string>& s, const string& start) {
    queue< stack<string> > q;
    q.push(s);                                                  //enqueue this stack

    list<string>::iterator iter;
    while (!q.empty()) {
        for (iter = dict.begin(); iter != dict.end(); iter++) {
            if (offByOne(q.front().top(), *iter)) {
                if (*iter == start) {
                    q.front().push(*iter);
                    while (!q.front().empty()) {
                        cout << q.front().top() << endl;
                        q.front().pop();
                    }
                    return;
                }
                else {
                    stack<string> cpy = q.front();
                    cpy.push(*iter);
                    q.push(cpy);
                    iter = dict.erase(iter);
                    iter--;
                }
            }
        }
        q.pop(); //dequeue front stack
    }
}

void WordLadder::printDictionary() {
    list<string>::iterator iter;
    for (iter = dict.begin(); iter != dict.end(); iter++) {
        cout << *iter << endl;
    }
}

bool WordLadder::offByOne(const string& s1, const string& s2) {
    if (s1 == s2) {
        return false;
    }
    int count = 0;
    for (unsigned int i = 0; i < s1.size(); i++) {
        if (s1.at(i) != s2.at(i)) {
            count++;
        }
        if (count >= 2) {
            return false;
        }
    }
    return true;
}
