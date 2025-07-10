#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *temp;
void ins_beg(struct node*);
void ins_end(struct node*);
void del_beg();
void del_end();
void traverse();
int main(){
    int choice, n;
    struct node *new1;
    while(1){
        printf("\nEnter your choice: ");
        printf("1. ins_beg\n2. ins_end\n3. del_beg\n4. del_end\n5. traverse\n6. exit");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                new1 = (struct node*)malloc(sizeof(struct node));
                printf("\nEnter the data: ");
                scanf("%d", new1->data);
                new1->next = NULL;
                ins_beg(new1);
                break;
            case 2:
                new1 = (struct node*)malloc(sizeof(struct node));
                printf("\nEnter the data: ");
                scanf("%d", new1->data);
                new1->next = NULL;
                ins_end(new1);
                break;
            case 3:
                del_beg();
                break;
            case 4:
                del_end();
                break;
            case 5:
                traverse();
                break;
            default:
                exit(1);
        }
    }
}
void ins_beg(struct node *new1){
    if(head == NULL)
        head = new1;
    else{
        new1->next = head;
        head = new1;
    }
}
void ins_end(struct node *new1){
    temp = head;
    if(head == NULL)
        head = new1;
    else{
        while(temp->next != NULL){
            temp = temp->next;
        temp->next = head;
        }
    }
}
void del_beg(){
    if(head == NULL)
        printf("Nothing to delete");
    else{
        head = head -> next;
    }
}
void del_end(){
    struct node *temp = head;
    struct node *temp1 = head;
    if(head == NULL)
        printf("Nothing to delete");
    else{
        while(temp->next != NULL){
            temp = temp1;
            temp1 = temp1->next;
        }
        if(temp1 == head)
            head = NULL;
        else
            temp -> next = NULL;
    }
}
void traverse(){
    struct node *temp = head;
    if(head == NULL)
        printf("Nothing to traverse.");
    else{
        while(temp -> next != NULL){
            printf("%d", temp->data);
            temp = temp->next;
        }
    }
}