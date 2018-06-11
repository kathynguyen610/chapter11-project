#include <iostream>
#include "dateType.h"

using namespace std;
void dateType::setDate(int month, int day, int year) {
	bool valid = false; //default validity is false
	int MaxDays = 31; //the max days in a month unless said otherwise
	int leapDay = 28; 

	//if the year is a leap year, then the leapday is 29. 
	if (isLeapYear(year) == true) {
		leapDay = 29; 
	}


	//if statements checking if the date is valid. if it is valid, then it moves to the next check.
	if (year >= 0) {
		if (month >= 1 && month <= 12) {
			if (day <= MaxDays) {
				valid = true;

				//if the date fulfills the requirements, it's true unless said otherwise for certain months.
				switch (month) {
				case 2: if (day > leapDay)
					valid = false;
					break;
				case 4: if (day > 30)
					valid = false;
					break;
				case 6: if (day > 30)
					valid = false;
					break;
				case 8: if (day > 30)
					valid = false;
					break;
				case 11: if (day > 30)
					valid = false;
					break;
				}
			}
		}
	}
	if (valid == true) {
		cout << "This is a valid date." << endl;
		dMonth = month;
		dDay = day;
		dYear = year;
	}
	else {
		cout << "This is not a valid date." << endl;
		dMonth = 0;
		dDay = 0;
		dYear = 0;
	}
}
dateType::dateType(int month, int day, int year) {
	cout << "Please enter a month: ";
	cin >> month;
	cout << "Please enter a day: ";
	cin >> day;
	cout << "Please enter a year: ";
	cin >> year;
	setDate(month, day, year);
}


bool dateType::isLeapYear(int year) {
	//if the year is devisible by 100 and 4, it also has to be divisible by 400 to be a leap year
	//for example, 2000 is a leap year but 1700 is not
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) {
		return true;
	}
	//if the year is divisible by 4 but not 100, it's a leap year ex. 2004
	else  if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else {
		return false;
	}
}

//This checks how many days are in a month and returns the amount.
int dateType::monthDays() const {
	//default day is 31
	int month = 0;
	int day = 31;
	cout << "Please enter a month: ";
	cin >> month;
	//sets the days of the month
	if (month > 0 && month < 13) {
		switch (month) {
		case 2:
			day = 28;
			break;
		case 4:
			day = 30;
			break;
		case 6:
			day = 30;
			break;
		case 9:
			day = 30;
			break;
		case 11:
			day = 30;
			break;
		}
		cout << "There are " << day << " days in month " << month << endl;
	}
	else {
		cout << "You have not entered a valid month." << endl;
	}
	return day;
}

int dateType::getDay() const {
	return dDay;
}
int dateType::getMonth() const {
	return dMonth;
}
int dateType::getYear() const {
	return dYear;
}
