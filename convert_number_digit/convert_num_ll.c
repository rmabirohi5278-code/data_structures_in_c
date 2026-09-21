#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//blueprint of structure
struct node{
    int data;
    struct node* next;
};

//creation of each node
struct node* create(int value){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}
//displaying the content of each node
void display(struct node* temp){
    printf("Displaying the contents in each nodes: ");
    while(temp->next!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
    printf("\n");
}

//main function
int main(){
    int n;
    printf("Enter Number to convert into numbers: ");
    scanf("%d",&n);
    printf("\n");
    char number[20];
    sprintf(number,"%d",n);
    struct node* head=NULL, *temp=NULL;
    for(int i=0;number[i]!='\0';i++){
        int value=number[i]-'0';
        struct node* newNode=create(value);
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            temp->next=newNode;
            temp=temp->next;
        }
    }
    temp=head;
    display(temp);
    temp=head;
    return 0;
}
