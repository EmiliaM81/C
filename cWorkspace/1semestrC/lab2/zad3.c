#include <stdio.h>

int main()
{
    int wysokość;

    do {
        printf("Podaj wysokość");
        scanf("%d",&wysokość);

    } while (wysokość <= 0);

    for (int i=0; i<wysokość; i++)
    {
        for (int k=0; k<i; k++)
        {
            printf(" ");
        }



        for (int j=0; j<((wysokość-i)*2 + 1); j++)
        {
            printf("*");
        }

        printf("\n");
    }






    return 0;
}