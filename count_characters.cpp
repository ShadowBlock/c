#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "ctype.h"

char line[81];
int last;
char vowels[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };

int convertLower(void);
int countVowels(void);
int countConsonants(void);

int main(void)
{
	int counter;
	while (1)
	{
		printf("\nPress your key: \nv - count vowels \nc - count consonants\nx - exit\n");
		switch (_getche())
		{
		case 'V':
		case 'v': 
			printf("\nType input sentence: ");
			gets_s(line);
			counter = countVowels();
			printf("You have %d vowels.", counter);
			break;
		case 'C':
		case 'c':
			printf("\nType input sentence: ");
			gets_s(line);
			counter = countConsonants();
			printf("You have %d consonants.", counter);
			break;
		case 'X':
		case 'x': return 0;
		default: break;
		}
	}
	return 0;
}

int countVowels(void)
{
	convertLower();
	int vowelCounter = 0;
	for (int i = 0; i < last; i++)
	{
		if (isalpha(line[i]))
		{
			for (int j = 0; j < 6; j++)
			{
				if (vowels[j] == line[i])
				{
					vowelCounter++;
					break;
				}
			}
		}
	}
	return vowelCounter;
}

int countConsonants(void)
{
	convertLower();
	int consonantCounter = 0;
	for (int i = 0; i < last; i++)
	{
		if (isalpha(line[i]))
		{
			for (int j = 0; j < 6; j++)
			{
				if (vowels[j] == line[i])
				{
					break;
				}
				else if (j == 5)
					consonantCounter++;
			}
		}
	}
	return consonantCounter;
}

int convertLower(void)
{
	for (int i = 0; i < 82; i++)
	{
		if (line[i] == '\0' || line[i] == '\n')
		{
			last = i;
			return 0;
		}
		line[i] = tolower(line[i]);
	}
	return 0;
}