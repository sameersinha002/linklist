#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int info;
    struct nodeType *prev;
    struct nodeType *next;
} node;

void createEmptyList(node **head, node **tail)
{
    *head = NULL;
    *tail = NULL;
}

void insertAtBeginning(node **head, node **tail, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->prev = NULL;
    ptr->next = *head;

    if (*head == NULL)
    {
        *tail = ptr; // If list is empty, update tail
    }
    else
    {
        (*head)->prev = ptr;
    }

    *head = ptr;
}

void insertAtEnd(node **head, node **tail, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->next = NULL;

    if (*head == NULL)
    {
        ptr->prev = NULL;
        *head = ptr;
        *tail = ptr;
        return;
    }

    ptr->prev = *tail;
    (*tail)->next = ptr;
    *tail = ptr;
}

void insertAfterItem(node *head, int item, int after)
{
    while (head != NULL && head->info != after)
    {
        head = head->next;
    }
    if (head == NULL)
    {
        printf("Element not found in the list\n");
        return;
    }

    node *ptr = (node *)malloc(sizeof(node));
    ptr->info = item;
    ptr->next = head->next;
    ptr->prev = head;
    if (head->next != NULL)
        head->next->prev = ptr;
    head->next = ptr;
}

void traverseInOrder(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->info);
        head = head->next;
    }
    printf("\n");
}

void traverseInReverseOrder(node *tail)
{
    if (tail == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (tail != NULL)
    {
        printf("%d ", tail->info);
        tail = tail->prev;
    }
    printf("\n");
}

int lengthOfList(node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

void deleteFromBeginning(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *ptr = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(ptr);
}

void deleteFromEnd(node **head)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    node *ptr = *head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    if (ptr->prev != NULL)
        ptr->prev->next = NULL;
    free(ptr);
}

int main()
{
    node *tail = NULL;
    node *head = NULL;
    int opt, item, after;

    do
    {
        printf("\n\n1 Create the linked list\n");
        printf("2 Insert at beginning\n");
        printf("3 Insert at end\n");
        printf("4 Insert after an item\n");
        printf("5 Traverse in order\n");
        printf("6 Traverse in reverse order\n");
        printf("7 Check length of linked list\n");
        printf("8 Delete from beginning\n");
        printf("9 Delete from end\n");
        printf("10 Exit\n\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            createEmptyList(&head, &tail);
            printf("Linked list is created\n");
            break;

        case 2:
            printf("Enter the data: ");
            scanf("%d", &item);
            insertAtBeginning(&head, &tail, item);
            printf("Data inserted at the beginning\n");
            break;

        case 3:
            printf("Enter the data: ");
            scanf("%d", &item);
            insertAtEnd(&head, &tail, item);
            printf("Data inserted at the end\n");
            break;

        case 4:
            printf("Enter the data: ");
            scanf("%d", &item);
            printf("Enter the element after which to insert: ");
            scanf("%d", &after);
            insertAfterItem(head, item, after);
            break;

        case 5:
            printf("Traversing in order: ");
            traverseInOrder(head);
            break;

        case 6:
            printf("Traversing in reverse order: ");
            traverseInReverseOrder(tail);
            break;

        case 7:
            printf("Length of linked list: %d\n", lengthOfList(head));
            break;

        case 8:
            deleteFromBeginning(&head);
            printf("Node deleted from the beginning\n");
            break;

        case 9:
            deleteFromEnd(&head);
            printf("Node deleted from the end\n");
            break;

        case 10:
            printf("Exited\n");
            break;

        default:
            printf("Invalid option\n");
            break;
        }

    } while (opt != 10);

    return 0;
}