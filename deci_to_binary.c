#include<stdio.h>
int binary(int bin)
{
    int rem=0,b=bin,r;
    while(b>0)
    {
        rem+=1;
        b=b/2;
    }
    int a[rem];
    for(int i=0;i<rem;i++)
    {
        r=bin%2;
        a[i]=r;
        bin/=2;
    }
    for(int i=(rem-1);i>=0;i--)
    {
        printf("%d",a[i]);
    }
}
int main()
{
    int a;
    printf("Enter a decimal number: ");
    scanf("%d",&a);
    binary(a);
}