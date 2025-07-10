#include<stdio.h>
int largest(int *arr,int b);
int main()
{
    int size,result;
    printf("Enter the length of the array: ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter element number: ");
        scanf("%d",&arr[i]);
    }
    result=largest(arr,size);
    printf("%d",result);
}
int largest(int *arr,int b)
{
    int i,max=*arr;
    for(i=0;i<b;i++)
    {
        if(*(arr+i)>max)
            max=*(arr+i);
    }
return max;
}