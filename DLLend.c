#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next , *prev;
};
int main()
{
    int a,i,n;
    struct node *p,*q,*head,*temp;
    printf("Enter the number of node\n");
    scanf("%d",&n);
    printf("Enter the 1st node\n");
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
        q->prev=p;
        p->next=q;
        p=p->next;
    }
    printf("Enter the new node\n");
    scanf("%d",&a);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    temp->next=NULL;
    temp->prev=p;
    p->next=temp;
    p=p->next;
    p=head;
    while(p!=NULL)
    {
        printf("\t%d",p->data);
        p=p->next;
    }
    return 0;
}