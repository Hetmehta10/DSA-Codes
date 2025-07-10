#include<stdio.h>
#include<malloc.h>
int* danglingptr()
{
    int* ptr=(int*)malloc(sizeof(int));
    *ptr=100;
    free(ptr);
    return ptr;
}
int main()
{
    int* dangling= danglingptr();
    printf("%d",*dangling);
}