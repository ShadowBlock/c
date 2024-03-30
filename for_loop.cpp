#include "stdlib.h"
#include "stdio.h"

int RandVal[100];
int y;

int GetRandArray(int z);

int main(void)
{
	int x;
	char line[4];
	printf("How many random numbers would you like? (1 to 100)? ");
	gets_s(line);
	x = atoi(line);
	
	y = GetRandArray(x);

	if (y == 1)
		printf("The input is invalid");
	else
		printf("Maximum random number is %d", y);
	return 0;
}

int GetRandArray(int z)
{
	if (z <= 0 || z > 100)
		return 1;

	int j = 0;

	for (int i = 0; i < z; i++)
	{
		RandVal[i] = rand();
		if (RandVal[i] > j)
			j = RandVal[i];
	}

	return j;
}