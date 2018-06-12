#include <iostream>
#include <string>
#include "extDateType.h"

using namespace std;

//constructor
extDateType::extDateType(int month, int day, int yr):dateType(month, day, yr) {
	return;
}

//switches the numerical gvalue of a month and puts in the string value, and prints out the month + year
std::string extDateType::strMonth(int month, int year){
	extMonth = "";
		if(month > 0 && month < 13){
			switch (month) {
			case 1:
				extMonth = "January";
				break;
			case 2:
				extMonth = "Feburary";
				break;
			case 3:
				extMonth = "March";
				break;
			case 4:
				extMonth = "April";
				break;
			case 5:
				extMonth = "May";
				break;
			case 6:
				extMonth = "June";
				break;
			case 7:
				extMonth = "July";
				break;
			case 8:
				extMonth = "August";
				break;
			case 9:
				extMonth = "September";
				break;
			case 10:
				extMonth = "October";
				break;
			case 11:
				extMonth = "November";
				break;
			case 12:
				extMonth = "December";
				break;
		}
	}
		cout << extMonth << " " << year << endl;
		return extMonth;
}
