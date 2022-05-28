#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

  //tests constructor, destructor, push_front, pop_front, display

   // {
      cout << "\nlist1 constructor called" << endl;
      IntList list1;
      // IntList list2;
      list1.push_back(10);
      list1.push_back(10);
      cout << "list1: " << list1 << endl;
      list1.remove_duplicates();
      cout << "list1: " << list1 << endl;
      IntList list2;
      list2 = list1;
      cout << "list1: " << list1 << endl;
      cout << "list2: " << list2 << endl;
      list1.pop_front();
      cout << list1.back() << endl;


   //    list2.push_front(8);
   //    list2.push_front(20);
   //    list2.push_front(20);
   //    list2.push_front(5);
   //    list2.push_front(6);
   //    list2.push_front(10);
   //    cout << "list2: " << list2 << endl;
   //    list2.selection_sort();
   //    cout << "list2: " << list2 << endl;
   //    list2.insert_ordered(0);
   //    cout << "list2: " << list2 << endl;
   //    list2.remove_duplicates();
   //    cout << "list2: " << list2 << endl;
   //    cout << "pushfront 10" << endl;
   //    list1.push_front(10);
   //    cout << "pushfront 20" << endl;
   //    list1.push_front(20);
   //    cout << "pushfront 30" << endl;
   //    list1.push_front(30);
   //    cout << "list1: " << list1 << endl;
   //    cout << "pop" << endl;
   //    list1.pop_front();
   //    cout << "list1: " << list1 << endl;
   //    cout << "pop" << endl;
   //    list1.pop_front();
   //    cout << "list1: " << list1 << endl;
   //    cout << "pop" << endl;
   //    list1.pop_front();
   //    cout << "list1: " << list1 << endl;
   //    cout << "pushfront 100" << endl;
   //    list1.push_front(100);
   //    cout << "pushfront 200" << endl;
   //    list1.push_front(200);
   //    cout << "pushfront 300" << endl;
   //    list1.push_front(300);
   //    cout << "list1: " << list1 << endl;
   //    cout << endl;
   //    cout << "Calling list1 destructor..." << endl;
   // }
   // cout << "list1 destructor returned" << endl;
   
   // // Test destructor on empty IntList
   // {
   //    IntList list2;
   //    cout << "Calling list2 destructor..." << endl;
   // }
   // cout << "list2 destructor returned" << endl;
   
   return 0;
}
