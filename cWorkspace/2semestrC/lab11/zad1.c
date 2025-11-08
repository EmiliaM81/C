#include "Student_v1.h"


int main()
{
    system("cp Students_or.csv Students.csv");

    FILE *fp = fopen("Students.csv", "r+");
    int count = 0;

    if (fp != NULL)
    {
        char buff[101];
    
        while (fgets(buff, 101, fp) != NULL)
        {
            char *ptr = strtok(buff, ",\n");

            while (ptr != NULL)
            {
                count++;
                ptr = strtok(NULL, ",\n");
            }
            
        }

        fclose(fp);
    
    } else {
        printf("Błąd w otwieraniu pliku\n");
        exit(1);
    }

    printf("ilość wyrazow w pliku: %d\n", count);

    // podpuknt b

    Student_v1 tab[count];

    fp = fopen("Students.csv", "r+");

    if (fp != NULL)
    {
        
    for (int i = 0; i < count/4; ++i) {
        char first_name[50], last_name[50], email[EMAIL_MAX];
        unsigned short age;

        if (fscanf(fp, "%49s[^,],%49s[^,],%hu,%99s[^\n]\n", first_name, last_name, &age, email) != 4) {
            fprintf(stderr, "Błąd odczytu danych studenta w linii %d\n", i + 1);
            free(tab);
            fclose(fp);
            return 1;
        }

        initialize_student(&tab[i], first_name, last_name, age, email);
    

        fclose(fp);
    } 

    } else {
        printf("bład podczas otwierania pliku\n");
        exit(1);
    }

    

    for (int i=0; i<count/4; i++)
    {
        print_student(tab+i);
    }
    

    //podpunkt c

    qsort(tab, sizeof(tab)/sizeof(*tab), sizeof(*tab), students_cmp);


    for (int i=0; i<count/4; i++)
    {
        print_student(tab+i);
    }

    //podpunkt d
    
    Student_v1 student_to_find = {.age = 23, "bilfooter@tumblr.com", .first_name = "Weider", "Bilfoot"};

    Student_v1 *found = bsearch(&student_to_find, tab, sizeof(tab)/sizeof(*tab), sizeof(*tab), students_cmp);

    print_student(found);

    
    //podpunkt e

    fp = fopen("Students.csv", "r+");

    if (fp != NULL)
    {
        fprintf(fp, "SORTED\n");
        for (int i=0; i<count/4; i++)
        {
            fprintf(fp, "%s , %s , %d , %s\n", tab[i].first_name, tab[i].last_name, tab[i].age, tab[i].email);
        }

        fclose(fp);

    } else {
        printf("Błąd w otwieraniu pliku\n");
        exit(1);
    }

    for (int i = 0; i < count/4; ++i) 
    {
        free_student(&tab[i]);
    }
    free(tab);

    return 0;
}