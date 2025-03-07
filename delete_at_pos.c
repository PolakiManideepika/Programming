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

void deletion_at_start()
{
    temp=head;
    head=head->next;
    temp->next=NULL;
    free(temp);
}
void deletion_at_pos()
{
    int pos,i=1;
    scanf("%d",&pos);
    if(pos==1)
    {
        deletion_at_start();
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
        prev->next=temp->next;
        temp->next=NULL;
        free(temp);
    }
}
int main()
{
    sll(10);
    sll(20);
    sll(30);
    sll(40);
    deletion_at_start();
    deletion_at_pos();
    display();
}
