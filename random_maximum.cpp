#include "stdio.h"
#include "stdlib.h"

int main()
{
	int Rand[50], n = 0, max = 0;
	while (n < 50)
	{
		Rand[n] = rand();
		if (Rand[n] > max)
			max = Rand[n];
		n = n + 1;
	}
	printf("The largest number is %d", max);
	return 0;
}