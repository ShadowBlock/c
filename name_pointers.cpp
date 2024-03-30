#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

char* ReformatName(char* str);
char* CreateRandomName(int n1, int n2);

int main(void)
{
	char* randomName = CreateRandomName(10, 8);
	printf("Original name: %s\n", randomName);

	char* reformattedName = ReformatName(randomName);
	printf("Reformatted name: %s\n", reformattedName);
	
	free(reformattedName);
	free(randomName);
	
	return 0;
}

char* ReformatName(char* str)
{
	if (str == NULL || *str == '\0') return str;
	int length = strlen(str);
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			n = i;
			break;
		}
	}
	char* correctedName = (char*)malloc((length + 3) * sizeof(char));
	int index = 0;
	for (int i = n + 1; i < length; i++)
	{
		correctedName[index] = str[i];
		index++;
	}
	correctedName[index] = ',';
	index++;
	correctedName[index] = ' ';
	index++;

	for (int i = 0; i < n; i++)
	{
		correctedName[index] = str[i];
		index++;
	}
	correctedName[index] = '\0';

	return correctedName;
}

char* CreateRandomName(int n1, int n2)
{
	if (n1 <= 0 || n2 <= 0)
	{
		return 0;
	}
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; 
	char* pResult = (char*)malloc(n1 + n2 + 2);
	for (int i = 0; i < n1; i++)
	{
		*(pResult + i) = alphabet[rand() % 26];
	}
	*pResult = toupper(*pResult);
	*(pResult + n1) = ' ';
	for (int i = 0; i < n2; i++) {
		*(pResult + n1 + 1 + i) = alphabet[rand() % 26];
	}
	*(pResult + n1 + 1) = toupper(*(pResult + n1 + 1));
	*(pResult + n1 + n2 +1) = 0;
	return pResult;
}