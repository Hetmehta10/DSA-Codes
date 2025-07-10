#include<stdio.h>
void add(int a)
{
    int b,sum=0,i=0;
    while(i<3)
    {
        b=a%10;
        sum=sum+b;
        a=a/10;
        i+=1;
    }
    printf("The sum of digit of 3 digit number = %d",sum);
}
int main()
{
    int a;
    printf("Enter the 3 digit number: ");
    scanf("%d",&a);
    add(a);
}