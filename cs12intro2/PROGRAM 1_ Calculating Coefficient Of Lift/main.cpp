#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void readData(const string &, vector<double> &, vector<double> &);
double interpolation(double, const vector<double> &, const vector<double> &);
bool isOrdered(const vector<double> &);
void reorder(vector<double> &, vector<double> &);

int main(int argc, char *argv[]) {

    string inputfile;
    string answer = " ";
    double userInput;
    double resultCoefLift;
    vector<double> flightAngles;
    vector<double> coefLifts;

    //get from command line the name of the file that contains the wind tunnel data
    inputfile = argv[1];

    //read data into two vectors
    readData(inputfile, flightAngles, coefLifts);

    while(answer != "No") {
        //ask user for flight-path angle
        cout << "Enter a flight-path angle: " << endl;
        cin >> userInput;

        //determine if angle is within bounds of data set
        //first make sure it is ordered and then compare to first and last value in vector
        if (isOrdered(flightAngles)) {
            if(userInput >= flightAngles.at(0) && userInput <= flightAngles.at(flightAngles.size() - 1)) {
                resultCoefLift = interpolation(userInput, flightAngles, coefLifts);
                cout << resultCoefLift << endl;
            }
        }
        else {
            //if not ordered call reorder function
            reorder(flightAngles, coefLifts);
            if(userInput >= flightAngles.at(0) && userInput <= flightAngles.at(flightAngles.size() - 1)) {
                //after ordering, call interpolation
                resultCoefLift = interpolation(userInput, flightAngles, coefLifts);
                cout << resultCoefLift << endl;
            }
        }

        //ask user if they want to enter another flight-path angle
        cout << "Do you want to enter another flight-path angle? Yes or No" << endl;
        cin >> answer;
    }

    return 0;
}

void readData(const string &filename, vector<double> &flightAngles, vector<double> &coefLifts) {
    
    double n;
    double m;
    ifstream inFS;
    inFS.open(filename);

    //check to see if file opened correctly
    if (!inFS.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(1);
    }

    //stores data into two parallel vectors
    while (inFS >> n >> m) {
        flightAngles.push_back(n); //stores flightangles into first vector
        coefLifts.push_back(m); //stores coefficients of lift into second vector
    }

    inFS.close();
}

double interpolation(double b, const vector<double> &flightAngles, const vector<double> &coefLifts) {
    
    double aa;
    double a;
    double cc;
    double c;
    double resultLift;

    for (unsigned int i = 0; i < flightAngles.size() - 1; ++i) {
        if (b >= flightAngles.at(i) && b <= flightAngles.at(i + 1)) {
            a = flightAngles.at(i);
            aa = coefLifts.at(i);
            c = flightAngles.at(i + 1);
            cc = coefLifts.at(i + 1);
            resultLift = aa + ((b - a)/(c - a)) * (cc - aa);
            return resultLift;
        }
    }
    return 0.0;
}

bool isOrdered(const vector<double> &flightAngles) {

    for (unsigned int i = 0; i + 1 < flightAngles.size(); ++i) {
        if (flightAngles.at(i) > flightAngles.at(i + 1)) {
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &flightAngles, vector<double> &coefLifts) {
    int first;
    unsigned int j;
    unsigned int i;

    for (i = 0; i < flightAngles.size(); ++i) {
        first = i;
        for (j = i + 1; j < flightAngles.size(); ++j) {
            if (flightAngles.at(j) < flightAngles.at(first)) {
               first = j;
            }
        }
        swap(flightAngles.at(i), flightAngles.at(first));
        swap(coefLifts.at(i), coefLifts.at(first));
    }
}


