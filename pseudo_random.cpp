#include "stdio.h"
#include "stdlib.h"

int main()
{
	int n = 0;
	while (n < 50)
	{
		int r = rand();
		if (r < 500)
			printf("\n %d", r);
		n = n + 1;
	}
	return 0;
}