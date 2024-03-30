#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#pragma warning (disable : 4996)

typedef struct duration {
	int hours, mins;
} DURATION;

typedef struct departure {
	int day;
	char month[4];
	int year, hour, min;
} DEPARTURE;

typedef struct flight {
	const char* pStartingPoint;
	DEPARTURE departure;
	DURATION Duration;
} FLIGHT;

char** Exam(FLIGHT* pFlights, int nFlights);
int stringMonth(const char* month);

int main(void)
{
	//Defining all variables for the function
	FLIGHT flights[] = {
		{"Sofia", {1, "Jul", 2024, 19, 40}, {4, 55}},
		{"Bucharest", {20, "May", 2024, 12, 20}, {4, 15}},
		{"Athens", {20, "Apr", 2024, 18, 30}, {5, 25}},
		{"Helsinki", {27, "Feb", 2024, 23, 55}, {0, 35}},
		{"Riga", {30, "Jan", 2024, 17, 40}, {0, 55}}
	};
	int nFlights = 5;
	//Executing the function
	char** ppFlights = Exam(flights, nFlights);

	//Printing the arrival information
	for (int i = 0; i < nFlights; i++) {
		printf("From %s arrives %s\n", flights[i].pStartingPoint, ppFlights[i]);
	}
	
	//Freeing the allocated memory
	for (int i = 0; i < nFlights; i++) {
		free(ppFlights[i]);
	}
	free(ppFlights);

	return 0;
}

char** Exam(FLIGHT* pFlights, int nFlights)
{
	//Checking if input values are zero and if they are, returning 0
	if (pFlights == NULL || nFlights == NULL)
	{
		return 0;
	}
	//Creating and allocating memory for the result output
	char** ppFlights = (char**)malloc(nFlights * sizeof(pFlights));

	for (int i = 0; i < nFlights; i++) {
		//Converting departure time to tm structure from time.h
		struct tm departureTime = { 0 };
		departureTime.tm_year = pFlights[i].departure.year - 1900;
		departureTime.tm_mon = stringMonth(pFlights[i].departure.month); //Using stringMonth function to convert sring months to integers
		departureTime.tm_mday = pFlights[i].departure.day;
		departureTime.tm_hour = pFlights[i].departure.hour;
		departureTime.tm_min = pFlights[i].departure.min;

		//Calculating the arrival time using mktime, first converting it into mktime then adding the duration hours and minutes
		time_t departureTimes = mktime(&departureTime);
		time_t arrivalTimes = departureTimes + (pFlights[i].Duration.hours * 3600) + (pFlights[i].Duration.mins * 60);

		//Converting arrival time back to string, because output must be in string format
		char* arrivalString = (char*)malloc(20 * sizeof(char));
		strftime(arrivalString, 20, "%d-%m-%Y %H:%M", localtime(&arrivalTimes));

		//Storing the output value to ppFlights array of pointers to strings
		ppFlights[i] = arrivalString;
	}

	//Returning the array of pointers to strings
	return ppFlights;
}

//Converting string months to integers
int stringMonth(const char* month)
{
	const char* allMonths[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	for (int i = 0; i < 12; i++) {
		if (strcmp(month, allMonths[i]) == 0) {
			return i;
		}
	}
	return 1; //If inputed wrong month, then output is 1 so error
}