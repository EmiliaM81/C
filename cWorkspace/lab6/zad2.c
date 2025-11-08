#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"

#include <ctype.h>

char *camelCase(char *tab)
{
    /// konwersja snake case na camel case
    int length = strlen(tab);
    char* temp;

    char *newTab = malloc(sizeof(length+1)*sizeof(char));
    
    if (newTab == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }

    newTab[0] = '\0';

    temp = strtok(tab, "_");
    int first = 1;


    while (temp != NULL)
    {
        if (first)
        {
            strcat(newTab, temp);
            first = 0;
        } else {
            temp[0] = toupper(temp[0]);
            strcat(newTab, temp);
        }
        temp = strtok(NULL, "_");

    }

    printf("Camel case: %s\n", newTab);

    return newTab;
}

int main(int argc, char const *argv[])
{
    if (argc <=1)
    {
        printf("za mało argumentow\n");
        exit(1);
    }

    int length = 1;




    for (int i=1; i<argc; i++)
    {
        length += strlen(argv[i]);
    }

    length+= argc-2;

    char *tab = malloc(sizeof(length)*sizeof(char));

    if (tab == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }

    tab[0] = '\0';

    for (int i=1; i<argc-1; i++)
    {
        strcat(tab, argv[i]);
        strcat(tab, "_");
    }

    strcat(tab, argv[argc-1]);

    printf("%s\n", tab);


    char copy[length];

    strcpy(copy, tab);



    char *newTab = camelCase(copy);

    free(tab);
    free(newTab);



    return 0;
}

