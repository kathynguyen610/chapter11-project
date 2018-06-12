

#ifndef exDateType_H
#define exDateType_H
#include "dateType.h"
class extDateType:public dateType {
public:
	extDateType(int month = 0, int day = 0, int year = 0);
	void setDate(int month, int day, int year);
	std::string extMonth;
	std::string strMonth(int month, int year);
};

#endif