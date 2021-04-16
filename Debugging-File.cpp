#include <iostream>
#include <string>
#include <ctime>
#include <time.h>

int addOneHour(int&, int& , int& ); // This function will add 1 hour to the time
int addOneMinute(int& , int&, int&); // This function will add 1 minute to the time
int addOneSecond(int&, int&, int&); // This function will add one second to the time
int display12hours(int&, int&, int& ); // This function will display the time in a 12 hour clock format
int display24hours(int&, int& , int&); // This function will display the time in a 24 hour clock format

int main() {

	int timeHour; // this variable represents the current hour in time
	int timeMinute; // this variable represents the current minute in time
	int timeSecond; // this variable represents the current second in time
	int userChoice; // this variable will read user input for the menu options

	// This text will display a 12 hour clock and a 24 hour clock.
	std::cout << "\t*************************         *************************\n";
	std::cout << "\t      12 hour clock                      24 hour clock\n";
	std::cout << "\t       ";
	display12hours(timeHour, timeMinute, timeSecond);
	std::cout << "\t                    ";
	display24hours(timeHour, timeMinute, timeSecond);
	std::cout << " \n";
	std::cout << "\t*************************         *************************\n\n";

	// This text will display a menu with options for altering the time. The user will input their selection
	std::cout << "\t\t\tWhat option would you like?\n";
	std::cout << "\t\t\t  *********************\n";
	std::cout << "\t\t\t  * 1. Add one hour   *\n";
	std::cout << "\t\t\t  * 2. Add one minute *\n";
	std::cout << "\t\t\t  * 3. Add one second *\n";
	std::cout << "\t\t\t  * 4. Exit           *\n";
	std::cout << "\t\t\t  *********************\n\n";

	std::cin >> userChoice;
	
	// This will loop the program when the user selects options 1-3 and quits when the user enters 4 or a number
	// outside of the selection
	while (userChoice >= 1 && userChoice <= 3) {

		
	// if user chooses 1, 1 will be added to the hour variable and both clock formats will be displayed
		if (userChoice == 1) {
			addOneHour(timeHour, timeMinute, timeSecond);
			
		}

	// if user chooses 2, 1 will be added to the minute variable and both clock formats will be displayed
		else if (userChoice == 2) {
			addOneMinute(timeHour, timeMinute, timeSecond);
			
		}

		// if user chooses 3, 1 will be added to the second variable and both clock formats will be displayed
		else if (userChoice == 3) {
			addOneSecond(timeHour, timeMinute, timeSecond);
			
		}

	// The menu is displayed again and the user has to input their selection
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

// This function will add 1 to the hour variable and display the updated time format.
int addOneHour(int &timeHour, int &timeMinute, int &timeSecond) {
	timeHour += 1;
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

// This function will add 1 to the minute variable and display the updated time format.
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


// This function will add 1 to the second variable and display the updated time format.
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



// This function will display the time in a 12 hour clock format
int display12hours(int& timeHour, int& timeMinute, int& timeSecond) {

	struct tm tempLocalTime;
	time_t localTime = time(0);
	localtime_s(&tempLocalTime, &localTime);
	timeHour = tempLocalTime.tm_hour;
	timeMinute = tempLocalTime.tm_min;
	timeSecond = tempLocalTime.tm_sec;

	//This if statement will covert 00:00 in 24 hour format to 12 AM for the 12 hour format
	if (timeHour == 0) {
		timeHour = 12;
		std::cout << timeHour << ":" << timeMinute << ":" << timeSecond << " AM ";

	}

	//This else if statement will convert the 24 hour format to the 12 hour format, if the 
	// hour is greater than 12
	else if (timeHour > 12) {
		timeHour -= 12;
		std::cout << timeHour << ":" << timeMinute << ":" << timeSecond << " PM ";

	}

	//This else statement will display the time in a 12 hour format because the hour is 
	// less than 12
	else {
		std::cout << timeHour << ":" << timeMinute << ":" << timeSecond << " AM";
	}
	return timeHour, timeMinute, timeSecond;


}


// This function will display the time in a 24 hour clock format
int display24hours(int& timeHour, int& timeMinute, int& timeSecond) {

	struct tm tempLocalTime;
	time_t localTime = time(0);
	localtime_s(&tempLocalTime, &localTime);
	timeHour = tempLocalTime.tm_hour; // This variable is storing the current hour
	timeMinute = tempLocalTime.tm_min; // This variable is storing the current minute
	timeSecond = tempLocalTime.tm_sec; // this variable is storing the current second

	std::cout << timeHour << ":" << timeMinute << ":" << timeSecond; // This statement will display the time in a 24 hour format

	return timeHour, timeMinute, timeSecond;

}