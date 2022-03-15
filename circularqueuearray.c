#include<stdio.h>
# define max 10
int rear=-1;
int front=-1;
int queue[max];
void main()
{
    int choice;
    printf("-----Menu-----");
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Search\n4.Dispaly\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid");
        }
    }
}
void enqueue()
{
    int value;
    printf("Enter value to inserted:");
    scanf("%d",&value);
    if((front==-1)&&(rear==-1))
    {
        front=0;
        rear=0;
        queue[rear]=value;
        printf("Inserted");
    }
    else if((rear+1)%max==front)
    {
        printf("Overflow");
    }
    else
    {
        rear=((rear+1)%max);
        queue[rear]=value;
        printf("Inserted");
    }
}
void dequeue()
{
    int value;
    if((front==-1)&&(rear==-1))
    {
        printf("Underflow");
    }
    else if(front==rear)
    {
        printf("Value deleted",queue[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Value deleted",queue[front]);
        front=((front+1)%max);
    }
}
void search()
{
    int f=front,value,flag,i,j;
    if(front==-1)
    {
        printf("\nCircular queue is empty");
    }
    else
    {
        printf("\nEnter the element to be searched:");
        scanf("%d",&value);
        while(f!=rear)
        {
            if(f==value)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            front++;
        }
        for(i=0;i<max;i++)
        {
            if(f==value)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
            f++;
        }
        for(j=0;j<rear;i++)
        {
            for(f=front;f<rear;f++)
            {
                if(queue[f]==value)
                {
                    flag=1;
                }
                else
                {
                    flag=0;
                }
            }
        }
        if(flag==1)
        {
            printf("\nElement found\n");
        }
        else
        {
            printf("\nElement not found\n");
        }
    }
}
void display()
{
    int i=front;
    if((front==-1)&&(rear==-1))
    {
        printf("Empty");
    }
    else
    {
        printf("Values are:\n");
        while(i<=rear)
        {
            printf("%d\n",queue[i]);
            i=((i+1)%max);
        }
    }
}
