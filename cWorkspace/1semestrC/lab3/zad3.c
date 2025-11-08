#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int tab1[50];
    int tab2[50];
    int tab3[51];

    



    for (int i=0; i<50; i++)
    {
        tab2[i] = rand()%10;
        tab1[i] = rand()%10;

    }


    
    int rest = 0;
    for (int i=49; i>=0; i--)
    {
        int sum = tab1[i] + tab2[i];

        tab3[i+1] = (sum+rest)%10;
        rest = (sum+rest)/10;
    }

    tab3[0] = rest;

    printf("   ");
    for (int i=0; i<50; i++)
    {
        printf("%d",tab1[i]);
    }

    printf("\n");
    printf(" + ");

    
    for (int i=0; i<50; i++)
    {
        printf("%d",tab2[i]);
    }

    printf("\n");    

    printf("---------------------------------------------\n");

    
    for (int i=0; i<51; i++)
    {
        printf("%d",tab3[i]);
    }

    return 0;
}