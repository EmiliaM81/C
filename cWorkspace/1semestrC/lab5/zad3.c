#include <stdio.h>

long long int silnia(int k);

int main()
{
    
    long long num = silnia(7);
    printf("%lld\n", num);

    return 0;
}

long long int silnia(int k)
{
    static int wywolanie=0;
    wywolanie ++;
    if (k==1)
    {
        
        printf("wywolanie nr. %d, %d\n",wywolanie, k);
        return k;
    } else {
        printf("wywolanie nr. %d, %d\n",wywolanie,k);
        return k*silnia(k-1);
    }

}