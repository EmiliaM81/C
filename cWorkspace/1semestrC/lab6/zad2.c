#include <stdio.h>
#include <ctype.h>
#include <string.h>

void funkcja(char * lancuch);

int main()
{
    char str[50] = "To jest testowy lancuch";

    

    printf("PRZED: %s\n", str);


    funkcja(str);

    return 0;
}

void funkcja(char * lancuch)
{
    int len = strlen(lancuch);

    char buff[len+1];

    for (int i=0; i<len; i++)
    {
        if (isspace(lancuch[i]))
        {
            buff[i] = '_';
        } 

        if ( isupper(lancuch[i]))
        {
            buff[i] = tolower(lancuch[i]);
        }

        if ( islower(lancuch[i]))
        {
            buff[i] = toupper(lancuch[i]);
        }
    }

    buff[len] = '\0';

    printf("Po: %s\n", buff);
}