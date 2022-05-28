#include <iostream>
#include <vector>
using namespace std;

int CountCapitals (vector<string>& reee) {
    int count = 0;
    unsigned int i;

    for (i = 0; i < reee.size(); ++i) {
        if (reee.at(i).at(0) >= 65 && reee.at(i).at(0) <= 96) {
            ++count;
        }
    }

    return count;
}

void CapitalizeStrings (vector<string>& dome) {
    unsigned int i;

    for (i = 0; i < dome.size(); ++i) {
        if (dome.at(i).at(0) >= 97) {
            dome.at(i).at(0) = dome.at(i).at(0) - 32;
        }
    }
}

int main() {
    unsigned int i;
    int ogNum;
    int newNum;
    vector<string> pengu(5);

    for (i = 0; i < pengu.size(); ++i) {
        cin >> pengu.at(i);
    }
    
    ogNum = pengu.size() - CountCapitals (pengu);
    cout << ogNum << endl;

    CapitalizeStrings (pengu);

    newNum = pengu.size() - CountCapitals (pengu);
    cout << newNum << endl;

    return 0;
}