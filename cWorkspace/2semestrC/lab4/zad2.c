#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"
#include <stdbool.h>

double *my_alloc(int i_min, int i_max)
{
    double *tab;

    tab = malloc(sizeof(double)*(i_max - i_min +1));

    if (tab == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        return NULL;
    }

    return tab-i_min;
}

void my_free(double **my_tab, int i_min)
{
    if ((*my_tab + i_min) != NULL)
    {
        free(*my_tab + i_min);
        *my_tab = NULL;
        // wiszace wskazniki sprawdz ???
    }


}

int main()
{
    srand(time(NULL));
    double* tab = my_alloc(-2, 4);

    for (int i=-2; i<=4; i++)
    {
        *(tab+i) = 8.8;
    }

    for (int i=-2; i<=4; i++)
    {
        printf("tab[%d] = %.2lf, &tab[%d]=%p\n", i, *(tab+i), i, tab+i);
    }

    d_array_set_random(tab-1, tab+4, -1.1, 9.9);


    printf("Tablica po wypełnieniu losowymi wartościami\n");
    for (int i=-2; i<=4; i++)
    {
        printf("tab[%d] = %.2lf, &tab[%d]=%p\n", i, *(tab+i), i, tab+i);
    }    

    my_free(&tab, -2);

    //my_free(&tab, -2);

    return 0;
}