#include <iostream>
#include "dateType.h"
using namespace std;

int main() {
	dateType newDate(2, 29, 2000);
	//newDate.monthDays(1000, 2);
	//newDate.daysPassed(3, 12, 2017);
	//newDate.daysRemaining(3, 12, 2017);
	newDate.newDate(12, 11, 2018, 80);
	system("pause");
}