#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    double tab[10];

    srand(time(NULL));

    for (int i=0; i<10; i++)
    {
        tab[i] = ((double)rand()/RAND_MAX)*200.0 - 100.0;
    }

    printf("wylosowano tablice:\n");

    for (int i=0; i<10; i++)
    {
        printf("A[%d] = %8.2f\n", i, tab[i]);
    }


    //odwracam

    for (int i=0; i<10/2; i++)
    {
        double temp = tab[i];
        tab[i] = tab[9-i];
        tab[9-i] = temp;
    }

    printf("po odwroceniu:\n");
    for (int i=0; i<10; i++)
    {
        printf("A[%d] = %8.2f\n", i, tab[i]);
    }

    return 0;
}