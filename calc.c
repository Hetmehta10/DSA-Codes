#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b,choice,i,c=1;
    while(1){
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Power\n6. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &a,&b);
                printf("Addition = %d", (a+b));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &a,&b);
                printf("Subtraction = %d", (a-b));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &a,&b);
                printf("Multiplication = %d", (a*b));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &a,&b);
                printf("Division = %d", (a/b));
                break;
            case 5:
                printf("Enter two numbers: ");
                scanf("%d %d", &a,&b);
                for(i=0;i<b;i++)
                c=c*a;
                printf("Power of %d to %d is %d",a,b,c );
                break;
            default:
            exit(1);     
        }
    }
}