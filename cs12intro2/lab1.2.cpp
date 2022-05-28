#include <iostream>
#include <vector>

using namespace std;

// parameter order will always be jersey #s then ratings
void outputRoster(const vector<int> &jerseyNumber, const vector<int> &rating);
void addPlayer(vector<int> &jerseyNumber, vector<int> &rating);
void removePlayer(vector<int> &jerseyNumber, vector<int> &rating);
void updatePlayerRating(const vector<int> &jerseyNumber, vector<int> &rating);
void outputPlayersAboveRating(const vector<int> &jerseyNumber, const vector<int> &rating);


int main() {

   /* Type your code here. */
   vector<int> jerseyNumber(5);
   vector<int> rating(5);
   int num;
   int rate;
   char option;
   
   for (unsigned int i = 0; i < jerseyNumber.size(); ++i) {
      cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
      cin >> num;
      jerseyNumber.at(i) = num;
      cout << "Enter player " << i + 1 << "'s rating:" << endl;
      cin >> rate;
      rating.at(i) = rate;
      cout << endl;
   }
   
   outputRoster(jerseyNumber, rating);
   
   cout << endl;
   cout << "MENU" << endl;
   cout << "a - Add player" << endl;
   cout << "d - Remove player" << endl;
   cout << "u - Update player rating" << endl;
   cout << "r - Output players above a rating" << endl;
   cout << "o - Output roster" << endl;
   cout << "q - Quit" << endl;
   
   cout << endl;
   cout << "Choose an option:" << endl;
   cin >> option;
   
   while (option != 'q') {
      if (option == 'a') {
         addPlayer(jerseyNumber, rating);
      }
      else if (option == 'd') {
         removePlayer(jerseyNumber, rating);
      }
      else if (option == 'u') {
         updatePlayerRating(jerseyNumber, rating);
      }
      else if (option == 'r') {
         outputPlayersAboveRating(jerseyNumber, rating);
      }
      else if (option == 'o') {
         outputRoster(jerseyNumber, rating);
      }
      
      cout << endl;
      cout << "MENU" << endl;
      cout << "a - Add player" << endl;
      cout << "d - Remove player" << endl;
      cout << "u - Update player rating" << endl;
      cout << "r - Output players above a rating" << endl;
      cout << "o - Output roster" << endl;
      cout << "q - Quit" << endl;
      
      cout << endl;
      cout << "Choose an option:" << endl;
      cin >> option;
   }

   return 0;
}

void outputRoster(const vector<int> &jerseyNumber, const vector<int> &rating) {
   cout << "ROSTER" << endl;
   for (unsigned int i = 0; i < jerseyNumber.size(); ++i) {
      cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumber.at(i) << ", Rating: " << rating.at(i) << endl;
   }
}

void addPlayer(vector<int> &jerseyNumber, vector<int> &rating) {
   int num;
   int rate;

   cout << "Enter another player's jersey number:" << endl;
   cin >> num;
   cout << "Enter another player's rating:" << endl;
   cin >> rate;
   jerseyNumber.push_back(num);
   rating.push_back(rate);
}

void removePlayer(vector<int> &jerseyNumber, vector<int> &rating) {
   int num;

   cout << "Enter a jersey number:" << endl;
   cin >> num;
   unsigned int indexToDelete = jerseyNumber.size();

   for (unsigned int i = 0; i < jerseyNumber.size(); ++i) {
      if (num == jerseyNumber.at(i)) {
         indexToDelete = i;
      }
   }
   
   if (indexToDelete >= 0 && indexToDelete < jerseyNumber.size()) {
      for (unsigned int i = indexToDelete; i + 1 < jerseyNumber.size(); ++i) {
         jerseyNumber.at(i) = jerseyNumber.at(i+1);
         rating.at(i) = rating.at(i+1);
      }
      
      jerseyNumber.pop_back();
      rating.pop_back();
   }
}

void updatePlayerRating(const vector<int> &jerseyNumber, vector<int> &rating) {
   int num;
   int newRate;

   cout << "Enter a jersey number:" << endl;
   cin >> num;
   cout << "Enter a new rating for player:" << endl;
   cin >> newRate;
      
   for (unsigned int i = 0; i < jerseyNumber.size(); ++i) {
      if (jerseyNumber.at(i) == num) {
         rating.at(i) = newRate;
      }
   }
}
   
void outputPlayersAboveRating(const vector<int> &jerseyNumber, const vector<int> &rating) {
   int rate;

   cout << "Enter a rating:" << endl;
   cin >> rate;
   cout << endl;
   
   cout << "ABOVE " << rate << endl;
   for (unsigned int i = 0; i < jerseyNumber.size(); ++i) {
      if (rating.at(i) > rate) {
         cout << "Player " << i + 1 << " -- Jersey number: " << jerseyNumber.at(i) << ", Rating: " << rating.at(i) << endl;
      }
   }
}

//code for rand number
int getRand(int small, int large) {
   return small + rand() % (large - small + 1);
}
   