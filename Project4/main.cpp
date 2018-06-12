#include <iostream>
#include <string>
#include "calendarType.h"

using namespace std;
int main() {
	//dateType newDate(2, 29, 2000);
	//newDate.daysRemaining(3, 12, 2017);
	//newDate.newDate(12, 11, 2018, 80);
	//extDateType date(2, 29, 2000);
	//date.strMonth(2, 1000);
	//otherDate.setDate(12, 11, 30);


	calendarType calendar(1, 1502);
	calendar.firstDayOfMonth(9, 2017);
	calendar.print(9, 1500);
	system("pause");
}
