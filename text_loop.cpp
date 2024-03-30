#include "stdio.h"
#include "stdlib.h"

int main()
{
	int n = 0, a = 0, A = 0;
	char line[81];
	printf("Type your text: ");
	gets_s(line);
	while (n < 80)
	{
		if ((line[n] >= 'A') && (line[n] <= 'Z'))
		{
			if (line[n] == 'A')
			{
				A = A + 1;
				n = n + 1;
			}
			else
				n = n + 1;
		}
		else if ((line[n] >= 'a') && (line[n] <= 'z'))
		{
			if (line[n] == 'a')
			{
				a = a + 1;
				n = n + 1;
			}
			else
				n = n + 1;
		}
		else if (line[n] == '\0')
		{
			printf("In this text there are %d lowercase a letters and %d uppercase A letters.", a, A);
			return (0);
		}
		else
		{
			printf("Illegal input.");
			return (1);
		}
	}

	return (0);
}