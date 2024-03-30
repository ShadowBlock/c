#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int main(void)
{
	char line[81];
	char buf[20];
	int i = 0, j = 0;
	printf("Type your text: ");
	gets_s(line);
	while (i < 81)
	{
		if ((line[i] >= '0') && (line[i] <= '9'))
		{
			buf[j] = line[i];
			j++;
			if (line[i+1] == ' ')
				buf[j] = '\0';
		}
		else if (line[i] == '\0')
		{
			buf[j] = '\0';
			break;
		}
		i++;
	}
	int x = atoi(buf);
	if ((x % 2) == 0)
	{
		printf("%d is an even number \n", x);
		return 0;
	}
	else
	{
		printf("%d is an odd number \n", x);
		return 0;
	}
	return 1;
}