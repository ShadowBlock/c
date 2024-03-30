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

EXAM **MySession(int* pnExams)
{
    EXAM** ppExams = (EXAM**)malloc(3 * sizeof(EXAM));
    EXAM* pFirstExam = (EXAM*)malloc(sizeof(EXAM));
    *pFirstExam = { strdup("Networking Basics"), {19, "Dec", 2023}, 3 };
    EXAM* pSecondExam = (EXAM*)malloc(sizeof(EXAM));
    *pSecondExam = { strdup("Networking Advanced"), {5, "Jan", 2023}, 4 };
    EXAM* pThirdExam = (EXAM*)malloc(sizeof(EXAM));
    *pThirdExam = { strdup("Networking Expert"), {15, "Feb", 2023}, 1 };

    ppExams[0] = pFirstExam;
    ppExams[1] = pSecondExam;
    ppExams[2] = pThirdExam;

    *pnExams = 3;
    return ppExams;
}

int main(void)
{
    int nExams;
    EXAM* *ppMyExams = MySession(&nExams);
    float avgMark = 0;

    for (int i = 0; i < nExams; i++)
    {
        avgMark += (float)ppMyExams[i]->mark;
        printf("%s at %d-%s-%d, mark is %d\n", (*(ppMyExams + i))->pSubject, (*(ppMyExams + i))->date.day, (*(ppMyExams + i))->date.month, (*(ppMyExams + i))->date.year, (*(ppMyExams + i))->mark);
        free(ppMyExams[i]->pSubject);
        free(ppMyExams[i]);
    }
    free(ppMyExams);

    avgMark = avgMark / nExams;
    printf("Your average mark is %.1f", avgMark);

    return 0;
}