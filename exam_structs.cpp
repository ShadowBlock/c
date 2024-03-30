#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define strdup _strdup
#pragma warning (disable: 4996)

typedef struct Date
{
    int day;
    char month[4];
    int year;
} DATE;

typedef struct Exam
{
    char* pSubject;
    DATE date;
    int mark;
} EXAM;

EXAM* MySession(int* pnExams)
{
    EXAM* pExams = (EXAM*)malloc(5 * sizeof(EXAM));

    for (int i = 0; i < 5; i++)
    {
        pExams[i].pSubject = strdup("Networking Basics");
        pExams[i].date.day = 19;
        strcpy(pExams[i].date.month, "Dec");
        pExams[i].date.year = 2023;
        pExams[i].mark = 3;
    }

    *pnExams = 5;
    return pExams;
}

int main(void)
{
    int nExams;
    EXAM* pMyExams = MySession(&nExams);
    float avgMark = 0;

    for (int i = 0; i < 5; i++)
    {
        avgMark += (float)pMyExams[i].mark;
        printf("%s at %d-%s-%d, mark is %d\n", pMyExams[i].pSubject, pMyExams[i].date.day, pMyExams[i].date.month, pMyExams[i].date.year, pMyExams[i].mark);
        free(pMyExams[i].pSubject);
    }

    free(pMyExams);

    avgMark = avgMark / nExams;
    printf("Your average mark is %.1f", avgMark);

    return 0;
}