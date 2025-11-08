#include <stdio.h>

void count(int *tab, int n);


int main()
{

    int tab1[] = {7, [645]=-48, 12, 9 ,0};

    count (tab1, 649);

    return 0;
}

void count(int *tab, int n)
{
    int count1 = 0;

    int num = 0;

    for (int i=0; i<n ; i++)
    {
        num = tab[i];

        if (num==0)
        {
            count1 ++;
        }
    }

    printf("ilosc elementow zerowych w tablicy: %d\n", count1);
}