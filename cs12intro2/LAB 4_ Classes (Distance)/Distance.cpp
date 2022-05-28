#include <iostream>
using namespace std;

#include "Distance.h"

Distance::Distance() {
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;

    init();
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;

    init();
}

unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    return (feet * 12) + inches;
}

double Distance::distanceInFeet() const {
    return feet + (inches/12);
}

double Distance::distanceInMeters() const {
    double totInches;

    totInches = (feet * 12) + inches;

    return totInches * 0.0254;
}

Distance Distance::operator+(const Distance &rhs) const {
    Distance sumOfDist;

    sumOfDist.feet = feet + rhs.feet;
    sumOfDist.inches = inches + rhs.inches;

    if (sumOfDist.feet < 0) {
        sumOfDist.feet = sumOfDist.feet * -1;
    }

    if (sumOfDist.inches < 0) {
        sumOfDist.inches = sumOfDist.inches * -1;
    } 

    if (sumOfDist.inches >= 12) {
        unsigned int addedFt;
        addedFt = sumOfDist.inches / 12;
        sumOfDist.feet = sumOfDist.feet + addedFt;
        sumOfDist.inches = sumOfDist.inches - (12 * addedFt);
    }

    return sumOfDist;
}

Distance Distance::operator-(const Distance &rhs) const {
    Distance diffOfDist;

    if (feet < rhs.feet && inches < rhs.inches) {
        diffOfDist.feet = rhs.feet - feet;
        diffOfDist.inches = rhs.inches - inches;
    }
    else if (feet < rhs.feet && inches > rhs.inches) {
        diffOfDist.feet = (rhs.feet - 1) - feet;
        diffOfDist.inches = (rhs.inches + 12) - inches;
    }
    else if (feet > rhs.feet && inches < rhs.inches){
        diffOfDist.feet = (feet - 1) - rhs.feet;
        diffOfDist.inches = (inches + 12) - rhs.inches;
    }
    else {
        diffOfDist.feet = feet - rhs.feet;
        diffOfDist.inches = inches - rhs.inches;
    }

    if (diffOfDist.feet < 0) {
        diffOfDist.feet = diffOfDist.feet * -1;
    }

    if (diffOfDist.inches < 0) {
        diffOfDist.inches = diffOfDist.inches * -1;
    } 

    return diffOfDist;
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs.feet << "' " << rhs.inches << "\""; 
    return out;
}

void Distance::init() {
    unsigned int newFt = 0;

    if (inches < 0) {
        inches = inches * -1;
    }

    if (inches >= 12) {
        newFt = inches / 12;
    }

    feet = feet + newFt;
    inches = inches - (12 * newFt);
}
