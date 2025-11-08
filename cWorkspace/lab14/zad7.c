#include <stdio.h>
#include <stdlib.h>

typedef void (*PRINT)(const void *);

typedef struct _Node
{
void *data;
struct _Node *next;
} Node;

typedef struct _UnorderedList
{
Node *head;
} UnorderedList;

void initialize_list(UnorderedList *list);
void add_begin(UnorderedList *list, void *data);
void add_end(UnorderedList *list, void *data);
void *delete_begin(UnorderedList *list);
void *delete_end(UnorderedList *list);
void print_list(const UnorderedList *list, PRINT print);


int main()
{

    return 0;
}

void initialize_list(UnorderedList *list)
{
    list->head = NULL;
}

void add_begin(UnorderedList *list, void *data)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}


void add_end(UnorderedList *list, void *data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Błąd w alokacji pamięci\n");
        exit(1);
    }

    new_node ->data = data;
    new_node->next = NULL;
    
    if (list->head == NULL)
    {
        list->head = new_node;

    } else {

        Node *node = list->head;

        while (node->next != NULL)
        {
            node = node->next;
        }
        node->next = new_node;
    }
    
}

void *delete_begin(UnorderedList *list)
{
    if (list == NULL)
    {
        return NULL;
    }

    Node *to_delete = list->head;
    void *data = to_delete->data;

    list->head = to_delete->next;

    free(to_delete);

    return data;
}

void *delete_end(UnorderedList *list)
{
    if (list->head == NULL)
    {
        return NULL;
    }

    Node *node = list->head;

    if (node->next == NULL)
    {
        void *data = node->data;
        free(node);
        list->head = NULL;
        return data;
    }

    Node *prev = node;

    while (node->next != NULL)
    {
        prev = node;
        node = node->next;
    }

    void *data = node->data;
    prev->next = NULL;
    free(node);

    return data;
}

void print_list(const UnorderedList *list, PRINT print)
{
    if (list->head == NULL)
    {
        return;
    }

    Node *node = list->head;

    while (node != NULL)
    {
        print(node->data);
        node = node->next;
    }
}
