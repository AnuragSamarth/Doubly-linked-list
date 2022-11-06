#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next,*prev;
};
struct node *anyposition(int position ,struct node *head)
{
    int i=0;
    struct node *p,*q;
    p=head;
    while(i<position-1)
    {
        p=p->next;
        i++;
    }
    q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
    return head;
}
int main()
{
    int i,a,n,position;
    struct node *p,*q,*head;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the head node\n");
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
        q->prev=p;
        q->next=NULL;
        p->next=q;
        p=p->next;
    }
     printf("Enter the position at which you want to delete a node\n");
     scanf("%d",&position);
     head=anyposition(position,head);
     p=head;
     while(p!=NULL)
     {
        printf("%d\t",p->data);
        p=p->next;
     }
     return 0;
}