/*
Name: Makayla Anderson-Tucker
Assignment: 3-1 Project 1
*/

#include <iostream>
#include <string>
#include <ctime>
#include <time.h>

void display12hours();
void display24hours();

int main() {

	// This text will display a 12 hour clock and a 23 hour clock.
	std::cout << "\t*************************         *************************\n";
	std::cout << "\t      12 hour clock                      24 hour clock\n";
	std::cout << "\t       ";
	display12hours();
	std::cout << "\t                    ";
	display24hours();
	std::cout << " \n";
	std::cout << "\t*************************         *************************\n\n";

	// This menu allows the user to select their preferred option
	std::cout << "\t\t\tWhat option would you like?\n";
	std::cout << "\t\t\t  *********************\n";
	std::cout << "\t\t\t  * 1. Add one hour   *\n";
	std::cout << "\t\t\t  * 2. Add one minute *\n";
	std::cout << "\t\t\t  * 3. Add one second *\n";
	std::cout << "\t\t\t  * 4. Exit           *\n";
	std::cout << "\t\t\t  *********************\n\n";


	return 0;
}

void display12hours() {

	struct tm tempLocalTime;
	time_t localTime = time(0);
	localtime_s(&tempLocalTime, &localTime);
	int timeHour = tempLocalTime.tm_hour;
	int timeMinute = tempLocalTime.tm_min;
	int timeSeconds = tempLocalTime.tm_sec;
	int t12;
	int t12AM;
	if (timeHour == 0) {
		t12AM = 12;
		std::cout << t12AM << ":" << timeMinute << ":" << timeSeconds << " AM";

	}

	else if (timeHour > 12) {
		t12 = timeHour - 12;
		std::cout << t12 << ":" << timeMinute << ":" << timeSeconds << " PM";

	}
	else {
		std::cout << timeHour << ":" << timeMinute << ":" << timeSeconds << " AM";
	}
	//be sure to run this program in the morning when it is still signle digit to be
	//sure that it works properly
}
void display24hours() {

	struct tm tempLocalTime;
	time_t localTime = time(0);
	localtime_s(&tempLocalTime, &localTime);
	int timeHour = tempLocalTime.tm_hour;
	int timeMinute = tempLocalTime.tm_min;
	int timeSeconds = tempLocalTime.tm_sec;
	std::cout << timeHour << ":" << timeMinute << ":" << timeSeconds;


	
}