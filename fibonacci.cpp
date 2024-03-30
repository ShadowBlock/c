#include "stdio.h"

int main()
{
	int Fib[20], i = 2;
	Fib[0] = 1;
	printf("%d ", Fib[0]);
	Fib[1] = 1;
	printf("%d ", Fib[1]);
	while (i < 20)
	{
		Fib[i] = Fib[i - 1] + Fib[i - 2];
		printf("%d ", Fib[i]);
		i = i + 1;
	}
	return 0;
}