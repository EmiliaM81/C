#include "Student.h"
#include "list.h"

#define ELEMENTY 100000

int main()
{
    Student *tab = malloc (sizeof(Student) *  ELEMENTY);
    int count;

    if (tab == NULL)
    {
        printf("błąd w alokacji pamięci\n");
        exit(1);
    }

    FILE *fp = fopen("plik", "rb");

    if (fp != NULL)
    {
        count = fread(tab, sizeof(Student), ELEMENTY, fp);

        Student *tmp = realloc(tab, count*sizeof(Student));

        if (tmp == NULL)
        {
            printf("błąd w alokacji pamięci\n");
            free(tab);
            exit(1);
        }

        tab = tmp;

        fclose(fp);
    } else {
        printf("błąd w otwiernaiu pliku\n");
        exit(1);
    }

    for (int i=0; i<count; i++)
    {
        print_student(tab+i);
    }

    free(tab);

    return 0;
}