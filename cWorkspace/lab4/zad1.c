#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"
#include <stdbool.h>
#include <math.h>




bool is_identity(const short *first, const short *last)
{
    size_t n = last - first;

    if (n ==0) return false;

    int dim = (int) sqrt(n);

    if (dim * dim !=n ) return false;

    for (int i=0; i< dim; i++)
    {
        for (int j=0; j<dim; j++)
        {
            short val = first[i*dim + j];
            if ( ( i==j && val != 1) || (i != j && val != 0))
                return false;
        }
    }

    return true;
}

int main()
{


    return 0;
}