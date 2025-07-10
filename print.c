#include<stdio.h>
void hello();
int main()
{
    void (*w1)()=&hello;
    w1();
}
void hello()
{
    printf("Hello World");
}