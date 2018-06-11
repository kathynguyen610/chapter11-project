#include <iostream>
#include "dateType.h"
using namespace std;

int main() {
	dateType newDate(2, 29, 2000);
	//newDate.monthDays(1000, 2);
	newDate.daysRemaining(3, 18, 2017);
	system("pause");
}