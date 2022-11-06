#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next,*prev; 
};
int main()
{
    int a,i,n;
    struct node *p,*q,*head;
    printf("Enter the number of nodes \n");
    scanf("%d",&n);
    printf("Enter the head node \n");
    scanf("%d",&a);
    p=(struct node*)malloc(sizeof(struct node));
    p->data=a;
    p->next=NULL;
    p->prev=NULL;
    head=p;
    for(i=0;i<n;i++)
    {
        printf("Enter the next nodes \n");
        scanf("%d",&a);
        q=(struct node*)malloc(sizeof(struct node));
        q->data=a;
        q->prev=p;
        q->next=NULL;
        p->next=q;
    
        p=p->next;
    }
    struct node *temp;
    temp=head;
    head=head->next;
    free(temp);
    p=head;
    while (p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    return 0;
}