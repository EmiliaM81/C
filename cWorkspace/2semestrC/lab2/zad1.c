#include "../my_functions/functions_0d.h"

void sort(int *a, int *b, int *c, int *d)
{
    if ( *c > *d )
    {
        swap(c,d, sizeof(int));
    }
        
    if (*b > *c)
    {
        swap(b,c, sizeof(int));

            if ( *c > *d )
            {
                swap(c,d, sizeof(int));
            }
    }

    if (*a > *b)
    {
        swap(a,b, sizeof(int));

        if (*b > *c)
        {
            swap(b,c, sizeof(int));

                if ( *c > *d )
                {
                    swap(c,d, sizeof(int));
                }
        }
    }
    
}

void test( void )
{
    int a,b,c,d;

    for (int i=0; i<300; i++)
    {
        a = i_rand(1, 100);
        b = i_rand(1, 100);
        c = i_rand(1, 100);
        d = i_rand(1, 100);

        sort(&a, &b ,&c, &d);
        {
            if ( ! (a <= b && b <= c && c <= d) )
            {
                printf("W funkcji sort jest błąd\n");
                exit(1);
            }
        }

    }

    printf("Funkcja sort działa poprawnie\n");

}

int main()
{
    srand(time(NULL));
    test();


    return 0;
}