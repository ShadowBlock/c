#include "stdio.h"
#include "stdlib.h"

char Table[5][5];

int createTable(void);

int main(void)
{
	createTable();
	for (int i = 0; i < 5; i++)
	{
		if (i > 0)
			printf("\n");
		for (int j = 0; j < 5; j++)
		{
			printf("%c ", Table[i][j]);
		}
	}
}

int createTable(void)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
				Table[i][j] = '*';
			else if (i > j)
				Table[i][j] = '-';
			else
				Table[i][j] = '+';
		}
	}
	return 0;
}