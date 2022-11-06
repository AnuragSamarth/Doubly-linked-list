#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next,*prev;
};
struct node *anyposition(int a,int position ,struct node *head)
{
     int i=0;
     struct node *temp , *p ,*q;
     p=head;

   while(i < position - 1)
   {
    p=p->next;
    i++;
   }
   temp=(struct node*)malloc(sizeof(struct node));
   temp->data=a;
   temp->prev=NULL;
   temp->next=NULL;

   q=p->next;

   p->next=temp;
   temp->next=q;
   temp->prev=p;
   q->prev=temp;
   return head;
}

int main()
{
    int a,i,n,position;
    struct node *p,*q,*head;
    printf("Enter the no. of nodes \n");
    scanf("%d",&n);
    printf("Enter the 1st node \n");
    scanf("%d",&a);
    p=(struct node*)malloc(sizeof(struct node));
    p->data=a;
    p->next=NULL;
    p->prev=NULL;
    head=p;
    for(i=0;i<n;i++)
    {
      printf("Enter the next node \n");
      scanf("%d",&a);
      q=(struct node*)malloc(sizeof(struct node));
      q->data=a;
      q->next=NULL;
      q->prev=NULL;
      p->next=q;
      q->prev=p;
      p=p->next;
    }
  
    printf("Enter the new node \n");
    scanf("%d",&a);
    printf("Enter the position at which you want to place node \n");
    scanf("%d",&position);
     
    head=anyposition(a,position,head);
    p=head;
    while(p!=NULL)
    {
      printf("\t %d",p->data);
      p=p->next;
    }
    return 0;
}