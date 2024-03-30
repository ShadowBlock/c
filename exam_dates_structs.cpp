#include "stdlib.h"
#include "stdio.h"

typedef struct Date
{
	int day;
	char month[4];
	int year;
} DATE;

typedef struct Exam
{
	const char* pSubject;
	DATE date;
	int mark;
} EXAM;

int main(void)
{
	struct Exam AllExams[5]
	{
		{ "Networking basics", { 18, "Dec", 2023 }, 4 },
		{ "Social, professional, Ethical aspects of IT", { 19, "Dec", 2023 }, 5 },
		{ "Introduction to Cyber Security", { 21, "Dec", 2023 }, 3 },
		{ "Introduction to Informatics and Computers", { 22, "Dec", 2023 }, 3 },
		{ "Fundamentals of Programming", { 5, "Jan", 2024 }, 2}
	};
	float avgMark = 0;
	for (int i = 0; i < 5; i++)
	{
		avgMark += (float)AllExams[i].mark;
		printf("%s at %d-%s-%d, mark is %d\n", AllExams[i].pSubject, AllExams[i].date.day, AllExams[i].date.month, AllExams[i].date.year, AllExams[i].mark);
	}

	avgMark = avgMark / 5;

	printf("Your average mark is %.1f", avgMark);

	return 0;
}