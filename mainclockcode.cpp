/*
Name: Makayla Anderson-Tucker
Assignment: 3-1 Project 1
*/

#include <iostream>
#include <string>
#include <ctime>
#include <time.h>


int addOneHour(int &timeHour, int &timeMinute, int &timeSecond);
int addOneMinute(int &timeHour, int &timeMinute, int &timeSecond);
int addOneSecond(int &timeHour, int &timeMinute, int &timeSecond);
int display12hours(int &timeHour, int &timeMinute, int &timeSecond);
int display24hours(int &timeHour, int &timeMinute, int &timeSecond);

int main() {

	int timeHour;
	int timeMinute;
	int timeSecond;
	int userChoice;
	
	

	// This text will display a 12 hour clock and a 23 hour clock.
	std::cout << "\t*************************         *************************\n";
	std::cout << "\t      12 hour clock                      24 hour clock\n";
	std::cout << "\t       ";
	std::cout << display12hours(timeHour, timeMinute, timeSecond);
	std::cout << "\t                    ";
	std::cout << display24hours(timeHour, timeMinute, timeSecond);
	std::cout << " \n";
	std::cout << "\t*************************         *************************\n\n";

	std::cout << "\t\t\tWhat option would you like?\n";
	std::cout << "\t\t\t  *********************\n";
	std::cout << "\t\t\t  * 1. Add one hour   *\n";
	std::cout << "\t\t\t  * 2. Add one minute *\n";
	std::cout << "\t\t\t  * 3. Add one second *\n";
	std::cout << "\t\t\t  * 4. Exit           *\n";
	std::cout << "\t\t\t  *********************\n\n";
	std::cin >> userChoice;
	int newHour;
	int newMinute;
	int newSecond;
	while (userChoice >= 1 && userChoice <= 3) {
	// This menu allows the user to select their preferred option
	
		if (userChoice == 1) {
			newHour = addOneHour(timeHour, timeMinute, timeSecond);
			std::cout << newHour;
		}
		else if (userChoice == 2) {
			newMinute = addOneMinute(timeHour, timeMinute, timeSecond);
			std::cout << newMinute;
		}
		else if(userChoice == 3){
			newSecond = addOneSecond(timeHour, timeMinute, timeSecond);
			std::cout << newSecond;
		}
		
	
			std::cout << "\t\t\tWhat option would you like?\n";
			std::cout << "\t\t\t  *********************\n";
			std::cout << "\t\t\t  * 1. Add one hour   *\n";
			std::cout << "\t\t\t  * 2. Add one minute *\n";
			std::cout << "\t\t\t  * 3. Add one second *\n";
			std::cout << "\t\t\t  * 4. Exit           *\n";
			std::cout << "\t\t\t  *********************\n\n";
			std::cin >> userChoice;
		
	}

	std::cout << "The program has ended.\n";

	return 0;
}

int addOneHour(int &timeHour, int &timeMinute, int &timeSecond) {
	timeHour = timeHour + 1;
	std::cout << "\t*************************         *************************\n";
	std::cout << "\t      12 hour clock                      24 hour clock\n";
	std::cout << "\t       ";
	display12hours(timeHour, timeMinute, timeSecond);
	std::cout << "\t                    ";
	display24hours(timeHour, timeMinute, timeSecond);
	std::cout << " \n";
	std::cout << "\t*************************         *************************\n\n";
	return timeHour, timeMinute, timeSecond;
}

int addOneMinute(int &timeHour, int &timeMinute, int &timeSecond) {
	timeMinute = timeMinute + 1;
	std::cout << "\t*************************         *************************\n";
	std::cout << "\t      12 hour clock                      24 hour clock\n";
	std::cout << "\t       ";
	display12hours(timeHour, timeMinute, timeSecond);
	std::cout << "\t                    ";
	display24hours(timeHour, timeMinute, timeSecond);
	std::cout << " \n";
	std::cout << "\t*************************         *************************\n\n";

	return timeHour, timeMinute, timeSecond;
}

int addOneSecond(int &timeHour, int &timeMinute, int &timeSecond) {
	timeSecond = timeSecond + 1;
	std::cout << "\t*************************         *************************\n";
	std::cout << "\t      12 hour clock                      24 hour clock\n";
	std::cout << "\t       ";
	display12hours(timeHour, timeMinute, timeSecond);
	std::cout << "\t                    ";
	display24hours(timeHour, timeMinute, timeSecond);
	std::cout << " \n";
	std::cout << "\t*************************         *************************\n\n";

	return timeHour, timeMinute, timeSecond;
}

int display12hours(int &timeHour, int &timeMinute, int &timeSecond) {

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

int display24hours(int &timeHour, int &timeMinute, int &timeSecond) {

	struct tm tempLocalTime;
	time_t localTime = time(0);
	localtime_s(&tempLocalTime, &localTime);
	timeHour = tempLocalTime.tm_hour;
	timeMinute = tempLocalTime.tm_min;
	timeSecond = tempLocalTime.tm_sec;
	std::cout << timeHour << ":" << timeMinute << ":" << timeSecond;

	return timeHour, timeMinute, timeSecond;
	
}