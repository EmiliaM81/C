#include "Student.h"
int cmp_student_by_age(const void *a, const void *b);
void print_student(const void *student);
char rand_letter(LETTER_CASE letter_case);
void rand_name(char *array, size_t max_len);
void rand_email(char *array, size_t max_len);
Student *rand_student(void);





int cmp_student_by_age(const void *a, const void *b)
{
    unsigned short ageA = ((Student *)a)->age; 
    unsigned short ageB = ((Student *)b)->age; 

    return ageA - ageB;
}

void print_student(const void *student)
{
    assert(student != NULL);
    const Student *student_a = student;
    printf("Dane studenta: %s %s, wiek: %u, adres: %s\n", student_a->first_name, student_a->last_name, student_a->age,
    student_a->email);
}

char rand_letter(LETTER_CASE letter_case)
{
    char tab[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int index = rand()%26;

    if (letter_case == LOWER)
    {
        return tolower(tab[index]);
    } else {
        return tab[index];
    }
}

void rand_name(char *array, size_t max_len)
{
    if (max_len <2 ) return;
    
    array[0] = (rand_letter(UPPER));

    for (int i=1; i<max_len-1; i++)
    {
        array[i] = rand_letter(LOWER);
    }

    array[max_len-1] = '\0';
}

void rand_email(char *array, size_t max_len)
{
    const char *suffix = "@student.agh.edu.pl";
    size_t suffix_len = strlen(suffix);
    size_t name_len = rand() % (max_len - suffix_len - 1) + 1;

    for (size_t i = 0; i < name_len; ++i)
        array[i] = rand_letter(LOWER);
    array[name_len] = '\0';
    strncat(array, suffix, max_len - name_len - 1);
}

Student *rand_student(void)
{
    Student *stud = malloc(sizeof(Student));

    if(stud == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }

    rand_name(stud->first_name, 20);
    rand_name(stud->last_name, 20);
    stud->age = rand()%30 + 10;
    rand_email(stud->email, 40);


    return stud;
}