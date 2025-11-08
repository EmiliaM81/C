#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum student_status { STUDENT = 1, GRADUATE = 2, REMOVED = -1 };

struct Student 
{
    char *name;
    char *surname;
    int age;
    char address[50];
    enum student_status status;
};

void set_first_name( struct Student* str_ptr, char *name_ptr);
void set_last_name( struct Student* str_ptr, char *surname_ptr);
void set_age( struct Student* str_ptr, int age);
void set_address( struct Student* str_ptr, char *address_ptr);
void set_status( struct Student* str_ptr, enum student_status status);

void initialize_student(struct Student* student_ptr, char *name, char* surname, int age, char *address_ptr, enum student_status status);
void print_student(struct Student* student_ptr);
struct Student *copy_of(struct Student* student_ptr);
struct Student get_older(struct Student* stud_a, struct Student* stud_b);


int main()
{
    struct Student stud_a;
    struct Student stud_b;
    struct Student stud_c;

    //stud_a

    stud_a.name = "Emilia";
    stud_a.surname = "Wojtowicz";
    stud_a.age = 20;
    char adr[] ="ul. Cegielniana, Sanok";
    strcpy(stud_a.address, adr);
    stud_a.status = STUDENT;


    char add_tab[] = "ul. Reymonta, Krakow";
    initialize_student(&stud_b, "Jan", "Kowalski", 23, add_tab, GRADUATE); 

    stud_c = get_older(&stud_a, &stud_b);

    struct  Student stud_tab[] = {stud_a, stud_b, stud_c};

    for (int i=0; i<3; i++)
    {
        print_student(&stud_tab[i]);
    }

    struct Student* stud_ptr_tab[] = { copy_of(&stud_a), copy_of(&stud_b), copy_of(&stud_c)};

    for (int i=0; i<3; i++)
    {
        print_student(stud_ptr_tab[i]);
    } 

    //zwalnianie pamięci

    for (int i = 0; i < 3; i++) 
    {
        free(stud_ptr_tab[i]->name);
        free(stud_ptr_tab[i]->surname);
        free(stud_ptr_tab[i]);
    }

    printf("Rozmiar struktury Student: %d\n", sizeof(struct Student));



    return 0;
}


void set_first_name( struct Student* str_ptr, char *name_ptr)
{


    str_ptr->name = malloc(strlen(name_ptr) +1);

    if (str_ptr->name)
    {
        strcpy(str_ptr->name, name_ptr);
    } else {
        printf("Error\n");
        exit(1);
    }
}

void set_last_name( struct Student* str_ptr, char *surname_ptr)
{

    str_ptr->surname = malloc(strlen(surname_ptr) +1);

    if (str_ptr->surname)
    {
        strcpy(str_ptr->surname, surname_ptr);
    } else {
        printf("Error\n");
        exit(1);
    }
}

void set_age( struct Student* str_ptr, int age)
{
    str_ptr->age = age;
}

void set_address( struct Student* str_ptr, char *address_ptr)
{


    strncpy(str_ptr->address, address_ptr, sizeof(str_ptr->address) - 1);
    
    // Upewnij się, że jest zakończony '\0'
    str_ptr->address[sizeof(str_ptr->address) - 1] = '\0';
}

void set_status( struct Student* str_ptr, enum student_status status)
{
    str_ptr->status = status;
}

void initialize_student(struct Student* student_ptr, char *name, char* surname, int age, char *address_ptr, enum student_status status)
{
    set_first_name(student_ptr, name);
    set_last_name(student_ptr, surname);
    set_age(student_ptr, age);
    set_address(student_ptr, address_ptr);
    set_status(student_ptr, status);
}

void print_student(struct Student* student_ptr)
{
    printf("Dane studenta: %s %s, ", student_ptr->name, student_ptr->surname);

    printf("wiek: %d, ", student_ptr->age);

    printf("adres: %s, ", student_ptr->address);

    if (student_ptr->status == STUDENT)
    {
        printf("status: student\n");
    } else if (student_ptr->status == GRADUATE) {
        printf("status: ukończone studia\n");
    } else if (student_ptr->status == REMOVED) {
        printf("status: usunięty z listy studentw\n");
    }
}

struct Student *copy_of(struct Student* student_ptr)
{
    struct Student *student_copy = malloc(sizeof(struct Student));

    initialize_student(student_copy, student_ptr->name, student_ptr->surname, student_ptr->age, student_ptr->address, student_ptr->status);

    return student_copy;
}

struct Student get_older(struct Student* stud_a, struct Student* stud_b)
{
    if (stud_a->age >= stud_b->age )
    {
        return *stud_a;
    } else {
        return *stud_b;
    }
}