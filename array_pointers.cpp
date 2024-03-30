#include "stdio.h"
#include "stdlib.h"

#define ERROR_NONE 0
#define ERROR_NEGATIVE 1
#define ERROR_ZERO 2
#define ERROR_LARGE_NUMBER 3
#define ERROR_POINTER_ZERO 4
#define ERROR_EMPTY 5

int CheckSum(int* array, int n, int* errorCode);
int* CreateRandomArray(int n, int lower, int upper);

int main(void)
{
	int errorCode;
	int n = 10; // how large the array is
	int *createdArray = CreateRandomArray(n, 10, 100);
	int sum = CheckSum(createdArray, n, &errorCode);
	switch (errorCode)
	{
	case ERROR_NEGATIVE: printf("ERROR! One of the elements was negative.\n"); break;
	case ERROR_ZERO: printf("ERROR! One of the elements was 0.\n"); break;
	case ERROR_LARGE_NUMBER: printf("ERROR! One of the elements was too large.\n"); break;
	case ERROR_POINTER_ZERO: printf("ERROR! The array is assigned the value of 0.\n"); break;
	case ERROR_EMPTY: printf("ERROR! The array is empty.\n"); break;
	default: printf("The sum of the array is %d\n", sum);
	}
	free(createdArray);
	return 0;
}

int CheckSum(int* array, int n, int* errorCode)
{
	if (array == NULL)
	{
		*errorCode = ERROR_POINTER_ZERO;
		return 0;
	}
	if (n <= 0)
	{
		*errorCode = ERROR_EMPTY;
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] < 0)
		{
			*errorCode = ERROR_NEGATIVE;
			break;
		}
		if (array[i] == 0)
		{
			*errorCode = ERROR_ZERO;
			break;
		}
		if (array[i] > 1000)
		{
			*errorCode = ERROR_LARGE_NUMBER;
			break;
		}
		sum += array[i];
	}
	*errorCode = ERROR_NONE;
	return sum;
}

int* CreateRandomArray(int n, int lower, int upper) 
{ 
// n is the length of array to be generated
// The random numbers will be in range lower….upper
// lower and upper may be negative 
if (n <= 0 || lower >= upper) 
{ 
	return 0; 
} 
int *pResult = (int *)malloc(n * sizeof(int)); 
for (int i = 0; i < n; i++) 
{ 
	*(pResult + i) = lower + rand() % (upper - lower + 1); 
} 
return pResult; 
}