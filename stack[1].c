#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void push();
void pop();
void display();

int stack[MAX];
int top = -1;

int main(){
    int choice, n;
    while(1){
        printf("\nEnter your choice: ");
        printf("\n1. push\n2. pop\n3. display\n4. exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2 :
                pop();
                break;
            case 3 :
                display();
                break;
            case 4:
                exit(1);
                break;
            default :
                printf("\nWrong choice.");
        }
    }
}

void push(){
    int n ;
    if( top>=MAX-1 ){
        printf("\nOverflow");
    }
    else{
        top = top + 1;
        printf("\n Enter an integer: ");
        scanf("%d", &n);
        stack[top] = n;
    }
}

void pop(){
    if(top == -1){
        printf("\nUnderflow");
    }
    else{
        top = top - 1;
    }
}

void display(){
    int i = 0;
    if(top == -1){
        printf("\nUnderflow");
    }
    else{
        while(i<=top){
            printf(" %d ", stack[i]);
            i++;
        }
    }
}