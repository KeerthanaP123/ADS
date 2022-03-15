#include<stdio.h>
void main()
{
int arr1[100],arr2[100],arr3[100],size,size2,i,j,k,temp=0;
printf("Enter the size of first array:");
scanf("%d",&size);
printf("\nEnter the elements of first array:\n");
for(i=0;i<size;i++)
scanf("%d",&arr1[i]);
for(i=0;i<size;i++)
{
for(j=i+1;j<size;j++)
{
if(arr1[i]>arr1[j])
{
temp=arr1[i];
arr1[i]=arr1[j];
arr1[j]=temp;
}
}
}
printf("The first sorted array is:\n");
for(i=0;i<size;i++)
printf("%d\t",arr1[i]);
printf("\nEnter the size of second array:");
scanf("%d",&size2);
printf("\nEnter the elements of second array:\n");
for(i=0;i<size2;i++)
scanf("%d",&arr2[i]);
for(i=0;i<size2;i++)
{
for(j=i+1;j<size2;j++)
{
if(arr2[i]>arr2[j])
{
temp=arr2[i];
arr2[i]=arr2[j];
arr2[j]=temp;
}
}
}
printf("The second  sorted array is\n");
for(i=0;i<size2;i++)
printf("%d\t",arr2[i]);
printf("\nThe combined sorted array is:");
for(i=0;i<size;i++)
{
arr3[i]=arr1[i];
}
k=size;
for(i=0;i<size2;i++)
{
arr3[k]=arr2[i];
k++;
}
for(i=0;i<(size+size2);i++)
{
for(j=i+1;j<(size+size2);j++)
if(arr3[i]>arr3[j])
{
temp=arr3[i];
arr3[i]=arr3[j];
arr3[j]=temp;
}
}
for(i=0;i<(size+size2);i++)
printf("%d\t",arr3[i]);
}
