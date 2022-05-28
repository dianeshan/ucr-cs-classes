#include <iostream>
using namespace std;

int main(){
  int trunkHeight;
  int trunkWidth;
  int i;
  int j;
  //specify number of trunk levels & get input from user
  cout << "Enter trunk height: " << endl;
  cin >> trunkHeight;
  //specify width of tree trunk
  cout << "Enter trunk width: " << endl;
  cin >> trunkWidth;
  //only accept odd numbers for the trunkWidth
  while ((trunkWidth % 2) == 0) {
    cout << "Please enter an odd number for the width: ";
    cin >> trunkWidth;
    cout << endl;
  }
  // Draw Leaves
  cout << "  *"   << endl;
  cout << " ***"  << endl;
  cout << "*****" << endl;

  //Draw trunk
  //use loop to draw that many levels
  //use loop to draw width the number of asterisks in each level
  for (i = 1; i <= trunkHeight; ++i) {
    cout << " ";
    for (j = 1; j <= trunkWidth; ++j){
      cout << "*";
    }
    cout << endl;
  }

  // cout << " ***" << endl;
  // cout << " ***" << endl;
  // cout << " ***" << endl;
  // cout << " ***" << endl;


  return 0;
}
