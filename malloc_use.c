#include<stdio.h>
#include<malloc.h>
int* merge(int arr1[],int arr2[], int n1, int n2)
{
    int i=0,j=0,k=0;
    int* mergearr=(int*)malloc((n1+n2)*sizeof(int));
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            mergearr[k++]=arr1[i++];
        }
        else
        {
            mergearr[k++]=arr2[j++];
        }
    }
    while(i<n1)
        mergearr[k++]=arr1[i++];
    while(j<n2)
        mergearr[k++]=arr2[j++]; 
    return mergearr;       
}
int main()
{
    int i=0,a,b;
    printf("Enter size of 1st array: ");
    scanf("%d",&a);
    int arr1[a];
    for(int j=0;j<a;j+=1)
    {
        printf("Enter %dth term: ",j);
        scanf("%d",&arr1[j]);
    }    
    printf("Enter size of 2nd array: ");
    scanf("%d",&b);
    int arr2[b];
    for(int j=0;j<a;j+=1)
    {
        printf("Enter %dth term: ",j);
        scanf("%d",&arr2[j]);
    }
    int* mergearr=merge(arr1,arr2,a,b);
    printf("[");
    for(i=0;i<(a+b);i++)
    {
        printf("%d,",mergearr[i]);
    }
    printf("]");
}