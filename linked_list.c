#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL; // there is no linked list has been created
struct node *temp; // to navigate the list as we cant move head

void ins_beg(struct node*);//pass the node
void ins_end(struct node*);
void ins_speci();//at specific point
void del_specific();
void search_ele(); //searching specific element enter by the user
void del_beg();
void del_end();
void traverse();

int main(){
	int choice, n;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. ins_beg\n2. ins_end\n3. del_beg\n4. del_end\n5. traverse\n6. ins_speci\n7. del_speci\n8. search_ele\n9. exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_beg(new1);
					break;
			case 2:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
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
            case 6:
                    ins_speci(new1, n);
                    break;
            case 7:
                    del_specific(n);
                    break;
            case 8:
                    search_ele(n);
                    break;
			default:
					exit(0);
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
			while(temp->next!= NULL)
				temp = temp->next;
			temp->next = new1;
			}
		}
		
	void del_beg(){
		if(head == NULL)
			printf("no item to delete\n");
		else
			head = head->next;
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
			}
	}

	
	void traverse(){
		struct node *temp = head;
		if(head == NULL)
			printf("no item to traverse\n");
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
	}
	
	void ins_speci(struct node *new1,int n){
        int i =1, count;
        temp = head;
        struct node *temp1=head;
        if(n<=count){
            if(head==NULL){
                head=new1;
            }
            else{
                temp1=temp->next;
                while(i<n-1){
                    temp = temp->next;
                    temp1 = temp1->next;
                    i++;
                }
                new1->next = temp1;
                temp->next = new1;
            }
            count+=1;
        }
        else
        printf("Number of nodes exceedes\n");
    }

    void del_specific(int n){
    int i=1, count;
    temp=head;
    struct node *temp1=head;
    if(n<=count)
    {
        if(head==NULL)
            printf("There're no nodes to delete\n");
        else{
            temp1=temp->next;
            while(i<n-1)
            {
                temp=temp->next;
                temp1=temp1->next;
                i++;
            }    
            temp->next = temp1->next;
            temp1->next = NULL;    
        }
        count-=1;
    }
    else
        printf("Number of nodes exceeded\n");
}		

    void search_ele(int n){
    int i=1, count;
    temp=head;
    if(n<=count)
    {
        if(head==NULL)
            printf("No nodes to delete\n");
        else{
            temp=temp->next;
            while(i<n-1)
            {
                temp=temp->next;
                i++;
            }    
            printf("Data at %d = %d",n,temp->data);    
        }
    }
    else
        printf("Number of nodes exceeded\n");  
}

