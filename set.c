#include<stdio.h>
#include<stdlib.h>
int set1[50];
int set2[50];
int set3[50];
int n,m,i;
void intersection();
void Union();
void difference();
void main()
{
    int choice;
    printf("No. of elements first set : ");
    scanf("%d",&n);
    printf("No. of elements in second set : ");
    scanf("%d",&m);
    if(n==m)
    {
    printf("Elements in first set : ");
    for(i=0;i<n;i++)
        scanf("%d",&set1[i]);
    printf("Elements in second set : ");
    for(i=0;i<m;i++)
        scanf("%d",&set2[i]);
    while(1)
    {
        printf("\n***MENU***");
        printf("\n1 : Union");
        printf("\n2 : Intersection");
        printf("\n3 : Difference");
        printf("\n4 : Exit");
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:Union(set1,set2,n);
            break;
            case 2:intersection();
            break;
            case 3:difference();
            break;
            case 4:exit(0);
            default:printf("Invalid choice");
            break;

        }
    }
    }
    else
    {
     printf("Limits are not same");
    }
}
void Union(int set1[],int set2[],int n)
{
    printf("Union of set is = ");
    for(i=0;i<n;i++)
        {
        set3[i]=set1[i]||set2[i];
        printf("%d",set3[i]);
         }
}
void intersection()
{
    int i;
    printf("Intersection of two set is : ");
    for(i=0;i<n;i++)
    {
        if(set1[i]==1&&set2[i]==1)
        {
            set3[i]=1;
        }
        else
        {
            set3[i]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",set3[i]);
    }

}
void difference()
{
    int i;
    printf("Difference of two set is : ");
    for(i=0;i<n;i++)
    {
        set3[i]=!set1[i]&&set2[i];
        printf("%d",set3[i]);
    }
}
