#include <iostream>
using namespace std;

int main(){
  int trunkHeight;
  int trunkWidth;
  int trunkMid;
  int leavesWidth;
  int leavesHeight;
  int i;
  int j;
  int k;
  int l;

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
  //specify number of tree leaves levels
  cout << "Enter leaves width: " << endl;
  cin >> leavesWidth;
  //only accept odd numbers for the leavesWidth
  while ((leavesWidth % 2) == 0) {
    cout << "Please enter an odd number for the width: ";
    cin >> leavesWidth;
    cout << endl;
  }
  // Draw Leaves
  //use loop to draw levels of leaves so one for the asterisks and one for the spaces
  //need to print out spaces before the asterisks
  //leavesWidth/2 + 1 equals the height of the leaves of tree
  leavesHeight = leavesWidth/2 + 1;
  for (i = 0; i < leavesHeight; ++i) {
    for (l = 1; l <= leavesWidth/2 - i; ++l) {
      cout << " ";
    }
    for (j = 0; j <= i; ++j) {
      cout << "*";
    }
    for (k = 0; k < i; ++k) {
      cout << "*";
    }
    cout << endl;
  }

  // cout << "  *"   << endl;
  // cout << " ***"  << endl;
  // cout << "*****" << endl;

  //move the trunk so it's in the middle of the leaves
  if (leavesWidth > trunkWidth) {
    trunkMid = ((leavesWidth - trunkWidth)/2);
  }

  //Draw trunk
  //use loop to draw that many levels
  //use loop to draw width the number of asterisks in each level
  for (i = 1; i <= trunkHeight; ++i) {
    for (l = 1; l <= trunkMid; ++l) {
      cout << " ";
    }
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
