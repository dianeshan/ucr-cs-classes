#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile;
   string outputFile;
   int n;
   vector<int> myVec;
   
   // Assign to inputFile value of 2nd command line argument
   inputFile = argv[1];
   // Assign to outputFile value of 3rd command line argument
   outputFile = argv[2];   

   // Create input stream and open input csv file.
   ifstream inFS;
   inFS.open(inputFile);
   // Verify file opened correctly.
   if(!inFS.is_open()) {
       // Output error message and return 1 if file stream did not open correctly.
      cout << "Could not open file " << argv[1] << "." << endl;
      return 1;
   }
  
   // Read in integers from input file to vector.
   while(inFS >> n) {
      myVec.push_back(n);
      inFS.ignore();
   }
   // Close input stream.
   inFS.close();
   // Get integer average of all values read in.
   int sum = 0;
   int count = 0;
   int avg;
   for (unsigned int i = 0; i < myVec.size(); ++i) {
      sum = sum + myVec.at(i);
      ++count;
   }
   avg = sum / count;
   // Convert each value within vector to be the difference between the original value and the average.
   for (unsigned int i = 0; i < myVec.size(); ++i) {
      myVec.at(i) = myVec.at(i) - avg;
   }  
   // Create output stream and open/create output csv file.
   ofstream outFS;
   outFS.open(outputFile);
   // Verify file opened or was created correctly.
   if(!outFS.is_open()) {
      // Output error message and return 1 if file stream did not open correctly.
      cout << "Could not open file " << argv[2] << "." << endl;
      return 1;
   }
   // Write converted values into ouptut csv file, each integer separated by a comma.
   for (unsigned int i = 0; i < myVec.size() - 1; ++i) {
      outFS << myVec.at(i) << ",";
   }
   outFS << myVec.at(myVec.size() - 1) << endl;
   //as an alternative to moving the last value out of the loop include an if statement
   // for (unsigned int i = 0; i < myVec.size(); ++i) {
   //    outFS << myVec.at(i);
   //    if(i != myVec.size() - 1) {
   //       outFS << ",";
   //    }
   // }
   // outFS << endl;
   
   // Close output stream.
   outFS.close();
   
   return 0;
}