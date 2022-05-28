#include <iostream>
using namespace std;

#include "IntList.h"

int main() {

   int testNum;
   
   cout << "Enter test number: ";
   cin >> testNum;
   cout << endl;
   
   if (testNum == 1) {
      IntList test1;
      test1.push_front(-3);
      test1.push_front(-2);
      test1.push_front(-1);
      test1.push_front(11);
      test1.push_front(1);
      test1.push_front(2);
      test1.push_front(3);
      test1.push_front(4);
      cout << "Before: " << test1 << endl;
      test1.removeLargest();
      cout << "After : " << test1 << endl;    
   }
   
   if (testNum == 2) {
      IntList test2;
      test2.push_front(3);
      test2.push_front(4);
      test2.push_front(6);
      test2.push_front(1);
      test2.push_front(7);
      test2.push_front(15);
      cout << "Before: " << test2 << endl;
      test2.removeLargest();
      cout << "After : " << test2 << endl;  
   }
   
   if (testNum == 3) {
      IntList test3;
      test3.push_front(19);
      test3.push_front(8);
      test3.push_front(7);
      test3.push_front(6);
      test3.push_front(5);
      test3.push_front(4);
      test3.push_front(3);
      test3.push_front(2);
      test3.push_front(1);
      cout << "Before: " << test3 << endl;
      test3.removeLargest();
      cout << "After : " << test3 << endl;  
   }   

   if (testNum == 4) {
      IntList test4;
      test4.push_front(2);
      test4.push_front(1);
      test4.push_front(5);
      test4.push_front(4);
      test4.push_front(16);
      test4.push_front(1);
      cout << "Before: " << test4 << endl;
      test4.removeLargest();
      cout << "After : " << test4 << endl;  
   }
   
   if (testNum == 5) {
      IntList test5;
      test5.push_front(-12);
      test5.push_front(-17);
      test5.push_front(-13);
      test5.push_front(-5);
      test5.push_front(-12);
      test5.push_front(-14);
      cout << "Before: " << test5 << endl;
      test5.removeLargest();
      cout << "After : " << test5 << endl;  
   }

   return 0;
}
