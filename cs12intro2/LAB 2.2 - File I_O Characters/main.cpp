#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

// Place charCnt prototype (declaration) here
int charCnt(const string& filename, const char c);


int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

// Place charCnt implementation here
int charCnt(const string& filename, const char c) {
   ifstream inFS;
   int count = 0;
   char chFromFile;

   inFS.open(filename);

   if (!inFS.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(1);
   }

   inFS.get(chFromFile);

   while (!inFS.fail()) {
      if (chFromFile == c) {
         ++count;
      }
      inFS.get(chFromFile);
   }

   inFS.close();

   return count;

}
