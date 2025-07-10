#include <stdio.h>
int ones(int nums)
{
    int count = 0;
    while (nums)
    {
        nums &=(nums - 1);
        count++;
    }
    return count;
}
int main() 
{
    int num,one;
    printf("Enter an integer: ");
    scanf("%d", &num);
    one= ones(num);
    printf("Number of 1s in %d: %d\n", num, one);
return 0;
}