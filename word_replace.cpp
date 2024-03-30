#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#pragma warning (disable : 4996)


char *WordReplace(char* pInput, const char* pWord, const char* pReplace)
{
	if (pInput == 0 || *pInput == 0) return 0;
	if (pWord == 0 || *pWord == 0) return 0;
	if (pReplace == 0 || *pReplace == 0) return 0;

	int nWord = strlen(pWord);
	int nReplace = strlen(pReplace);
	int nInput = strlen(pInput);

	char* pOutput = (char*)malloc(nInput + (nReplace - nWord) + 2);

	char* pSequence = strstr(pInput, pWord);

	char* last = pSequence + nWord;

	if (pSequence == 0) return 0;

	int first = strlen(pInput) - strlen(pSequence);

	strncpy(pOutput, pInput, first);
	pOutput[first] = '\0';
	strcat(pOutput, pReplace);
	strcat(pOutput, last);

	return pOutput;
}

int main(void)
{
	char input[] = "I asked Mary to call me";
	char word[] = "Mary";
	char replace[] = "Elizabeth";
	
	char *pOutput = WordReplace(input, word, replace);
	if (pOutput == 0)
	{
		printf("Input parameters are wrong.");
		return 0;
	}
	printf("%s", pOutput);

	return 0;
}