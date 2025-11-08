#include "Student.h"
#include "list.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    if (argc < 3)
    {
        printf("Za mało argumentow\n");
        exit(1);
    }

    int n = atoi(argv[1]);
 
    SortedList list;
    initialize_list(&list);

    for (int i=0; i<n; i++)
    {
        add(&list, rand_student(), cmp_student_by_age);

    }

    print_list(&list, print_student );

    FILE *fp = fopen(argv[2], "wb");

    if (fp != NULL)
    {
        Node *current = list.head;

        while (current != NULL)
        {
            Student *s = (Student *)current->data;
            fwrite(s, sizeof(Student), 1, fp);
            current = current->next;
        }

        fclose(fp);
        free_list(&list, free);
    } else {
        printf("błąd w otwieraniu pliku\n");
        exit(1);
    }


    



    return 0;
}