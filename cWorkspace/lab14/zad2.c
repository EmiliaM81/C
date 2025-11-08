#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct  
{
    char znak;
    int ile_liczb;
    unsigned short elastic_tab[];
} big_number;

big_number *rand_big_number(size_t n_min, size_t n_max);
void fprint_big_number(big_number *ptr);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    if (argc < 4)
    {
        printf("za mało argumentow\n");
        exit(1);
    }

    int count = atoi(argv[1]);
    int n_min = atoi(argv[2]);
    int n_max = atoi(argv[3]);

    big_number *tab[count];

    for (int i=0; i<count; i++)
    {
        tab[i] = rand_big_number(n_min, n_max);
    }


    //wypisywanie

    for (int i=0; i<count; i++)
    {
        fprint_big_number(tab[i]);
    }
    
    for (int i=0; i<count; i++)
    {
        free(tab[i]);
    }


    return 0;
}


big_number *rand_big_number(size_t n_min, size_t n_max) 
{
    int len = rand()%(n_max - n_min) + n_min;

    big_number *ptr = malloc(sizeof(big_number)+sizeof(unsigned short)*len);

    if (ptr == NULL) 
    {
        printf("błąd w alokacji pamięci\n");
        exit(1);
    }

    ptr->ile_liczb = len;


    
    if (rand()%2 == 0)
    {
        ptr->znak = '-';
        ptr->elastic_tab[0] =  (rand()%8 + 1);
    } else {
        ptr->znak ='+';
        ptr->elastic_tab[0] =  (rand()%8 + 1);
    }

    for (int i=1; i<len; i++)
    {

        ptr->elastic_tab[i] = rand()%10;
    }

    return ptr;

    


}

void fprint_big_number(big_number *ptr)
{
    int len = ptr->ile_liczb;

    if (ptr-> znak == '-') fprintf(stdout, "%c", ptr->znak);


    for (int i=0; i<len; i++)
    {
        fprintf(stdout, "%d", ptr->elastic_tab[i]);
    }

    fprintf(stdout, "\n");
}