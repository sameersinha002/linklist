#include<stdio.h>
#include<stdlib.h>

typedef struct typenode
{
  int data;
  struct typenode *link;
} node;

node *reverseLinkedList(node *head)
{
    node *temp = head;
    node *prev = NULL;

    while (temp != NULL)
    {
        node *front = temp->link;

        temp->link = prev;
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
        head = head->link;
    }
}

void traverseInOrder2(node *head)
{
    for (; head != NULL; head = head->link)
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
    //  with call stack - recursive approach
    if (head->link != NULL)
        traverseInReverseOrder(head->link);

    printf("\n%d", head->data);
}

node *searchInUnsortedList(node *head, int item)
{
    while (head != NULL && head->data != item)
    {
        head = head->link;
    }
    return head;
}

// Sorted in increasing order
node *searchInSortedList(node *head, int item)
{
    while (head != NULL && head->data != item)
    {
        if (head->data < item)
            return NULL;
        head = head->link;
    }

    return head;
}
void insertatend(node **head,int value){
   node *new_node= (node *)malloc(sizeof(node));
    new_node->data=value;
    new_node->link=NULL;
    node *last=*head;
    if (*head==NULL){
      *head=new_node;
    }
    else{
     while (last->link!=NULL){
      last=last->link;
     }
     last->link=new_node;
  }}

void insertatfront(node **head,int value){
  node *new_data= (node *)malloc(sizeof(node));
  new_data->data=value;
  new_data->link=NULL;
  if (*head==NULL){
    *head=new_data;
  }
  else{
    new_data->link=*head;
    *head=new_data;
  }
}

void deleteAtFront(node **head){
  node *temp=*head;
   *head=temp->link;
   free(temp);
}

void deleteAtend(node **head){
  node *temp=*head;
  node *temp1=*head;
  while (temp->link!=NULL){
   temp1=temp;
   temp=temp->link;
  }
  temp1->link=NULL;
  free(temp);
}

void node_count(node **head){
  node *temp=*head;
  int count=0;
  while (temp!=NULL)
  {
    count++;
    temp=temp->link;
  }
  printf("No of Nodes = %d\n",count);
}

void printnode(node **head){
  node *temp=*head;
  if (head==NULL){
    printf("Linklist is empty\n");
  }
  else{
   int i=1;
    while(temp!=NULL){
      printf("Node %d Data = %d\n",i,temp->data);
      temp=temp->link;
      i++;
    }
  }
}

int main(){
node *head=NULL;

insertatend(&head,5);
insertatend(&head,7);
insertatend(&head,8);
insertatend(&head,9);
insertatend(&head,4);
insertatend(&head,15);
insertatfront(&head,11);
insertatfront(&head,3);
insertatfront(&head,22);
printnode(&head);
node_count(&head);
deleteAtFront(&head);
deleteAtFront(&head);
deleteAtend(&head);
printnode(&head);
node_count(&head);
return 0;
}