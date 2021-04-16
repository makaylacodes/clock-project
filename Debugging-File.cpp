#include <iostream>
#include <string>
#include <ctime>
#include <time.h>


int display12hours(int& timeHour, int& timeMinute, int& timeSecond);
int display24hours(int& timeHour, int& timeMinute, int& timeSecond);

int main() {

	int timeHour;
	int timeMinute;
	int timeSecond;

	// This text will display a 12 hour clock and a 24 hour clock.
	std::cout << "\t*************************         *************************\n";
	std::cout << "\t      12 hour clock                      24 hour clock\n";
	std::cout << "\t       ";
	display12hours(timeHour, timeMinute, timeSecond);
	std::cout << "\t                    ";
	display24hours(timeHour, timeMinute, timeSecond);
	std::cout << " \n";
	std::cout << "\t*************************         *************************\n\n";

	std::cout << "\t\t\tWhat option would you like?\n";
	std::cout << "\t\t\t  *********************\n";
	std::cout << "\t\t\t  * 1. Add one hour   *\n";
	std::cout << "\t\t\t  * 2. Add one minute *\n";
	std::cout << "\t\t\t  * 3. Add one second *\n";
	std::cout << "\t\t\t  * 4. Exit           *\n";
	std::cout << "\t\t\t  *********************\n\n";

	return 0;
}

int display12hours(int& timeHour, int& timeMinute, int& timeSecond) {

	struct tm tempLocalTime;
	time_t localTime = time(0);
	localtime_s(&tempLocalTime, &localTime);
	timeHour = tempLocalTime.tm_hour;
	timeMinute = tempLocalTime.tm_min;
	timeSecond = tempLocalTime.tm_sec;

	if (timeHour == 0) {
		timeHour = 12;
		std::cout << timeHour << ":" << timeMinute << ":" << timeSecond << " AM ";

	}

	else if (timeHour > 12) {
		timeHour -= 12;
		std::cout << timeHour << ":" << timeMinute << ":" << timeSecond << " PM ";

	}

	else {
		std::cout << timeHour << ":" << timeMinute << ":" << timeSecond << " AM";
	}
	return timeHour, timeMinute, timeSecond;

	//be sure to run this program in the morning when it is still signle digit to be
	//sure that it works properly
}

int display24hours(int& timeHour, int& timeMinute, int& timeSecond) {

	struct tm tempLocalTime;
	time_t localTime = time(0);
	localtime_s(&tempLocalTime, &localTime);
	timeHour = tempLocalTime.tm_hour;
	timeMinute = tempLocalTime.tm_min;
	timeSecond = tempLocalTime.tm_sec;
	std::cout << timeHour << ":" << timeMinute << ":" << timeSecond;

	return timeHour, timeMinute, timeSecond;

}