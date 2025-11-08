#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void fun(int *tab);

int main()
{
    srand(time(NULL));

    
    int tab[3];

    fun(tab);

    printf("%d, %d, %d\n",tab[0], tab[1], tab[2]);

    return 0;
}

void fun(int *tab1)
{
    int tab[10000];

    for (int i=0; i<10000; i++)
    {
        tab[i] = (double)rand()/RAND_MAX;
    }

    

    int sum = 0;

    for (int i=0; i<10000; i++)
    {
        sum += tab[i];
    }

    tab1[0] = sum/10000;
    tab1[1] = 1;
    tab1[2] = 2;

    

}