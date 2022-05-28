#include <iostream>
#include <string>

using namespace std;

// void flipString(string &s, int i = 0);
void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

// Implement the flipString function here
void flipString(string &s) {
   if (s.size() <= 1) {
      return;
   }
   string t;
   swap(s.at(0), s.at(s.size() - 1));
   t = s.substr(1, s.size() - 2);   
   flipString(t);
   s = s.back() + t + s.front();  
}

// void flipString(string &s, int i) { 
//    int n = s.size(); 
//    if (n / 2 == i) {
//       return; 
//    }
//    else {
//       char temp;
//       temp = s.at(i);
//       s.at(i) = s.at(n - i - 1);
//       s.at(n - i - 1) = temp;
//       flipString(s, i + 1); 
//    }
// } 
