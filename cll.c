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
        printf("\nEnter your choice");
        printf("1. insbeg\n2. insend\n3. delbeg\n4. delend\n5. traverse\n6. exit");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                new1 = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data");
                scanf("%d", &new1->data);
                new1->next = NULL;
                ins_beg(new1);
                break;
            case 2:
                new1 = (struct node*)malloc(sizeof(struct node));
                printf("Enter the data");
                scanf("%d", &new1->data);
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
    struct node *temp = head;
    if(head == NULL){
        head = new1;
        head -> next = head;
    }
    else{
        while(temp->next!=head)
            temp = temp->next;
        new1->next = head;
        temp->next = new1;
        head = new1;
    }
}
void ins_end(struct node *new1){
    struct node *temp = head;
    if(head == NULL){
        head = new1;
        head -> next = head;
    }
    else{
        while(temp->next!=head)
            temp = temp->next;
        new1->next = head;
        temp->next = new1;
    }
}
void del_beg(){
    struct node *temp = head;
    struct node *temp1 = head;
    if(head == NULL){
        printf("Nothing");
    }
    else if(head -> next == head){
        printf("Item deleted from the head = %d", head->data);
        head = NULL;
    }
    else{
        while(temp->next!=head)
            temp = temp->next;
        printf("Item deleted from the head = %d", head->data);
        head = head->next;
        temp->next = head;
        free(temp);
        temp1 = NULL;
    }
}
void del_end(){
    struct node *temp = head;
    struct node *temp1 = head;
    if(head == NULL){
        printf("Nothing");
    }
    else if(head -> next == head){
        head = NULL;
        free(temp);
    }
    else{
        while(temp->next!=head){
            temp1 = temp1->next;
        }
        while(temp->next != temp1){
            temp = temp->next;
        }
        temp1->next = NULL;
        temp->next = head;
        free(temp1);
        temp1=NULL;
    }
}
void traverse(){
    struct node *temp = head;
    if(head == NULL)
        printf("Nothing");
        else{
            do{
                printf("%d", temp->data);
                temp = temp->next;
            }while(temp!=head);
        }
}