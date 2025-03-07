#include<stdio.h>
struct node
{
    int data;
    struct  node*next;
};
struct node *head,*tail,*temp,*newnode;
void sll(int num)
{
    newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}
void display()
{
    temp=head;
    while(temp->next!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }

    printf("%d",temp->data);
}
void insert_at_start(int num)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void delete_at_first()
{
    temp = head;
    head = head->next;
    temp->next=NULL;
    free(temp);
}
int main()
{
    sll(10);
    sll(20);
    sll(30);
    sll(40);
    insert_at_start(50);
    delete_at_first();
    display();

}
