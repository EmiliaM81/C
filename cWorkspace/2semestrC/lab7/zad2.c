#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"

#include <ctype.h>
#include <stdarg.h>


int my_charcmp(char a, char b)
{
    _Bool signA=0;
    _Bool signB=0;

    if ( (! isalnum(a))) signA =1;
    if ( (! isalnum(b))) signB =1;

    if ( signA && signB)
    {
        return a - b;

    } else if ( signA && (!signB)){

        return 1;

    } else if ( (!signA) && signB ) {

        return -1;

    } else {

        return tolower(a) - tolower(b);
    }
}

int my_strcmp(const void *a, const void *b)
{
    int lenA = strlen((char*)a);
    int lenB = strlen((char *)b);

    int len;

    if (lenA >= lenB)
    {
        len = lenA;
    } else {
        len = lenB;
    }

    for (int i=0; i<len; i++)
    {
        if ( my_charcmp( ((char*)a)[i], ((char*)b)[i]) >0 )
        {
            return 1;
        } else if (my_charcmp( ((char*)a)[i], ((char*)b)[i])  < 0)
        {
            return -1;
        }
    }

    if (lenA > lenB)
    {
        return 1;
    } else if (lenA < lenB)
    {
        return -1;
    } else {
        return 0;
    }


}

int main()
{
    //printf("%d %d %d %d",'a', 'A', '$', '9');
    char strings[][11] = {"u", "REh4HmPJRS", "One", "one", "@$9325", "two", "THREE", "four", "415", "@#$325","@#$315", "@#9325", "five", "alpha", "zet", "0zero", "0123", "(text)", "8", "@#$325"};
    int elements = sizeof(strings)/sizeof(*strings);
    qsort(strings, elements, sizeof(*strings), my_strcmp);

    for (int i=0; i<elements; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}
