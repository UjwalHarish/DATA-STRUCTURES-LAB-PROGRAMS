#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void create();
void display();
void insert_head();
void insert_last();
void insert_val();
void delete_head();
void delete_last();
void delete_val();

struct Node
{
    int data;
    struct Node *link;
};
typedef struct Node node;
node *start=NULL;

void main()
{
    int ch;
    while(1)
    {
        printf("\n1.Create\n2.Display \n3.Insert Head \n4.Insert Last\n5.Insert val\n6.Delete Head\n7.Delete Last\n8.Delete val\n9.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_head();
            break;
        case 4:
            insert_last();
            break;
        case 5: insert_val();
            break;
        case 6: delete_head();
            break;
        case 7:delete_last();
            break;
        case 8:delete_val();
            break;
        case 9:
            exit(1);

        default:
            printf("Invalid choice\n");
        }
    }
}

void create()
{
    int c;
    node *new,*curr;
    start=(node *) malloc(sizeof(node));
    curr=start;
    printf("Enter element\n");
    scanf("%d",&start->data);
    while(1)
    {
        printf("Do you want to add another element(1/0)\n");
        scanf("%d",&c);
        if(c==1)
        {
            new=(node *) malloc(sizeof(node));
            printf("Enter element\n");
            scanf("%d",&new->data);
            curr->link = new;
            curr=new;
        }
        else
        {
            curr->link=NULL;
            break;
        }
    }
}
void display()
{
    node *temp;
    if(start==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->link;
    }
}
void insert_head(){
    node *temp,*mew;
    mew = (node *) malloc(sizeof(node));
    temp = start;
    printf("enter element value");
    scanf("%d",&mew->data);
    mew->link = start;
    start = mew;
}
void insert_last(){
    node *new,*temp;
    new = (node *) malloc(sizeof(node));
    temp = start;
    printf("enter element value");
    scanf("%d",&new->data);
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = new;
    new->link = NULL;
}
void insert_val(){
        node *new,*ptr,*prevptr;
        int val;
    new = (node *) malloc(sizeof(node));
    ptr = start;
    prevptr = start;
    printf("enter element value");
    scanf("%d",&new->data);
    printf("enter value in between where to enter");
    scanf("%d",&val);
    while(ptr->link !=val){
        prevptr = ptr;
        ptr = ptr->link;
    }
    prevptr->link = new;
    new->link = ptr;
}
void delete_head(){
    node *ptr;
    ptr = start;
    start=start->link;
    free(ptr);
}
void delete_last(){
    node *ptr,*prevptr;
    ptr = start;
    prevptr = start;
    while(ptr->link != NULL){
        prevptr = ptr;
        ptr = ptr->link;
    }
    prevptr->link = NULL;
    free(ptr);
}
void delete_val(){
    int val;
    node *ptr,*prevptr;
    prevptr = start;
    ptr = start;
    printf("enter value to be deleted");
    scanf("%d",&val);
    while(ptr->data!=val){
        prevptr = ptr;
        ptr = ptr->link;
    }
    prevptr->link = ptr->link;
    free(ptr);
}

