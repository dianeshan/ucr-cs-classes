#include <iostream>
#include <vector>

using namespace std;
unsigned int i;

// double findMaxAngle(const vector<double> &);
// double findMinAngle(const vector<double> &);

bool isOrdered(const vector<double> &flightAngles) {

    for (i = 0; i < flightAngles.size() - 1; ++i) {
        if (flightAngles.at(i) > flightAngles.at(i + 1)) {
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &flightAngles, vector<double> &coefLifts) {
    int smallest;
    int temp;
    int temp2;

    for (unsigned int i = 0; i < flightAngles.size(); ++i) {
        smallest = i;
        for (unsigned int j = i + 1; j < flightAngles.size(); ++j) {
            if (flightAngles.at(j) < flightAngles.at(smallest)) {
               temp = flightAngles.at(smallest);
               flightAngles.at(smallest) = flightAngles.at(j);
               flightAngles.at(j) = temp;
               temp2 = coefLifts.at(smallest);
               coefLifts.at(smallest) = coefLifts.at(j);
               coefLifts.at(j) = temp2;
            }
        }
    }

}

int main() {
   /* Type your code here */
    int numInput;
   
    cin >> numInput;
   
    vector<double> jackSmart(numInput);
    vector<double> coefLifts(numInput);
   
    cout << "Enter values for first vector: " << endl;
    for (i = 0; i < jackSmart.size(); ++i) {
       cin >> jackSmart.at(i);
    }

    cout << "Enter values for second vector: " << endl;
    for (i = 0; i < coefLifts.size(); ++i) {
       cin >> coefLifts.at(i);
    }

    if(isOrdered(jackSmart)) {
        for (i = 0; i < jackSmart.size(); ++i) {
            cout << jackSmart.at(i) << " " << coefLifts.at(i) << endl;
        }
    }
    else {
        reorder(jackSmart, coefLifts);
            for (i = 0; i < jackSmart.size(); ++i) {
                cout << jackSmart.at(i) << " " << coefLifts.at(i) << endl;
            }
        cout << "We reordered" << endl;
    }

   return 0;
}

// double findMaxAngle(const vector<double> &flightAngles) {
//     double max = flightAngles.at(0);

//     for (unsigned int i = 1; i < flightAngles.size(); ++i) {
//         if (flightAngles.at(i) > max) {
//             max = flightAngles.at(i);
//         }
//     }

//     return max;
// }

// double findMinAngle(const vector<double> &flightAngles) {
//     double min = flightAngles.at(0);

//     for (unsigned int i = 1; i < flightAngles.size(); ++i) {
//         if (flightAngles.at(i) < min) {
//             min = flightAngles.at(i);
//         }
//     }

//     return min;
// }
