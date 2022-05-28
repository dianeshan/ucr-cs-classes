#include <iostream>

using namespace std;

#include "IntList.h"
#include "SortedSet.h"

int main() {

    SortedSet list1;
    IntList list2;

    SortedSet list3 = SortedSet(list1);
    SortedSet list4 = SortedSet(list2);
    list1.push_front(10);
    list1.push_front(12);
    list1.push_front(20);

    if (list1.in(12)) {
        cout << "yay" << endl;
    }
    else {
        cout << "boo" << endl;
    }

    cout << list1 << endl;

    list1.add(30);
    cout << list1 << endl;
    list1.add(40);
    cout << list1 << endl;
    list1.add(12);
    cout << list1 << endl;

    list4.push_back(34);
    cout << list4 << endl;
    list4.push_back(30);
    cout << list4 << endl;
    list4.push_front(20);
    cout << list4 << endl;
    list4.push_front(15);
    cout << list4 << endl;

    SortedSet sset1 = list1 | list4;
    cout << sset1 << endl;
    SortedSet sset2 = list1 & list4;
    cout << sset2 << endl;
    

    return 0;
}