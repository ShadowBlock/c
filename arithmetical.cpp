#include "stdio.h"
#include "stdlib.h"
int main()
{
	int x;
	char line[81];
	printf("Type an integer: ");
	gets_s(line);
	x = atoi(line);
	if (x % 2 == 0)
		printf("This number is even");
	else
		printf("This number is odd");
	return 0;
}