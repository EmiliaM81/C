#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"

#include <ctype.h>

#define MONTHS_IN_YEAR 12


int main()
{
    const unsigned short sizes[MONTHS_IN_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const char *MONTHS_NAMES[MONTHS_IN_YEAR] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec",
    "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};

    unsigned short *months_v1[MONTHS_IN_YEAR];

    for (int i=0; i<MONTHS_IN_YEAR; i++)
    {
        months_v1[i] = malloc(sizes[i]*sizeof(int));

        if (months_v1[i] == NULL)
        {
            printf("Błąd w alokacji pamięci\n");

            for (int j=0; j<=i; j++)
            {
                free(months_v1[j]);
            }

            exit(1);
        }    

        for (int j=0; j<sizes[i]; j++)
        {
            months_v1[i][j] = j+1;
        }


    }

    // wypisywanie tablicy

    for (int i=0; i<MONTHS_IN_YEAR; i++)
    {
        printf("%s ", MONTHS_NAMES[i]);

        for (int j=0; j<sizes[i]; j++)
        {
            printf("%d ", months_v1[i][j]);
        }

        printf("\n");
    }

    //zwolnienie pamieci

    for (int i=0; i<MONTHS_IN_YEAR; i++)
    {
        free(months_v1[i]);
        months_v1[i] = NULL;
    }





    return 0;
}