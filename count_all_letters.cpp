#include "stdio.h"
#include "string.h"
#include "ctype.h"
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

int *CharFreqs(char* pInput)
{
	if (*pInput == 0 || pInput == 0) return 0;
	for (int i = 0; pInput[i]; i++)
	{
		pInput[i] = tolower(pInput[i]);
	}
	//jesse pinkman0

	int occurences[26];
	int i = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		occurences[i] = CharFreq(pInput, c);
		i++;
	}

	return occurences;
}

int main(void)
{
	char input[] = "My name is Jesse";
	int occurences[26];
	char c[27] = "abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < 26; i++)
	{
		occurences[i] = *(CharFreqs(input) + i);
		printf("%c - %d\n", c[i], occurences[i]);
	}
	return 0;
}