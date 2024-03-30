#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void)
{
    int i = 0;
    char c;
    char text[21];
    printf("Type your text, maximum of 20 characters, end with ESC \n");

    while (1)
    {
        c = _getch();

        if (c == 27)
        {
            text[i] = '\0';
            printf("\nResult is %s\n", text);
            break;
        }
        else if (i == 20)
        {
            text[i] = '\0';
            printf("\nResult is %s\n", text);
            break;
        }
        else
        {
            text[i] = c;
            i++;
            putchar(c); // Print the character without echo
        }
    }

    return 0;
}
