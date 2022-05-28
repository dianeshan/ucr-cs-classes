#include <iostream>
#include <vector>
using namespace std;
unsigned int i;
unsigned int j;

/* Define your function here */
void SortVector(vector<int>& myVec) {
    int smallest;
    int temp;

    for (i = 0; i < myVec.size(); ++i) {
        smallest = i;
        for (j = i + 1; j < myVec.size(); ++j) {
            if (myVec.at(j) < myVec.at(smallest)) {
               temp = myVec.at(smallest);
               myVec.at(smallest) = myVec.at(j);
               myVec.at(j) = temp;
            }
        }
    }
}

int main() {
   /* Type your code here */
   int numInput;
   
   cin >> numInput;
   
   vector<int> jackSmart(numInput);
   
   for (i = 0; i < jackSmart.size(); ++i) {
       cin >> jackSmart.at(i);
   }

   SortVector(jackSmart);

   for (i = 0; i < jackSmart.size(); ++i) {
       cout << jackSmart.at(i) << " ";
   }
   cout << endl; 

   return 0;
}
