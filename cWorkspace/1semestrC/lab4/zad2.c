#include <stdio.h>

unsigned int count1(unsigned int p);

int main()
{
    unsigned int num = 2327;


    int jedynki = count1(num);

    printf("Liczba %d ma %d jedynak.\n",num,jedynki);

    return 0;
}

unsigned int count1(unsigned int p)
{
    unsigned int num = 1U;

    int count = 0;

    while (p)
    {
        if ((p&1) == 1)
        {
            count++;
        }

        p=p>>1;
    }


    return count;
}
