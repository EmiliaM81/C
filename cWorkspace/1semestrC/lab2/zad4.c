#include <stdio.h>
#include <ctype.h>

int main()
{
    printf("podaj litere: \n");

    char letter;

    scanf(" %c", &letter);



    for (int i = 'D'; i>='A'; i--)
    {

        for (int j = 'D'; j-i>0; j--)
        {
            printf(" ");
        }


        for (int j = 'A'; j<=i; j++ )
        {
            printf("%c", j);
        }
        for (int j = i-1; j>='A'; j-- )
        {
            printf("%c", j);
        }
        printf("\n");
    }


    return 0;
}