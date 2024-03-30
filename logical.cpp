#include "stdio.h"
#include "stdlib.h"
int main()
{
	int x;
	char line[81];
	printf("Type your text: ");
	gets_s(line);
	x = line[0];
	if ((x >= '0') && (x <= '9'))
		printf("The text starts with digit.");
	else if ((x >= 'A') && (x <= 'Z'))
		printf("The text starts with uppercase letter.");
	else if ((x >= 'a') && (x <= 'z'))
		printf("The text starts with lowercase letter.");
	else
		printf("The text starts with unidentified character.");
	return 0;
}