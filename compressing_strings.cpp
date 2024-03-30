#include <stdio.h>

char Buf1[81], Buf2[81];

int compressText(void);

int main() 
{
    printf("Write a text with lots of spaces: ");
    gets_s(Buf1);

    compressText();
    printf("Text after compressing: %s\n", Buf2);
    return 0;
}

int compressText(void) {
    int j = 0;
    int lastCharWasSpace = 0;

    for (int i = 0; i <= 81; i++) 
    {
        if (Buf1[i] == '\0') 
        {
            Buf2[j] = '\0';
            return 0;
        }
        else if (Buf1[i] == ' ') 
        {
            if (lastCharWasSpace < 1) 
            {
                Buf2[j++] = ' ';
                lastCharWasSpace = 1;
            }
        }
        else 
        {
            Buf2[j++] = Buf1[i];
            lastCharWasSpace = 0;
        }
    }
    return 0;
}
