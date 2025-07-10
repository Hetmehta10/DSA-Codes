#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <stdint.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};
int8_t count=0;
struct node *head = NULL;
//struct node *temp;

void ins_beg(struct node*);
void ins_end(struct node*);
void del_beg();
void del_end();
void traverse1();
void traverse2();
void ins_spec(struct node*,int);
void del_spec(int);

int main(){
	int choice, n;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. ins_beg\n2. ins_end\n3. del_beg\n4. del_end\n5. traverse1\n6. traverse2\n7. ins_spec\n8. del_spec\n9. count\n10. exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d", &new1->data);
					new1->next = NULL;
					new1->prev = NULL;
					ins_beg(new1);
					break;
			case 2:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					new1->prev = NULL;
					ins_end(new1);
					break;
			case 3:
					del_beg();
					break;
					
			case 4:
					del_end();
					break;
			case 5:
					traverse1();
					break;
			case 6:
					traverse2();
					break;
			case 7:
			        printf("Enter the position you want to add data: ");
			        scanf("%d",&n);
			        new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d", &new1->data);
					new1->next = NULL;
					new1->prev = NULL;
					ins_spec(new1,n);
					break;
			case 8:
			        printf("Enter the position you want to delete data: ");
			        scanf("%d",&n);
			        del_spec(n);
			        break;
			case 9:
			        printf("Total element present is: %d",count);
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
			head->prev = new1;
			new1->next = head;
			head = new1;
		}
		count+=1;
	}
	
	void ins_end(struct node *new1){
		struct node *temp = head;
		if(head == NULL)
			head = new1;
		else{
			while(temp->next!= NULL)
				temp = temp->next;
			new1->prev = temp;
			temp->next = new1;
			}
		count+=1;
		}
		
	void del_beg(){
		struct node *temp = head;
		if(head == NULL)
			printf("no item to delete\n");
		else{
			head = head->next;
			head->prev = NULL;
			free(temp);
			temp = NULL;
		}
		count-=1;
	}
	
	void del_end(){
		struct node *temp = head;
		struct node *temp1 = head;
		
		if(head == NULL)
			printf("no item to delete\n");
		else{
			while(temp1->next != NULL){
				temp = temp1;
				temp1 = temp1->next;
				}
	    	if(temp1 == head)
	    		head = NULL;
			else
			 	temp->next = NULL;
			 	temp1->prev = NULL;
				free(temp1);
				temp1 = NULL;
			}
		count-=1;
	}

	void traverse1(){
		struct node *temp = head;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	
	void traverse2(){
	struct node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->prev;
			}
	}
	
	void ins_spec(struct node *new1,int n){
	    struct node *temp=head;
        struct node *temp1=head;
        int i;
		if(n<=count){
        	if(head==NULL){
             	head=new1;
				count+=1;
			}
        	else{
       
            	if(n==1){
                	ins_beg(new1);
					count+=1;
			}
            	else{
                	for(i=1;i<n;i++){
                    	temp1=temp;
                    	temp=temp->next;
                	}
                	temp1->next=new1;
                	new1->prev=temp1;
                	new1->next=temp;
                	temp->prev=new1;
            	}
				count+=1;
        	}
		}
		else if(n==count+1){
        ins_end(new1);
    }
    else
        printf("Numnber of nodes exceeded\n");
    
	}
	
void del_spec(int n){
	struct node *temp=head;
    struct node *temp1=head;
    struct node *temp2 = head;
    int i;
    if(head==NULL)
        printf("Nothing to delete");
    else{
        if(n==1)
            del_beg();
       else{
            for(i=1;i<n;i++){
                temp2=temp1;
                temp1=temp;
                temp=temp->next;
            }
            temp2->next=temp1->next;
            temp->prev=temp2;
            temp->next=temp1->next;
            free(temp1);
            temp1=NULL;
       }
    }
    count-=1;
	}