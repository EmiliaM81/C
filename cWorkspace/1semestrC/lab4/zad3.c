#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 8

void U2(int p)
{
    char tab[N+1];

    int p1 = abs(p);

    for (int i=7; i>=0; i--)
    {
        if ( p1%2 == 0)
        {
            tab[i] ='0';
        } else {
            tab[i] = '1';
        }

        p1 = p1/2;
    }

    tab[8] = '\0';

    if (p <0)
    {
        for (int i=0; i<8; i++)
        {
            if (tab[i] == '0')
            {
                tab[i] = '1';
            } else {
                tab[i] = '0';
            }
        }
    }

    printf("%4d = %s\n",p,tab);
}


int main(void)
{
    for (int i=-130; i<131; i++)
        if(i<-125 || i>125 || i%50==0)
            U2(i);
        

    return 0;
}



