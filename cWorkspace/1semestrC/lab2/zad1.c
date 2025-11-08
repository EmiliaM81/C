#include <stdio.h>

int main()
{
    int sum = 0;
    int iloczyn = 1;

    for (int i=2000; i<=3000; i++)
    {
        if (i%2 == 1 && i%113 == 0)
        {
            printf("%d ",i);
            sum+=i;
            iloczyn*=i;
        }
    }

    printf("\n suma = %d, iloczyn = %d\n", sum, iloczyn);


    return 0;
}