#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int main(void)
{
	int counters[6] = {0,0,0,0,0,0};
	int i = 0, j = 0;
	char vowels[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	char c;
	printf("Write characters\n");
	while (1)
	{
		c = _getche();
		j = 0;
		if (c == '\r')
		{
			printf("\n\nThe results are: \n");
			while (i < 6)
			{
				printf("%c: %d\n", vowels[i], counters[i]);
				i++;
			}
			return 0;
		}
		while (j < 6)
		{
			if (c == vowels[j])
			{
				counters[j]++;
				break;
			}
			else j++;
		}
	}
}