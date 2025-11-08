#include "../my_functions/functions_1d.h"
#include "../my_functions/functions_0d.h"

#include <ctype.h>

char *read_line(void)
{
    char *tab = malloc(sizeof(char)*1);

    if (tab == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    int count = 0;
    char letter;

    printf("Podaj słowo:\n");

    while ( (letter = getchar()) != '\n')
    {
        tab[count] = letter;
        count++;
        char *temp = realloc( tab , (count+1)*sizeof(char));
        

        if (temp == NULL)
        {
            free(tab);
            printf("Błąd w alokacji pamięci\n");
            exit(1);
        }

        tab = temp;
    }

    tab[count] = '\0';

    printf("Wczytane słowo: %s\n", tab);

    return tab;
}

char *trim(char *string)
{
    if ( string == NULL) return NULL;

    int count = 0;

    while (*(string+count) != '\0')
        count ++;

    char *temp = realloc(string, sizeof(char)*(count+1));

    if (temp == NULL)
    {
        free(string);
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }


    return temp;
}

void safe_free(void **my_tab)
{
    if ( *my_tab == NULL)
    {
        return;
    }

    free(*my_tab);
    *my_tab = NULL;
}

char *generate_key(const char *key_init)
{
    char *key = malloc(sizeof(char)*27);

    if (key == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int count = 0;

    int i = 0;

    while ( *(key_init + i) != '\0')
    {
        char letter = toupper(*(key_init+i));

        _Bool isThere = 0;

        for (int j=0; j< count ; j++)
        {
            if (key[j] == letter) 
            {
                isThere = 1;
                break;
            }    
        }

        if ( ! isThere)
        {
            key[count] = letter;
            count ++;
        }

        i++;
    }

    i=0;
    int k = count;
    

    while (i < 26)
    {
        char letter = alphabet[i];
        _Bool isThere = 0;

        for(int j=0; j<k; j++)
        {
            if (key[j] == letter) 
            {
                isThere = 1;
                break;
            }
        }

        if ( ! isThere)
        {
            key[count++] = letter;
        }

        i++;
    }

    key[26] = '\0';

    return key;


}

void encrypt(char *input_string, const char *key)
{

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int len = strlen(input_string);

    _Bool upp;

    for (int i=0; i<len; i++)
    {

        char letter = input_string[i];
        if (!isalpha(letter)) continue;

        upp = isupper(letter);

        int index;

        for (int j=0; j<27; j++)
        {
            if (alphabet[j] == toupper(letter))
            {
                index = j;
            }
        }

        if (upp)
        {
            input_string[i] = key[index];
        } else {
            input_string[i] = tolower(key[index]);
        }
    }

}


void decrypt(char *input_string, const char *key)
{

    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int len = strlen(input_string);

    _Bool upp;

    for (int i=0; i<len; i++)
    {

        char letter = input_string[i];
        upp = isupper(letter);

        int index;

        for (int j=0; j<27; j++)
        {
            if (!isalpha(letter)) continue;

            if (key[j] == toupper(letter))
            {
                index = j;
            }
        }

        if (upp)
        {
            input_string[i] = alphabet[index];
        } else {
            input_string[i] = tolower(alphabet[index]);
        }
    }

}

int main()
{

    printf("Podaj łańcuch, na podstawie ktorego zostanie utworzony klucz szyfrowania\n");

    char *tab = read_line();

    printf("podaj tekst do zaszyfrowania:\n");

    char *tekst = read_line();

    tab = trim(tab);
    tekst = trim(tekst);


    char *key = generate_key(tab);

    //printf("wygenerowany klucz: %s\n", key);

    encrypt(tekst, key);

    printf("po zaszyfrowaniu: %s\n", tekst);

    decrypt(tekst, key);

    printf("po odszyfrowaniu: %s\n", tekst);


    safe_free((void**)&tab);
    safe_free((void**)&key);
    safe_free((void**)&tekst);


    return 0;
}