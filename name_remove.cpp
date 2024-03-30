#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "memory.h"
#pragma warning(disable : 4996)

int removeName(char* pNames, char* pNameToRemove)
{
	if (!*pNames || !pNames) return 0;
	if (!*pNameToRemove || !pNameToRemove) return 0;
	int i;
	for (i = 0; i < strlen(pNames); i++)
	{ // find the index from which the name to remove begins
		if (!memcmp(pNames + i, pNameToRemove, strlen(pNameToRemove)))
		{
			break;
		}
	}
	if (i == strlen(pNames))
		return 0;
	if (pNames[i + strlen(pNameToRemove)] != '\0')
	{
		memmove(pNames + i, pNames + i + strlen(pNameToRemove) + 1, strlen(pNames) - (i + strlen(pNameToRemove)));
	}
	else
	{
		pNames[i - 1] = '\0';
	}
	return 1;
}

int main(void)
{
	char names[81], nameRemove[81];
	printf("Type the names: \n");
	scanf("%s", names);
	printf("Type the name to remove: \n");
	scanf("%s", nameRemove);
	if (removeName(names, nameRemove))
	{
		printf("New list is %s\n", names);
	}
	else
	{
		printf("Failed\n");
	}
	return 0;
}