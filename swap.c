#include<stdio.h>
void swap(int *x,int *y,int *z)
{
    int d;
    d=*y;
    *y=*x;
    *x=*z;
    *z=d;
    printf("x=%d , y=%d , z=%d",*x,*y,*z);
}
int main()
{
    int x,y,z;
    printf("Enter the numbers: ");
    scanf("%d %d %d",&x,&y,&z);
    swap(&x,&y,&z);
}