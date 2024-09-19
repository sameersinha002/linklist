#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int data;
    struct nodeType *next;
} node;

void createEmptyList(node **head)
{
    *head = NULL;
}

void insertAtEnd(node **head, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    ptr->next = NULL;

    if (*head == NULL)
        *head = ptr;
    else
    {
        node *current = *head;
        while (current->next != NULL)
            current = current->next;

        current->next = ptr;
    }
}

void insertAtStart(node **head, int info)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = info;

    ptr->next = *head;
    *head = ptr;
}

int listLength(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

node *reverseLinkedList(node *head)
{
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL)
    {
        node *front = temp->next;

        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void traverseInOrder(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void traverseInOrder2(node *head)
{
    for (; head != NULL; head = head->next)
    {
        printf("%d ", head->data);
    }
}

void traverseInReverseOrder(node *head)
{
    head = reverseLinkedList(head);
    traverseInOrder(head);
    head = reverseLinkedList(head);
}

void traverseInReverseOrder2(node *head)
{
    if (head->next != NULL)
        traverseInReverseOrder(head->next);

    printf("\n%d", head->data);
}

node *searchInUnsortedList(node *head, int item)
{
    while (head != NULL && head->data != item)
    {
        head = head->next;
    }
    return head;
}

node *searchInSortedList(node *head, int item)
{
    while (head != NULL && head->data != item)
    {
        if (head->data < item)
            return NULL;
        head = head->next;
    }

    return head;
}

void insertAfterElement(node *head, int insertAfter, int item)
{
    node *ptr;
    node *insertAfterNode = searchInUnsortedList(head, insertAfter);
    if (insertAfterNode != NULL)
    {
        ptr = (node *)malloc(sizeof(node));
        ptr->data = item;
        ptr->next = insertAfterNode->next;
        insertAfterNode->next = ptr;
        printf("\nInserted");
    }
    else
        printf("\nNode not found");
}

void insertBeforeElement(node **head, int insertBefore, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *prev = *head;
    ptr->data = item;

    // In case before the first element
    if (prev->data == insertBefore)
    {
        ptr->next = prev;
        *head = ptr;
        printf("\nInserted.");
        return;
    }

    // Traverse to the prev element
    while (prev->next != NULL && prev->next->data != insertBefore)
        prev = prev->next;

    if (prev->data != item && prev->next == NULL)
    {
        free(ptr);
        ptr = NULL;
        printf("\nNode does not exist.");
        return;
    }

    ptr->next = prev->next;
    prev->next = ptr;
    printf("\nInserted.");
}

void deleteAtStart(node **head)
{
    node *ptr = *head;
    if (*head == NULL)
    {
        printf("\nList Empty.");
        return;
    }
    *head = ptr->next;
    free(ptr);
    ptr = NULL;
    printf("\nDeleted.");
}

void deleteAtEnd(node **head)
{
    node *curr, *loc;
    if (*head == NULL)
    {
        printf("\nList Empty.");
        return;
    }
    curr = *head;
    if (curr->next == NULL)
    {
        *head = NULL;
        free(curr);
        curr = NULL;
    }
    else
    {
        while (curr->next->next != NULL)
            curr = curr->next;

        free(curr->next);
        curr->next = NULL;
    printf("\nDeleted.");
    }
}

void deleteAfterElement(node *head, int after)
{
    node *ptr, *loc;
    loc = searchInUnsortedList(head, after);
    if (loc == (node *)NULL)
        return;
    ptr = loc->next;
    loc->next = ptr->next;
    free(ptr);
}

void deleteSpecificNode(node **head, int item)
{
    if (*head == NULL)
    {
        printf("\nList Empty.");
        return;
    }
    node *prev = *head;

    if (prev->data == item)
    {
        *head = prev->next;
        printf("\nDeleted.");
        return;
    }

    while (prev->next != NULL && prev->next->data != item)
        prev = prev->next;

    if (prev->data != item && prev->next == NULL)
    {
        printf("\nNode does not exist.");
        return;
    }
    node *curr = prev->next;
    prev->next = curr->next;
    printf("\nDeleted.");
}

void deleteList(node **head)
{
    node *ptr;
    while (*head != NULL)
    {
        ptr = *head;
        *head = (*head)->next;
        free(ptr);
    }
}

void update(node *head, int old, int new)
{
    node *ptr = searchInUnsortedList(head, old);
    ptr->data = new;
    printf("\nUpdated");
}

void InsertAtNpos(node **head, int lenght,int pos,int item){
  node *ptr=(node *)(malloc(sizeof(node)));

}

void main()
{
    node *head;
    int choice, d, ins;
    createEmptyList(&head);

    do
    {
        printf("\n\n1. Create A New Linked List.");
        printf("\n2. Insert at the Start of the list.");
        printf("\n3. Insert at the end of the list.");
        printf("\n4. Insert after an item.");
        printf("\n5. Insert before an item.");
        printf("\n6. Delete from the Start of the list.");
        printf("\n7. Delete from the end of the list.");
        printf("\n8. Delete a specific item.");
        printf("\n9. Delete after an item.");
        printf("\n10. Delete list.");
        printf("\n11. Update item.");
        printf("\n12. Traverse In Order.");
        printf("\n13. Traverse In Reverse Order.");
        printf("\n14. Reverse LinkedList.");
        printf("\n15. Check List Length.");
        printf("\n16. Insert at n Position of list.");
        printf("\n17. Exit.");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createEmptyList(&head);
            printf("\nNew List Created");
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d", &d);
            insertAtStart(&head, d);
            printf("\nInserted");
            traverseInOrder(head);
            break;
        case 3:
            printf("\nEnter data: ");
            scanf("%d", &d);
            insertAtEnd(&head, d);
            printf("\nInserted");
            traverseInOrder(head);
            break;
        case 4:
            printf("\nEnter data: ");
            scanf("%d", &d);
            printf("\nEnter item info to insert after: ");
            scanf("%d", &ins);
            insertAfterElement(head, ins, d);
            traverseInOrder(head);
            break;
        case 5:
            printf("\nEnter data: ");
            scanf("%d", &d);
            printf("\nEnter item info to insert before: ");
            scanf("%d", &ins);
            insertBeforeElement(&head, ins, d);
            traverseInOrder(head);
            break;
        case 6:
            deleteAtStart(&head);
            traverseInOrder(head);
            break;
        case 7:
            deleteAtEnd(&head);
            traverseInOrder(head);
            break;
        case 8:
            printf("\nEnter item info to delete: ");
            scanf("%d", &d);
            deleteSpecificNode(&head, d);
            traverseInOrder(head);
            break;
        case 9:
            printf("\nEnter item info to delete after: ");
            scanf("%d", &d);
            deleteAfterElement(head, d);
            traverseInOrder(head);
            break;
        case 10:
            deleteList(&head);
            break;
        case 11:
            printf("\nEnter old value: ");
            scanf("%d", &d);
            printf("\nEnter new value: ");
            scanf("%d", &ins);
            update(head, d, ins);
            traverseInOrder(head);
            break;
        case 12:
            traverseInOrder(head);
            break;
        case 13:
            traverseInReverseOrder(head);
            break;
        case 14:
            head = reverseLinkedList(head);
            printf("\nList Reversed");
            break;
        case 15:
            printf("\n%d", listLength(head));
            break;
        case 16:
        printf("\nEnter position value.");
        scanf("%d",&d);
        int x=listLength(head);

        break;
        case 17:
            printf("\nExited");
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (choice != 17);
}