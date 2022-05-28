#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

//* next to it means done
//default constructor *
Date::Date() {
   month = 1;
   day = 1;
   year = 2000;
   monthName = "January";
} 

//month number, day, year constructor *
Date::Date(unsigned m, unsigned d, unsigned y) {
   month = m;
   day = d;
   year = y;

   if (month > 12 && day > 31) {
      month = 12;
      day = 31;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (month > 12 && day <= 0) {
      month = 12;
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (month > 12) {
      month = 12;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (month <= 0 && day <= 0) {
      month = 1;
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (month <= 0 && day > 31) {
      month = 1;
      day = 31;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (month <= 0) {
      month = 1;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (day <= 0) {
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else {
      if (daysPerMonth(month, year) < day) {
      day = daysPerMonth(month, year);
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
   }

   monthName = name(month);

} 

//month name, day, year constructor
Date::Date(const string &mn, unsigned d, unsigned y) {
   monthName = mn;
   day = d;
   year = y; 
   month = number(monthName);

   //check to see if correct month
   if (monthName == "january") {
      monthName = "January";
   }
   else if (monthName == "february") {
      monthName = "February";
   }
   else if (monthName == "march") {
      monthName = "March";
   }
   else if (monthName == "april") {
      monthName = "April";
   }
   else if (monthName == "may") {
      monthName = "May";
   }
   else if (monthName == "june") {
      monthName = "June";
   }
   else if (monthName == "july") {
      monthName = "July";
   }
   else if (monthName == "august") {
      monthName = "August";
   }
   else if (monthName == "september") {
      monthName = "September";
   }
   else if (monthName == "october") {
      monthName = "October";
   }
   else if (monthName == "november") {
      monthName = "November";
   }
   else if (monthName == "december") {
      monthName = "December";
   } 

   if (monthName != "January" && monthName != "February" && monthName != "March" && monthName != "April" && monthName != "May" && monthName != "June" && monthName != "July" && monthName != "August" && monthName != "September" && monthName != "October" && monthName != "November" && monthName != "December") {
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
      month = 1;
      day = 1;
      year = 2000;
      monthName = "January";
   }
 
   if (day > 31) {
      day = 31;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (day <= 0) {
      day = 1;
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }
   else if (daysPerMonth(month, year) < day) {
      day = daysPerMonth(month, year);
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }

  

}

//output numeric date *
void Date::printNumeric() const {
   cout << month << "/" << day << "/" << year; 
 }

//output alphabetic date *
void Date::printAlpha() const {
   cout << monthName << " " << day << ", " << year; 
}

//determine if year is leap year *
bool Date::isLeap(unsigned y) const {

   if (y % 400 == 0) {
      return true;
   }
   else if (y % 100 == 0) {
      return false;
   }
   else if (y % 4 == 0) {
      return true;
   }

   return false;
}

//returns number of days allowed in a month *
unsigned Date::daysPerMonth(unsigned m, unsigned y) const {
   if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
      return 31;
   }
   else if (m == 4 || m == 6 || m == 9 || m == 11) {
      return 30;
   }
   else {
      if (isLeap(y)) {
         return 29;
      }
      else {
         return 28;
      }
   }
}

//returns name of month *
string Date::name(unsigned m) const {
   string monthName;

   if (m == 1) {
      monthName = "January";
   }
   else if (m == 2) {
      monthName = "February";
   }
   else if (m == 3) {
      monthName = "March";
   }
   else if (m == 4) {
      monthName = "April";
   }
   else if (m == 5) {
      monthName = "May";
   }
   else if (m == 6) {
      monthName = "June";
   }
   else if (m == 7) {
      monthName = "July";
   }
   else if (m == 8) {
      monthName = "August";
   }
   else if (m == 9) {
      monthName = "September";
   }
   else if (m == 10) {
      monthName = "October";
   }
   else if (m == 11) {
      monthName = "November";
   }
   else if (m == 12) {
      monthName = "December";
   } 

   return monthName;
}

//returns number of month *
unsigned Date::number(const string &mn) const {
   int month = 0;

   if (mn == "January" || mn == "january") {
      month = 1;
   }
   else if (mn == "February" || mn == "february") {
      month = 2;
   }
   else if (mn == "March" || mn == "march") {
      month = 3;
   }
   else if (mn == "April" || mn == "april") {
      month = 4;
   }
   else if (mn == "May" || mn == "may") {
      month = 5;
   }
   else if (mn == "June" || mn == "june") {
      month = 6;
   }
   else if (mn == "July" || mn == "july") {
      month = 7;
   }
   else if (mn == "August" || mn == "august") {
      month = 8;
   }
   else if (mn == "September" || mn == "september") {
      month = 9;
   }
   else if (mn == "October" || mn == "october") {
      month = 10;
   }
   else if (mn == "November" || mn == "november") {
      month = 11;
   }
   else if (mn == "December" || mn == "december") {
      month = 12;
   } 

   return month;
}



// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}

// monthName == "january" && monthName == "february" && monthName == "march" && monthName == "april" && monthName == "may" && monthName == "june" && monthName == "july" && monthName == "august" && monthName == "september" && monthName == "october" && monthName == "november" && monthName == "december"
