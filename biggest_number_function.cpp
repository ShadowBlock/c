#include "stdio.h"
#include "stdlib.h"

int MaxOfThree(int a, int b, int c);

int main() 
{
	int m1 = MaxOfThree(1, 2, 3);
	printf("%d \n", m1);
	int m2 = MaxOfThree(3, 2, 1);
	printf("%d \n", m2);
	int m3 = MaxOfThree(1, 3, 2);
	printf("%d \n", m3);
	int m4 = MaxOfThree(2, 2, 3);
	printf("%d \n", m4);
	int m5 = MaxOfThree(2, 2, 2);
	printf("%d \n", m5);

	char line[81];
	int n1, n2, n3, answer;
	printf("Type your first number: ");
	gets_s(line);
	n1 = atoi(line);

	printf("Type your second number: ");
	gets_s(line);
	n2 = atoi(line);

	printf("Type your third number: ");
	gets_s(line);
	n3 = atoi(line);

	answer = MaxOfThree(n1, n2, n3);
	printf("The largest of the three is %d", answer);
}

int MaxOfThree(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
		{
			return a; // a biggest
		}
		else if (c > a)
		{
			return c; // c biggest
		}
		else if (a == c)
		{
			return a; // a and c biggest
		}
	}
	else if (b > a)
	{
		if (b > c)
		{
			return b; // b biggest
		}
		else if (c > b)
		{
			return c; // c biggest
		}
		else if (b == c)
		{
			return b; // b and c biggest
		}
	}
	else if (a == b)
	{
		if (a > c)
		{
			return a; // a and b biggest
		}
		else if (c > a)
		{
			return c; // c biggest
		}
		else if (a == c)
		{
			return a; // everything same
		}
	}
}