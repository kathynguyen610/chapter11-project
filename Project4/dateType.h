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
	int monthDays() const;
	void printDate()const;
	dateType(int month = 0, int day = 1, int year = 2000);

private:
	int dMonth;
	int dDay;
	int dYear;

};

#endif