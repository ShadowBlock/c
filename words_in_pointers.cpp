#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"
#pragma warning (disable : 4996)

char** SentenceSplit(char* pSentence, int* pnWords)
{
	if (pSentence == 0 || *pSentence == 0)
	{
		*pnWords = 0;
		return 0;
	}

	int lenSentence = strlen(pSentence);
	char** ppTable = (char**)malloc(lenSentence);

	char* pChar = strchr(pSentence, ' ');
	int spaces = 1;
	for (int i = 2; ; i++)
	{
		spaces++;
		pChar = strchr((pChar + 1), ' ');
		if (pChar == 0) break;
	}
	*pnWords = spaces;

	char* pToken = strtok(pSentence, " ");
	int lenToken = strlen(pToken);
	ppTable[0] = (char*)malloc(lenToken + 1);
	strcpy(*(ppTable + 0) + 0, pToken);

	for (int i = 1; i < spaces; i++)
	{
		char* pToken = strtok(0, " ");
		int lenToken = strlen(pToken);
		ppTable[i] = (char*)malloc(lenToken + 1);
		strcpy(*(ppTable + i) + 0, pToken);
	}

	return ppTable;
}

char* CreateRandomSentence(int nWords, ...) {
	// nWords is the number of words, it is followed by sequence specifying the word lengths
	// nWords may be any positive number 
	va_list indic;
	va_start(indic, nWords);
	int nChars = 0, j = 0;
	for (int i = 0; i < nWords; i++, nChars += va_arg(indic, int) + 1);
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char* pResult = (char*)malloc(nChars);
	va_start(indic, nWords);
	for (int i = 0; i < nWords; i++)
	{
		int nWord = va_arg(indic, int);
		for (int k = 0; k < nWord; k++, *(pResult + j++) = alphabet[rand() % 26]);
		*(pResult + j++) = ' ';
	}
	*(pResult + nChars - 1) = 0;
	return pResult;
}

int WordExist(char** ppInput, int nWords, const char* pSearch)
{
	int output = 0;
	int cmpOutput;

	if (**ppInput == 0 || ppInput == 0 || nWords == 0 || pSearch == 0 || *pSearch == 0) return -1;

	for (int i = 0; i < nWords; i++)
	{
		cmpOutput = strcmp(ppInput[i], pSearch);
		if (cmpOutput == 0) output = 1;
	}
	
	return output;
}

int main(void)
{
	char* pSentence = CreateRandomSentence(7, 3, 4, 6, 1, 5, 7, 8);
	printf("The sentence: %s\n", pSentence);

	int nWords;

	char** ppTable = SentenceSplit(pSentence, &nWords);

	printf("The table: \n");

	for (int i = 0; i < nWords; i++)
	{
		printf("%d. %s\n", i, ppTable[i]);
	}

	int exists = WordExist(ppTable, nWords, "bwkfnqdu");

	if (exists == 1) printf("Word exists");
	if (exists == 0) printf("Word does not exist");
	if (exists == -1) printf("Input parameters are wrong.");

	return 0;
}