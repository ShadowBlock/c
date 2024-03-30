#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "memory.h"
#pragma warning(disable : 4996)

int InsertName(char* pNames, int n, char* pNameToInsert)
{
	if (!pNames || !*pNames)
	{  // checks input data
		return 0;
	}
	if (!pNameToInsert || !*pNameToInsert)
	{ // checks input data
		return 0;
	}
	int nNames = 0, nInsert = 0;
	nNames = strlen(pNames);
	printf("%d\n", nNames);
	nInsert = strlen(pNameToInsert);
	printf("%d\n", nInsert);
	if (nInsert > n - nNames - 2)
	{  // no memory for the new name
	   // we need one byte for terminating zero and one byte for comma after the new name
		return 0;
	}
	memmove(pNames + nInsert + 1, pNames, nNames + 1);
	pNames[nInsert] = ',';
	memcpy(pNames, pNameToInsert, nInsert);
	return 1;
}

int main(void)
{
	char names[81];
	char newName[81];
	printf("Write name list: ");
	scanf("%s", names);
	printf("Write new name: ");
	scanf("%s", newName);
	if (InsertName(names, sizeof names, newName))
	{
		printf("New list: %s\n", names);
	}
	else
	{
		printf("Failed\n");
	}
	return 0;
}