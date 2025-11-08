#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    int n;

    printf("Podaj liczbe losowan: \n");
    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++) 
    {
    tab[i] = 0;
    }
 

    for (int i=0; i<n; i++)
    {
        double num = ((double)rand() / RAND_MAX) * 9.9999;

        if (num >= 0 && num<1)
        {
            tab[0]++;
        } else if (num>=1 && num < 2) {
            tab[1]++;
        } else if (num>=2 && num < 3) {
            tab[2]++;
        } else if (num>=3 && num < 4) {
            tab[3]++;
        }else if (num>=4 && num < 5) {
            tab[4]++;
        }else if (num>=5 && num < 6) {
            tab[5]++;
        }else if (num>=6 && num < 7) {
            tab[6]++;
        } else if (num>=7 && num < 8) {
            tab[7]++;
        }else if (num>=8 && num < 9) {
            tab[8]++;
        }else if (num>=9 && num < 10) {
            tab[9]++;
        }
    }


    for (int i=0; i<10; i++)
    {
        printf("Przedzial [%d, %d): %d punktow\n",i,i+1, tab[i]);
    }



    return 0;
}