#include <iostream>
using namespace std;

#include "IntVector.h"

int main() {

   int testNum;
   
   cout << "Enter test number: ";
   cin >> testNum;
   cout << endl;
   
   if (testNum == 1) {
      int arr1[] = {4, 7, 9, 8, 1, 9, 2, 3, 5, 0};
      IntVector v1(arr1, 3, 6);
      
      cout << "Size: " << v1.size() << endl;
      cout << "Capacity: " << v1.capacity() << endl;
      cout << "v1: ";
      for (unsigned i = 0; i < v1.size(); ++i) {
         cout << v1.at(i) << ' ';
      }
      cout << endl;  
   }
   
   else if (testNum == 2) {
      int arr2[] = {1, 7, 3, 2};
      IntVector v2(arr2, 0, 3);
      
      cout << "Size: " << v2.size() << endl;
      cout << "Capacity: " << v2.capacity() << endl;
      cout << "v2: ";
      for (unsigned i = 0; i < v2.size(); ++i) {
         cout << v2.at(i) << ' ';
      }
      cout << endl;  
   }
 
   else if (testNum == 3) {
      int arr3[] = {5, 7, 4, 9, 0};
      IntVector v3(arr3, 2, 2);
      
      cout << "Size: " << v3.size() << endl;
      cout << "Capacity: " << v3.capacity() << endl;
      cout << "v3: ";
      for (unsigned i = 0; i < v3.size(); ++i) {
         cout << v3.at(i) << ' ';
      }
      cout << endl;  
   }
   
   else if (testNum == 4) {
      int arr4[] = {5, 7, 4, 10, 3, 8, 4, 2};
      IntVector v4(arr4, 3, 2);
      
      cout << "Size: " << v4.size() << endl;
      cout << "Capacity: " << v4.capacity() << endl;
      cout << "v4: ";
      for (unsigned i = 0; i < v4.size(); ++i) {
         cout << v4.at(i) << ' ';
      }
      cout << endl;  
   } 
   return 0;
}
