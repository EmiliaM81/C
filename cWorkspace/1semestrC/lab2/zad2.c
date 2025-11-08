#include <stdio.h>

#define EPS (1e-9)

int main()
{
    int elem = 0;
    double sum = 0.0;

    int n=1;

    while ((1/(n*n)) >= EPS)
    {
        sum += 1/(n*n);
        n+=1;
        elem +=1;
    }

    printf("Po zsumowaniu %d elementow suma wyniosla: %.2f\n", elem, sum);



    return 0;
}