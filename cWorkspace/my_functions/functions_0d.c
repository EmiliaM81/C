#include "functions_0d.h"

int i_rand(int min, int max)
{

    
    int number = min + rand()%(max-min+1);

    return number;
}


double d_rand(double min, double max)
{


    return min + ((double)rand() / RAND_MAX) * (max - min);


}


void i_swap(int *restrict first, int *restrict second)
{
    int temp = *first;

    *first = *second;
    *second = temp;

}


void swap(void * first, void * second, size_t size)
{
    char *a = (char *)first;
    char *b = (char *)second;
    char temp;

    for (size_t i=0; i<size; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;

    }
}