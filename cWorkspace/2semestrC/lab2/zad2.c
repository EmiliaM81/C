#include "../my_functions/functions_0d.h"

#define MAX_HIST 15
#define MIN -100
#define MAX 49

int n_przedzialu(int num)
{
    int div = (MAX - MIN +1)/15;
    int przedział = 0;

    while (num > MIN + div*przedział)
        przedział++;

    return przedział;
}

int main()
{
    int tab[MAX_HIST] = {0};

    for (int i=0; i<100000; i++)
    {
        tab[ n_przedzialu( i_rand(MIN, MAX) ) ]++;
    }

    for (int i=0; i<15; i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }

    return 0;
}