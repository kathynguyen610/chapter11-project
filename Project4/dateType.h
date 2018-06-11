#ifndef dateType_H
#define dateType_H

class dateType {
public: 
	void setDate(int month, int day, int year);
	//Function to set the date.
	//The member variables dMonth, dDay, and dYear are set according to the parameters
	//Postcondition: dMonth = month; dDay = day; dYear = year

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	bool isLeapYear(int);
	int monthDays(int, int);
	int daysPassed(int, int, int);
	int daysRemaining(int, int, int);
	void printDate()const;
	dateType(int month = 0, int day = 0, int year = 0);

private:
	int dMonth;
	int dDay;
	int dYear;

};

#endif