#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double *f_min(double *tab, int n);

int main()
{
    srand(time(NULL));

    double tab[10];

    for (int i=0; i<10; i++)
    {
        tab[i] = (double)rand()/RAND_MAX;
    }

    for (int i=0; i<10; i++)
    {
        printf("tab[%d] = %f, adres elementu : %p\n",i,tab[i],tab+i);
    }

    double *min = f_min(tab, 10);


    printf("minimum: tab[%d] = %f, adres elementu = %p\n",min-tab, *min, min);

    return 0;
}

double *f_min(double *tab, int n)
{
    double *min = tab;

    for (int i=0; i<n; i++)
    {
        if (tab[i] < *min)
        {
            min = tab+i;
        }
    }

    return min;
}