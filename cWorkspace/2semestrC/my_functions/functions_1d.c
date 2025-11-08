#include "functions_1d.h"
#include "functions_0d.h"

void i_array_print(const int *first, const int *last, const char *header)
{
    

    

    for (const int *i=first; i<last; i++)
    {
        printf("%s[%ld] = %d\n",header, i-first, *(i));
    }
}

void d_array_print(const double *first, const double *last, const char *header)
{
    

    

    for (const double* i=first; i<last; i++)
    {
        printf("%s[%ld] = %.2lf\n", header,i-first, *(i));
    }
}

void i_array_set_zero(int *first, int *last)
{
    

    for (int* i=last-1; i>=first; i--)
    {
        *(i) = 0;
    }

}

void d_array_set_zero(double *first, double *last)
{
    for (double* i=last-1; i>=first; i--)
    {
        *(i) = 0;
    }  
}

void i_array_set_random(int *first, int *last, int min, int max)
{
    for (int* i=last-1; i>=first; i--)
    {
        *(i) = i_rand(min, max);
    }
}

void d_array_set_random(double *first, double *last, double min, double max)
{
    for (double* i=last-1; i>=first; i--)
    {
        *(i) = d_rand(min, max);
    }
}

double suma(double* first, double* last)
{
    int len = last - first;

    double sum = 0;

    for (int i=0; i< len; i++)
    {
        sum += *(first + i);
    }

    return sum;
}

double srednia(double *first, double *last)
{
    int len = last - first;

    if (len==0)
    {
        printf("Błąd - dzielenie przez zero\n");
        return 0.0;
    }

    return suma(first, last)/len;
}

double iloczyn(double *first, double *last)
{
    double num = 1.0;

    int len = last - first;

    for (int i=0; i<len; i++)
    {
        num *= *(first + i);
    }

    return num;
}

double *min(double *first, double *last)
{
    double *min_ptr = first;

    int len = last -first;

    for (int i=0; i<len; i++)
    {
        if (*(first +i) < *min_ptr)
        {
            min_ptr = first + i;
        }
    }

    return min_ptr;
}

double *max(double *first, double *last)
{
    double *max_ptr = first;

    int len = last -first;

    for (int i=0; i<len; i++)
    {
        if (*(first +i) > *max_ptr)
        {
            max_ptr = first + i;
        }
    }

    return max_ptr;
}
