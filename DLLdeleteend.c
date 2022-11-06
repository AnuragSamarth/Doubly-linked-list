#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next , *prev;
};
struct node *deleteend(struct node *head)
{
    struct node *ptr=head,*prep=head->next;
    while(prep->next!=NULL)
    {
        ptr=ptr->next;
        prep=prep->next;
    }
    ptr->next=NULL;
    free(prep);
    return head;
}
int main()
{
    int a,i,n;
    struct node *p,*q,*head;
    printf("Enter the number of node \n");
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
        printf("Enter the next node\n");
        scanf("%d",&a);
        q=(struct node*)malloc(sizeof(struct node));
        q->data=a;
        q->next=NULL;
        q->prev=p;
        p->next=q;
        p=p->next;
    }
    head = deleteend(head);
    p=head;
    while(p!=NULL)
    {
        printf("\t%d",p->data);
        p=p->next;
    }
    return 0;
}