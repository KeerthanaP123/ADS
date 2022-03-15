#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
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
    int choice,c;
    while(1)
    {
        printf("\n1.Insertion at beg\n2.Insertion at end\n3.Insertion at position");
        printf("\n4.Deletion at begining\n5.Deletion at end\n6.Deletion at Specific position\n7. Display\n5.Exit\n");
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
    struct node *newnode,*temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;

    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;


        head=newnode;

    }
    printf("Node Inserted");

}
void insatend()
{
    struct node *temp=head,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value");
    scanf("%d",&newnode->data);
    if(head==NULL)
       {
           head=newnode;
           newnode->next=head;

       }
        else
        {
         while(temp->next!=head)
          {
             temp=temp->next;
          }
         temp->next=newnode;
         newnode->next=head;
       }
        printf("Node inserted");
}
void insatpos()
{
    int item;
    struct node *newnode,*temp=head,*temp1,*temp2;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the item");
    scanf("%d",&newnode->data);
    printf("Enter the value after which we want to insert");
    scanf("%d",&item);
    if(head==NULL)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        while(temp->next->data!=item)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp2=temp1->next;
        temp1->next=newnode;
        newnode->next=temp2;
    }
    printf("Node inserted");
}
void delatbeg()
{
    struct node *temp=head,*temp1=head;
    if(head==NULL)
    {
        printf("No node to Delete");
    }
    else if(temp->next==head)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        free(temp1);
    }
    printf("Node Deleted");
}
void delatend()
{
    struct node *temp=head,*temp1;
    if(head==NULL)
    {
        printf("No node to Delete");
    }
    else if(temp->next==head)
    {
        head=NULL;
        free(temp);
    }

    else
    {

        while(temp->next->next!=head)
        {

            temp=temp->next;
        }

        temp1=temp->next;

        temp->next=head;
        free(temp1);

    }
    printf("Node deleted");
}
void delatpos()
{
    struct node *temp=head,*temp1,*temp2,*temp3;
    int value;
    if(head==NULL)
    {
        printf("No node to Delete");
    }
    else if(temp->next==head)
    {
        head=NULL;
        free(temp);
    }

    else
    {
        printf("Enter the value after you want to delete");
        scanf("%d",&value);
        while(temp->next->data!=value)
        {

            temp=temp->next;
        }

        temp1=temp->next;
        temp2=temp1->next;
        temp3=temp2->next;
        temp1->next=temp3;
        free(temp2);

    }
    printf("Node deleted");
}
void display()
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\t",temp->data);
}
