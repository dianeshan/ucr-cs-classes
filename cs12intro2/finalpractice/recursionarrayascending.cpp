#include <iostream>
#include <string>

using namespace std;

// When completed, submit this file to gradescope.

// returns true if all values within array are in ascending order (NO LOOPS!!)
bool isAscending(int arr[], int size);


int main() {


    int arr[] = {4, 7, 1, 5};
    cout << "4,7,1,5: " << isAscending(arr, 4) << endl;
    
    int arr1[] = {1, 2, 3, 4, 5};        
    cout << "1,2,3,4,5: " << isAscending(arr1, 5) << endl;
    
    int arr2[] = {3, 2, 1};        
    cout << "3,2,1: " << isAscending(arr2, 3) << endl;
    
    int arr3[] = {-1};        
    cout << "-1: " << isAscending(arr3, 1) << endl;
    
    int arr4[] = {1, 2, 3, 4, 5, 4};        
    cout << "1,2,3,4,5,4: " << isAscending(arr4, 6) << endl;

    int arr5[] = {10, 2, 3, 4, 5};        
    cout << "10,2,3,4,5: " << isAscending(arr5, 5) << endl; 
   
   return 0;
}

bool isAscending(int arr[], int size) {
   
   // implement recursive isAscending function
   if (size == 0) {
      return true;
   }
   if (size == 1) {
      return true;
   }
   if (arr[size - 1] < arr[size - 2]) {
      return false;
   }
   else {
      return isAscending(arr, size - 1);
   }
   
   return false;
}