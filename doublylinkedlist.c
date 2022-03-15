#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
}*head=NULL;
void insatbeg();
void display();
void insatend();
void insatpos();
void delatbeg();
void delatend();
void delatpos();
void main()
{
    int choice;
    while(1)
    {
        printf("\n1.Insertion at beg\n2.Insertion at end\n3.Insertion at position");
        printf("\n4.Deletion at beginning\n5.Deletion at end\n6.Deletion at Specific position\n7. Display\n5.Exit\n");
        printf("Enter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insatbeg();
                   break;
            case 2:insatend();
                   break;
            case 3:insatpos();
                   break;
            case 4:delatbeg();
                   break;
            case 5:delatend();
                   break;
            case 6:delatpos();
                   break;
            case 7:display();
                   break;
            case 8:exit(0);
                   break;
            default:printf("Invalid Statement");
        }
    }
}
void insatbeg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
        {
           newnode->next=head;
           newnode->prev=NULL;
           head->prev=newnode;
           head=newnode;
        }
        printf("Node Inserted");
}
void insatend()
{
    struct node *newnode,*temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
    }
}
void insatpos()
{
    struct node *newnode,*temp=head,*temp1;
    int value;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item");
    scanf("%d",&newnode->data);
    printf("Enter the value in which you want to insert");
    scanf("%d",&value);
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head=newnode;
    }
    else
    {
        while(temp->data!=value)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        newnode->next=temp1;
        temp1->prev=newnode;
    }
    printf("Node inserted");

}
void delatbeg()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("List is Empty");
    }
    else if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
    printf("Node Deleted");
}
void delatend()
{
    struct node *temp=head,*temp1;
    if(head==NULL)
    {
        printf("List is Empty");
    }
    else if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=NULL;
        free(temp1);
    }
    printf("Node Deleted");

}
void delatpos()
{
    int value;
    struct node *temp=head,*temp1,*temp2;
    printf("Enter the value after you want to delete");
    scanf("%d",&value);
     if(head==NULL)
    {
        printf("List is Empty");
    }
    else if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->data!=value)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp2=temp1->next;
        temp->next=temp2;
        temp2->prev=temp;
        free(temp1);
    }
    printf("Node Deleted");
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
        {
        printf("List Empty\n");
        }
    while(temp->next!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\t",temp->data);
}
