#include<stdio.h>
#include<malloc.h>
struct abc{
    int id;
    char name[30];
    int salary;
    struct abc *ptr1;
    struct abc *ptr2;
};
void show(struct abc *a){ printf("Name:%s\nID:%d\nSalary:%d\n",a->name,a->id,a->salary);}
void inc(struct abc *a)
{
    int inc;
    printf("Enter the increment in salary: ");
    scanf("%d",&inc);
    a->salary=a->salary +inc;
}
void dec(struct abc *a)
{
    int dec;
    printf("Enter the decrement in salary: ");
    scanf("%d",&dec);
    a->salary=a->salary -dec;
}
int main()
{
    int i=0,b=1,c;
    struct abc *x,*y,*z,*a;
    x=(struct abc*)malloc(sizeof(struct abc));
    y=(struct abc*)malloc(sizeof(struct abc));
    z=(struct abc*)malloc(sizeof(struct abc));
    x->ptr1=y;
    x->ptr2=NULL;
    y->ptr1=z;
    y->ptr2=x;
    z->ptr1=NULL;
    z->ptr2=y;
    a=x;
    while(i<3)
    {
        printf("Enter id: ");
        scanf("%d",&(a->id));
        printf("Enter salary and name: ");
        scanf("%d %[^\n]s",&(a->salary),&(a->name));
        a=a->ptr1;
        i+=1;
    }
    a=x;
    while(b!=0)
    {
        printf("Enter Your Choice\n1)To increase salary of current employee\n2)To decrease salary of current employee\n3)To Show details of current employee\n4)To Go to next employee\n5)To Go to previous employee\n6)Quit: ");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
                inc(a);
                break;
            case 2:
                dec(a);        
                break;
            case 3:
                show(a);
                break;
            case 4:
                if(a->ptr1==NULL)
                    printf("No Next employee\n");
                else    
                    a=a->ptr1;
                break;    
            case 5:
                if(a->ptr2==NULL)
                    printf("No previous employee\n");
                else    
                    a=a->ptr2;
                break;
            case 6:
                b=0; 
                break;   
            default:
                printf("Wrong choice");
        }
    }
}