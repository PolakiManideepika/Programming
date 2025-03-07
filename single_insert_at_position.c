#include<stdio.h>
struct node
{
    int data;
    struct node*next;
};
struct node*head,*tail,*temp,*newnode,*prev;
void sll(int num)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode -> data = num;
    newnode -> next = NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail -> next = newnode;
        tail=newnode;
    }
}
void display()
{
    temp=head;
    while(temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);

}
void insertion_at_start(int num)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
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

void insertion_at_pos(int num)
{
    int pos,i=1;
    scanf("%d",&pos);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    if(pos==1)
    {
        insertion_at_start(num);
    }
    else
    {
        temp=head;
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=newnode;
        newnode->next=temp;
    }

}
int main()
{
    sll(10);
    sll(20);
    sll(30);
    sll(40);
    insertion_at_start(50);
    insertion_at_pos(70);
    display();
}
