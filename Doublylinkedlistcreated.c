#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
int main()
{
    int i,n,item;
    struct node *p , *new_node , *head;
    printf("Enter the no. of nodes :");
    scanf("%d",&n);
    printf("Enter the 1st node :");
    scanf("%d",&item);
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=item;
    new_node->next=NULL;
    new_node->prev=NULL;
    head=new_node;
    p=new_node;
    for(i=0;i<n;i++)
    {
        printf("Enter the next node :");
        scanf("%d",&item);
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=item;
        new_node->next=NULL;
        new_node->prev=p;
        p->next=new_node;
        p=p->next;
    }
    p=head;
    while(p!=NULL)
    {
        printf("\t %d",p->data);
        p=p->next;
    }
    return 0;
}
