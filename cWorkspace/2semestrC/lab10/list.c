#include "list.h"

void initialize_list(SortedList *list)
{
    list->head = NULL;
}

void add(SortedList *list, void *data, CMP cmp)
{
    Node *tmp = malloc(sizeof(Node));

    if (tmp == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }

    tmp->data = data;

    //na początek pustej listy
    if (list->head == NULL || cmp(data, list->head->data) < 0)
    {
        tmp->next = list->head;
        list->head = tmp;
        return;
    }    


    

    for (Node *i = list->head; i != NULL; i = i->next )
    {
        if (i->next == NULL || cmp(data, i->next->data) < 0 )
        {
            tmp->next = i->next;
            i->next = tmp;
            return;
        }
    }

}

void print_list(const SortedList *list, PRINT print)
{
    for (Node *i = list->head; i != NULL; i = i->next)
    {
        print(i->data);
    }
}

void *get_data(const SortedList *list, CMP cmp, const void *data)
{
    for (Node *i = list->head; i != NULL; i=i->next)
    {
        if (cmp(data, i->data) == 0)
        {
            return i->data;
        }
    }
    return NULL;
}

void remove_data(SortedList *list, CMP cmp, void *data) 
{
    if (list->head == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    if (cmp(data, list->head->data) == 0)
    {
        Node *tmp = list->head;
        list->head = list->head->next;
        free(tmp);
    }


    for (Node *i = list->head; i != NULL && i->next != NULL; i= i->next )
    {
        if (cmp(data, i->next->data) == 0)
        {
            Node *tmp = i->next->next;
            free(i->next);
            i->next = tmp;
        
        }
    }

    
}

void remove_all(SortedList *list)
{
    if (list->head == NULL)
    {
        return;
    }

    for (Node *i = list->head, *next; i != NULL; i = next)
    {
        next = i->next;
        free(i);
    }

    list->head = NULL;
}