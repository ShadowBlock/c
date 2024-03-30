#include "stdio.h"
#include "string.h"
#pragma warning (disable : 4996)

int WordFreq(char* pInput)
{
	int nWord = 1;
	if (*pInput == 0 || pInput == 0) return 0;

	char* pChar = strchr(pInput, ' ');
	// Pinkman0
	if (pChar == 0) return 1;

	char* pLastChar = strrchr(pInput, ' ');
	// Pinkman0

	if (pChar == pLastChar) return 2;

	for (int i = 0; 1; i++)
	{
		nWord++;
		pChar = strchr(pChar + 1, ' ');
		if (pChar == pLastChar)
		{
			nWord++;
			break;
		}
	}

	return nWord;
}

int main(void)
{
	char input[] = "Here is a small list of words, lol.";
	printf("Number of words is: %d\n", WordFreq(input));
	return 0;
}