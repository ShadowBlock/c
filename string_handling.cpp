#include "stdio.h"
#include "string.h"
#pragma warning (disable : 4996)

int CharFreq(char* pInput, char searchChar)
{
	int occurence = 0;
	if (*pInput == 0 || pInput == 0) return 0;
	if (searchChar == 0) return 0;

	char* pChar = strchr(pInput, searchChar);
	// esse Pinkman0
	if (pChar == 0) return 0;

	char* pLastChar = strrchr(pInput, searchChar);
	//e Pinkman0

	if (pChar == pLastChar) return 1;

	for (int i = 0; 1; i++)
	{
		occurence++;
		pChar = strchr(pChar + 1, searchChar);
		if (pChar == pLastChar)
		{
			occurence++;
			break;
		}
	}

	return occurence;
}

int main(void)
{
	char input[] = "Jesse Pinkerman";
	printf("%d\n", CharFreq(input, 'e'));
	return 0;
}