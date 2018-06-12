#ifndef calendarType_H
#define calendarType_H
#include "dateType.h"
#include "extDateType.h"
class calendarType{
public:
	void setMonth(int);
	void setYear(int);
	int getMonth();
	int getYear();
	void printCal(int, int);
	calendarType();
	calendarType(int, int);
	int firstDayOfMonth(int, int);
	void print(int, int);
private:
	extDateType calExtDate;
	dateType calDate;
};

#endif