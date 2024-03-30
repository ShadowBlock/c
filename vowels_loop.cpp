#include "stdio.h"
#include "stdlib.h"

int main(void) 
{
	int i = 0, j = 0, undercase = 0;
	char line[81];
	char vowels[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	printf("Type your 80 character text: ");
	gets_s(line);
	while (i <= 80)
	{
		j = 0;
		while (j < 6)
		{
			if (vowels[j] == line[i])
			{
				undercase++;
				break;
			}
			else j++;
		}

		if (line[i] == '\0')
		{
			printf("There are %d undercase vowels", undercase);
			return 0;
		}
		else i++;
	}
	return 1;
}