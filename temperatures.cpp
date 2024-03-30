#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "conio.h"

double TempConverter(double temp, char type);

int main()
{
	char line[81];
	double value, convert;

	printf("Write the value you would like to convert: \n");
	gets_s(line);
	value = atof(line);

	printf("Is this value in Celsius (c,C) or Fahrenheit (F, f)? \n");
	char sign = _getche();

	convert = TempConverter(value, sign);
	if (isnan(convert))
		printf("\nNo solution");
	else
		printf("\nYour converted value is %.2f", convert);
	return 0;
}

double TempConverter(double temp, char type)
{
	double answer;
	if (type == 'F' || type == 'f')
	{
		answer = (temp - 32) * 5 / 9;
		return answer;
	}
	else if (type == 'C' || type == 'c')
	{
		answer = temp * 9 / 5 + 32;
		return answer;
	}
	else 
		return NAN;
}
