#include<stdio.h>
void swap(int *x,int *y);
int main()
{
    int a,b;
    printf("Enter the number: ");
    scanf("%d %d",&a,&b);
    swap(&a,&b);
}
void swap(int *x,int *y)
{
    *x=(*x^*y);
    *y=(*x^*y);
    *x=(*x^*y);
    printf("%d %d",*x,*y);
}