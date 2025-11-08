#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"

#define COLS 7
#define ROWS 4

double *min_pointer(double (*tab)[COLS], int rows)
{
    return min(*tab, *(tab+rows));
}

double** min_pointers_of_rows(double (*tab)[COLS], int rows)
{
   double **p_tab = malloc(sizeof(double*)*rows);

   for (int i=0; i<rows; i++)
   {
        *(p_tab + i) = min_pointer(tab+i, 1);
   }

   return p_tab;
}

int main()
{
    srand(time(NULL));

    double tab[ROWS][COLS];

    d_array_set_random(*tab, *tab+ROWS*COLS, 0, 100);

    d_array_print(*tab, *tab + ROWS*COLS, "tab");

    double *min_ptr = min_pointer(tab, ROWS);

    double **ptr_tab = min_pointers_of_rows(tab, ROWS);

    printf("Najmniejszy wskaźnik: adres = %p, wartość = %.2lf\n", min_ptr, *min_ptr);

    for (int i=0; i<ROWS; i++)
    {
        printf("Najmniejszy wskaźnik w wierszu %d : adres = %p, wartość = %.2lf\n",i, ptr_tab[i], *(ptr_tab[i]));

    }

    swap(min_ptr, *tab+ROWS*COLS-1, sizeof(double));

    d_array_print(*tab, *tab + ROWS*COLS, "tab");

    free(ptr_tab);

    
    return 0;
}