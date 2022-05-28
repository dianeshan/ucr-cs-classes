//include any standard libraries needed
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line
   string filename;
   double avg;
   int indexToRemove;
   int size;
   double n;
   int i = 0;

   if (argc == 2) {
      filename = argv[1];
   }
   else {
      cout << "Error" << endl;
      return 1;
   }


   // open file and verify it opened
   ifstream inFS;
   inFS.open(filename);
   if (!inFS.is_open()) {
      cout << "Could not open file " << argv[1] << "." << endl;
      return 1;
   }

   // Declare an array of doubles of size ARR_CAP.
   double pengu[ARR_CAP];

   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
   while (inFS >> n) {
      pengu[i] = n;
      ++i;
   }

   size = i;

   inFS.close();
    
   // Call the mean function passing it this array and output the 
   // value returned.
   avg = mean(pengu, size);
   cout << "Mean: " << avg << endl;
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
   cout << "Enter index of value to be removed (0 to " << size - 1 << ") :";
   cin >> indexToRemove;
   cout << endl;
	
   // Call the display function to output the array.
   cout << "Before removing value: ";
   display(pengu, size);
   cout << endl;
   
   // Call the remove function to remove the value at the index
   // provided by the user.
   remove(pengu, size, indexToRemove);
    
   // Call the display function again to output the array
   // with the value removed.
   cout << "After removing value: ";
   display(pengu, size);
   cout << endl;
   
   // Call the mean function again to get the new mean
   avg = mean(pengu, size);
   cout << "Mean: " << avg << endl;
   
	return 0;
}

double mean(const double array[], int arraySize) {
   double sum = 0;
   double avg;
   for (int i = 0; i < arraySize; ++i) {
      sum = sum + array[i];
   }
   avg = sum / arraySize;

   return avg;
}

void remove(double array[], int &arraySize, int index) {
   for (int i = index + 1; i < arraySize; ++i) {
      array[i - 1] = array[i];
   }
   arraySize = arraySize - 1;
}

void display(const double array[], int arraySize) {
   for (int i = 0; i < arraySize; ++i) {
      cout << array[i];
      if (i < arraySize - 1) {
         cout << ", ";
      }
   }
}

