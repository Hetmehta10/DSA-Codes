#include<stdio.h>
void hello();
void world();
void pr(void (*v1)(), void (*v2)());
int main()
{
    pr(hello, world);
}
void hello()
{
    printf("Hello");
}
void world()
{
    printf("World");
}
void pr(void (*v1)(), void (*v2)())
{
    v1();
    v2();
}