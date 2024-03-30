#include "stdlib.h"
#include "stdio.h"
#include "string.h"

char* Reverse(char* i);
char* CreateRandomString(int n);

int main(void)
{
	char* pc = CreateRandomString(10);
	printf("The generated string is: %s\n", pc);
	char* pd = Reverse(pc);
	printf("The reversed of this is: %s\n", pd);
	free(pc);
	free(pd);
	return 0;
}

char *Reverse(char *i)
{
	if (i == NULL || *i == '\0') return i;
	int length = strlen(i);
	char* reversed = (char*)malloc((length + 1) * sizeof(char));
	for (int j = 0; j < length; j++)
	{
		reversed[j] = i[length - j - 1];
	}
	reversed[length] = '\0';
	return reversed;
}

char* CreateRandomString(int n)
{
	const char alphabet[] = "abcdefghijklmonpqrstuvwxyz";
	char* pResult = (char*)malloc(n + 1);
	for (int i = 0; i < n; i++)
	{
		*(pResult + i) = alphabet[rand() % 26];
	}
	*(pResult + n) = '\0';
	return pResult;
}