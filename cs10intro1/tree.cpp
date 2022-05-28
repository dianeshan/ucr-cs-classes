#include <iostream>
using namespace std;

int main(){
  int trunkHeight;
  int i;
  //specify number of trunk levels & get input from user
  cout << "Enter trunk height: " << endl;
  cin >> trunkHeight;
  // Draw Leaves
  cout << "  *"   << endl;
  cout << " ***"  << endl;
  cout << "*****" << endl;

  //Draw trunk
  //use loop to draw that many levels

  for (i = 1; i <= trunkHeight; ++i) {
    cout << " ***" << endl;
  }

  // cout << " ***" << endl;
  // cout << " ***" << endl;
  // cout << " ***" << endl;
  // cout << " ***" << endl;


  return 0;
}
