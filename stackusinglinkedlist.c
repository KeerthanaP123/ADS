
        #include <stdio.h>
        #include <stdlib.h>
        void push();
        void pop();
        void search();
        void display();
        struct node
        {
        int val;
        struct node *next;
        };
        struct node *head;

        void main ()
        {
            int choice=0;
            printf("\MENU");

            while(choice != 5)
            {
                printf("\n\nChoose option");
                printf("\n 1.Push\n 2.Pop\n 3.Display\ \n 4.Search\n 5.Exit");
                printf("\n Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    {
                        push();
                        break;
                    }
                    case 2:
                    {
                        pop();
                        break;
                    }
                    case 3:
                    {
                        display();
                        break;
                    }
                    case 4:
                        {
                            search();
                            break;
                        }
                    case 5:
                    {
                        printf("Exiting....");
                        break;
                    }
                    default:
                    {
                        printf(" Invalid choice");
                    }
            };
        }
        }
        void push ()
        {
            int val;
            struct node *ptr = (struct node*)malloc(sizeof(struct node));
            if(ptr == NULL)
            {
                printf("can not to push the element");
            }
            else
            {
                printf("Enter the value:");
                scanf("%d",&val);
                if(head==NULL)
                {
                    ptr->val = val;
                    ptr -> next = NULL;
                    head=ptr;
                }
                else
                {
                    ptr->val = val;
                    ptr->next = head;
                    head=ptr;

                }
                printf("Item pushed");

            }
        }

        void pop()
        {
            int item;
            struct node *ptr;
            if (head == NULL)
            {
                printf("Underflow");
            }
            else
            {
                item = head->val;
                ptr = head;
                head = head->next;
                free(ptr);
                printf("Item popped");

            }
        }
        void display()
        {
            int i;
            struct node *ptr;
            ptr=head;
            if(ptr == NULL)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack elements are\n");
                while(ptr!=NULL)
                {
                    printf("%d\n",ptr->val);
                    ptr = ptr->next;
                }
            }
        }
        void search()
           {
           int item,temp,i=0;
           struct node *ptr;
           ptr=(struct node*)malloc(sizeof(struct node));
            if(ptr==NULL)
            {
                printf("Overflow");
            }
            else(ptr!=NULL);
            {
            printf("Enter the element to be searched:");
            scanf("%d",&item);
            }
            while(ptr!=NULL)
            {
                if(ptr->val=item)
            {

                printf("Element found at %d",i+1);
                temp=0;
                break;
            }

            else
            {
                temp=1;
zz
