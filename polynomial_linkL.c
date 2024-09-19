#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    int coeff;
    int power;
    struct nodeType *next;
} node;



void addNode(node **head, int coeff, int pow)
{
    node *ptr = (node *)malloc(sizeof(node));
    node *loc;
    ptr->coeff = coeff;
    ptr->power = pow;
    ptr->next = NULL;
    if (*head == NULL)
        *head = ptr;
    else
    {
        loc = *head;
        while (loc->next != NULL)
            loc = loc->next;
        loc->next = ptr;
    }
}

void traverse(node *head)
{
    printf("\n");
    while (head != NULL)
    {
        printf("%dx^%d ", head->coeff, head->power);
        head = head->next;
    }
}

node *search(node *head, int item)
{
    while (head != NULL && head->power != item)
    {
        head = head->next;
    }
    return head;
}

void addPolynomial(node *ptr1, node *ptr2, node **ptr3)
{
    int power;
    int coeff;
    while ((ptr1 != NULL) && (ptr2 != NULL))
    {
        if (ptr1->power > ptr2->power)
        {
            power = ptr1->power;
            coeff = ptr1->coeff;
            ptr1 = ptr1->next;
        }
        else if (ptr1->power < ptr2->power)
        {
            power = ptr2->power;
            coeff = ptr2->coeff;
            ptr2 = ptr2->next;
        }
        else
        {
            power = ptr1->power;
            coeff = ptr1->coeff + ptr2->coeff;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (coeff != 0)
            addNode(ptr3, coeff, power);
    }

    if (ptr1 == NULL)
    {
        for (; ptr2 != NULL; ptr2 = ptr2->next)
            addNode(ptr3, ptr2->coeff, ptr2->power);
    }
    else if (ptr2 == NULL)
    {
        for (; ptr1 != NULL; ptr1 = ptr1->next)
            addNode(ptr3, ptr1->coeff, ptr1->power);
    }
}

void multiplyPolynomial(node *ptr1, node *ptr2, node **ptr3)
{
    int powe, coef;
    node *temp, *loc, *tt;
    while (ptr1 != NULL)
    {
        temp = ptr2;
        while (temp != NULL)
        {
            coef = ptr1->coeff * temp->coeff;
            powe = ptr1->power + temp->power;
            tt = *ptr3;
            loc = search(tt, powe);
            if (loc == NULL)
                addNode(ptr3, coef, powe);
            else
                loc->coeff += coef;

            temp = temp->next;
        }
        ptr1 = ptr1->next;
    }
}

void main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;
    node *poly3 = NULL;
    node *poly4 = NULL;
    addNode(&poly1, 4, 4);
    addNode(&poly1, 7, 3);
    addNode(&poly1, 9, 2);
    addNode(&poly2, 6, 4);
    addNode(&poly2, 5, 3);
   
    addPolynomial(poly1, poly2, &poly3);
    multiplyPolynomial(poly1, poly2, &poly4);
    traverse(poly1);
    traverse(poly2);
    traverse(poly3);
    traverse(poly4);
}
