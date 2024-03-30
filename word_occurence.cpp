#include "stdio.h"
#include "string.h"
#include "ctype.h"


int WordSearch(char* pInput, const char* pWord)
{
	int occurences = 0;
	if (pInput == 0 || *pInput == 0) return 0;
	if (pWord == 0 || *pWord == 0) return 0;

	int nWord = strlen(pWord);

	char* pSequence = strstr(pInput, pWord);

	if (pSequence == 0) return 0;

	if (pSequence)
	{
		for (int i = 0; pSequence != 0; i++)
		{
			if (pSequence == pInput || isspace(pSequence[-1]) || iscntrl(pSequence[-1]))
			{
				if (isspace(pSequence[nWord]) || iscntrl(pSequence[nWord]))
				occurences++;
			}
			pSequence = strstr(pSequence + strlen(pWord), pWord);
		}
	}

	return occurences;
}

int main(void)
{
	char input[] = "and The sasandsas band is cool andi awesome and and great and";
	char word[] = "and";
	printf("%d", WordSearch(input, word));
	return 0;
}