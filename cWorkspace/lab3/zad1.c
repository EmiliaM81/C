#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"

void fun(double *tab, int len, double *suma1, double *srednia1, double *iloczyn1, double **min1, double **max1)
{
    *suma1 = suma(tab, tab + len);
    *srednia1 = srednia(tab, tab+len);
    *iloczyn1 = iloczyn(tab, tab+len);

    *min1 = min(tab, tab + len);
    *max1 = max(tab, tab+len);


}

int main()
{
    srand(time(NULL));

    double tab[1000];

    d_array_set_random(tab, tab + 1000, 0.9, 999.9);

    d_array_print(tab, tab+1000, "tab");

    double suma1;
    double iloczyn1;
    double srednia1;
    double *min1;
    double *max1;

    fun(tab, 1000, &suma1, &srednia1, &iloczyn1, &min1, &max1);

    printf("Dla podanej tablicy: \n");
    printf("Suma = %.2lf\n", suma1);
    printf("Srednia = %.2lf\n", srednia1);
    printf("Iloczyn = %.2lf\n", iloczyn1);
    printf("Minimalny element = %.2lf\n", *min1);
    printf("Maksymalny element = %.2lf\n", *max1);

}