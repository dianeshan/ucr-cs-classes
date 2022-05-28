#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

//#2
int main() {
    int userInput;
    int product = 1;
    int count = 0;
    int endNum;

    cin >> userInput;

    while (userInput != 0) {
        product = product * userInput;
        count = count + 1;
        cin >> userInput;
    }

    endNum = product / count;

    cout << endNum << endl; 

    return 0;
}

//#3 
//Write a function that finds the min of three ints that are parameters of the function. 
// The function also has a fourth parameter representing a lower boundary (also int).  
// If the lower boundary parameter value is below 10, the function should use 10 as the lower boundary.   
// If the min of the first three int parameters is below the lower boundary, 
// the program should return the lower boundary.  
// If the min is above the lower boundary, the program should return the min. 
// For example, if the function arguments are 2 6 4 10, the function returns 10. 
// If the function arguments are 20 60 40 10, the function returns 20. 
// If the function arguments are 2 3 4 3, the function returns 10.  
int findMinBound (int a, int b, int c, int lowBound) {
    int finalMin;
    int minVal;

    if (a <= b && a <= c) {
        minVal = a;
    }
    else if (b <= a && b <= c) {
        minVal = b;
    }
    else {
        minVal = c;
    }

    if (lowBound < 10) {
        lowBound = 10;
    }

    if (minVal <= lowBound) {
        finalMin = lowBound;
    }
    else if (minVal > lowBound) {
        finalMin = minVal;
    }

    return finalMin;
}

// #4
// Define a function FindLocation() that passes in an int vector parameter and an int parameter. 
// The function should return an int representing the index of the first occurrence of the second parameter 
// in the vector.  For example, if the vector parameter is 3 9 6 7 9 6 and the int parameter is 9, 
// the function returns 1 (the index of the first instance of 9 found). 
// The function should return -1 if the int parameter is not found within the vector parameter. 
// You can assume the vector has at least one element. 
// You should assume the vector could have a very large number of elements. 
int FindLocation (vector<int>& penguin, int dome) {
    unsigned int i;
    for (i = 0; i < penguin.size(); ++i) {
        if (penguin.at(i) == dome) {
            return i;
        }
    }

    return -1;
}

// #6
// Write a function with one input parameter that is a vector of strings. 
// The function should replace the first lower case ‘a’ character in each string with an ‘@’ character 
// and return the number of 'a' characters replaced.

// For example, when the function is called, if the vector argument contains the 6 string values,
// "enter", "exit", "zebra", "tiger", "pizza", "caseload"
// the function should return a count of 3 and the vector should now be
// 	            “enter”, “exit”, “zebr@”, “tiger”, “pizz@”, “c@seload”
// ("zebra", "pizza", and "caseload" all have an ‘a’ character that was replaced)

// You may assume all letters in the vector of strings are lowercase.  You may use .find, .size, and .at.
int findSomeAs(vector<string>& softBall) {
    unsigned int i;
    unsigned int j;
    int count = 0;

    for (i = 0; i < softBall.size(); ++i) {
        for (j = 0; j < softBall.at(i).size(); ++j) {
            if (softBall.at(i).at(j) == 'a') {
                softBall.at(i).at(j) = '@'
                count = count + 1;
                break;
            }
        }
    }

    return count;
}
