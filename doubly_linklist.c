#include<stdio.h>
#include<stdlib.h>
typedef struct nodetype
{
    struct nodetype *prev;
    int data;
    struct nodetype *next;
}node;
void Emptylist(node **head,node **tail){
    *head=NULL;
    *tail=NULL;
}

void Insert_at_front(node **head, node **tail, int item){
   node *newnode=(node *)(malloc(sizeof(node)));
   newnode->data=item;
   newnode->prev=NULL;
   newnode->next=*head;
   if(*head==NULL){
   *head=*tail=newnode;
   }
   else{
      (*head)->prev=newnode;
      *head=newnode;
   }
}
void Insert_at_end(node **head, node **tail,int item){
   node *newnode=(node *)(malloc(sizeof(node)));
   newnode->data=item;
   newnode->next=NULL;
   newnode->prev=tail;
   if(*head==NULL){
   *head=*tail=newnode;
   } 
   else{
    (*tail)->next=newnode;
    *tail=newnode;
   }
}
node search_unsorted(node *head,int item){
     while (head!=NULL&& head->data!=item){
        head=head->next;
     }
    return head;
}
void traverseInOrder(node *head){
   while (head!=NULL)
   {
    printf("%d  ",head->data);
    head=head->next;
   }
}
int main(){
int n;
node *head;
node *tail;
int choice;
Emptylist(&head,&tail);
do
{
printf("Options\n");
printf("1 : Create Empty List.\n");
printf("2 : Insert Element at Beginning.\n");
printf("3 : Insert Element at End.\n");
printf("4 : Insert After a given element.\n");
printf("5 : Delete from beginning.\n");
printf("6 : Delete from End.\n");
printf("7 : Delete after a given element.\n");
printf("8 : Traverse in order.\n");
printf("0 : Exit.\n");
printf("Enter Choice--->\n");
scanf("%d",&choice);
switch (choice)
{
case 1:
    Emptylist(&head,&tail);
    printf("New list created.\n");
    break;
case 2:
     printf("Enter Data\n");
     scanf("%d",&n);
     Insert_at_front(&head,&tail,n);
     traverseInOrder(head);
     break;  
case 3:
     printf("Enter Data\n");
     scanf("%d",&n);
     Insert_at_end(&head,&tail,n);
     traverseInOrder(head);
     break;
case 8:
    traverseInOrder(head);
    break;
case 0:
    printf("Exiting...\n");
    break; 
default:
    printf("Default choice Enter Again.\n");
}
} while (choice!=0);
    // Free memory allocated for the nodes before exiting
    while(head != NULL) {
        node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}