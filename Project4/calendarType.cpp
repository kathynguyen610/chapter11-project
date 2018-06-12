#include <iostream>
#include <string>
#include "calendarType.h"

using namespace std;

//constructor
calendarType::calendarType(int month, int year){
	setMonth(month);
	setYear(year);
}

//setters
void calendarType::setMonth(int month) {
	calExtDate.setMonth(month);
}

void calendarType::setYear(int year) {
	calExtDate.setYear(year);
}

//calculates the first day of the year, then it calculates the first day of the month
int calendarType::firstDayOfMonth(int month, int year) {
	int numOfYears = year - 1500;
	int weekDay = 1; //monday is number 1
	int amountOfDays = calDate.daysPassed(month, 1, year) - 1;


	//calculates the first day depending on year
	if (year == 1500) {
		weekDay = 1;
	}
	//if the year is greater than 1500
	else if (year > 1500) {
		year = 1500; //set year to 1500 to check if it's a leap year
		for (int i = numOfYears; i > 0; i--) {
			if (calDate.isLeapYear(year) == true) {
				//if it's a leap year, days move forward by 2
				if (weekDay == 6) {
					weekDay = 1; 
				}
				else if (weekDay == 5) {
					weekDay = 0;
				}
				else {
					weekDay+=2;
				}
			}
			else {
				if (weekDay == 6) {
					weekDay = 0;
				}
				else {
					weekDay++;
				}
			}
			year++;
		}
	}
	//if the year is less than 1500
	else {
		for (int i = numOfYears; i < 0; i++) {
			if (calDate.isLeapYear(year) == true) {
				//if it's a leap year, days move back by 2
				if (weekDay == 1) {
					weekDay = 6;
				}
				else if (weekDay == 0) {
					weekDay = 5; 
				}
				else {
					weekDay -= 2;
				}
			}
			else {
				if (weekDay == 0) {
					weekDay = 6;
				}
				else {
					weekDay--;
				}
			}
			year--;
		}
	}
	//calculating the first day of month
	for (int i = 0; i < amountOfDays; i++) {
		if (weekDay == 6) {
			weekDay = 0;
		}
		else {
			weekDay++;
		}
	}
	return weekDay;
}


//this function prints out a calendar using the first day and month calculations
void calendarType::print(int month, int year){
	int weekDay = firstDayOfMonth(month, year);
	calExtDate.strMonth(month, year);
	//prints the days of the month
	cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;
	
	//prints the spaces before the month starts
	for (int i = 0; i < weekDay; i++) {
		cout << "    ";
	}

	//prints the days of the month
	for (int i = 1; i < calDate.monthDays(year, month) + 1; i++) {
		if (weekDay == 6) {
			cout << i << endl;
			weekDay = 0;
		}
		else {
			//if the days are two digits, add one less space
			if (i > 9) {
				cout << " " << i << " ";
				weekDay++;
			}
			else {
				cout << " " << i << "  ";
				weekDay++;
			}
		}
	}
	cout << endl;
}
