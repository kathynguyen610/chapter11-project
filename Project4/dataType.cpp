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
		cout << "The date is " << month << ", " << day << ", " << year << ". This is a valid date." << endl;
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
	//cout << "Please enter a month: ";
	//cin >> month;
	//cout << "Please enter a day: ";
	//cin >> day;
	//cout << "Please enter a year: ";
	//cin >> year;
	setDate(month, day, year);
}

//getting the day, month, and year
int dateType::getDay() const {
	return dDay;
}
int dateType::getMonth() const {
	return dMonth;
}
int dateType::getYear() const {
	return dYear;
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
int dateType::monthDays(int year, int month) {
	//default day is 31
	int leapDay = 28;
	int day = 31;
	if (isLeapYear(year) == true) {
		leapDay = 29;
	}
	//sets the days of the month
	if (month > 0 && month < 13) {
		switch (month) {
		case 2:
			day = leapDay;
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
	}
	else {
		cout << month;
		cout << "Not a valid month." << endl;
	}
	return day;
}
//calculates how many days have passed with the month, day, and year
int dateType::daysPassed(int month, int days, int year){
	int totDays = 0;
	//takes the value and adds together the days for each month
	for (int i = 1; i < month; i++) {
		totDays += monthDays(year, i);
	}
	//adding in remaining days
	days = totDays + days;
	return days;
}
//calculates how many days are remaining after a certain date
int dateType::daysRemaining(int month, int days, int year){
	int daysInYear = 0;

	if (isLeapYear(year) == false) {
		daysInYear = 365;
	}
	else {
		daysInYear = 366;
	}
	return(daysInYear - daysPassed(month, days, year));
}

//calculates new date based on how many days specified
int dateType::newDate(int month, int days, int year, int addedDays) {
	int i = 0;
	for (i = addedDays; i > 0; i--) {
		days++;
		if (days > monthDays(year, month)) {
			days = 1;
			if (month >= 12) {
				year++;
				month = 1;
				days = 1;
			}
			else {
				month++;
			}
		}
	}
	cout << "Month: " << month << endl;
	cout << "Day: " << days << endl;
	cout << "Year: " << year << endl;
	return 0;
}
