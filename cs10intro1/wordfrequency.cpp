#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Define your function here */
//to get the frequency of the word
int GetFrequencyOfWord(vector<string> wordsList, string currWord) {
   unsigned int i;
   int count=0;

   for (i = 0; i < wordsList.size(); ++i) {
      if (wordsList.at(i) == currWord) {
         count = count + 1;
      }
   }

   return count;
}


int main() {
   /* Type your code here */
   int numInput;
   string currWord;
   unsigned int i;

   cin >> numInput;

   vector<string> wordsList(numInput);
   vector<int> frequencyList(numInput);

   for (i = 0; i < wordsList.size(); ++i) {
      cin >> wordsList.at(i);
   }

   for (i = 0; i < frequencyList.size(); ++i){
      frequencyList.at(i) = GetFrequencyOfWord(wordsList, wordsList.at(i));
      cout << wordsList.at(i) << " " << frequencyList.at(i) << endl;
   }


   return 0;
}
