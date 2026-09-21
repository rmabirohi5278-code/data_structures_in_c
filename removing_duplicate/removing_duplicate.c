/*This program is for unsorted linked list. for sorted just one while loop is enough. but steps are same.
comparing with current->data==current->next->data.*/
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
//to remove duplicate elements in a ll.
void removingDuplicate(struct node* head){
    struct node* current=NULL;
    struct node* prev=head;
    struct node* dummy=NULL;
    //goes until null reaches
    while(prev!=NULL){
        current=prev;
        //we are checking the current next. so it should not be null.
        while(current->next!=NULL){
            if(prev->data==current->next->data){
                dummy=current->next;
                current->next=current->next->next;
                free(dummy);
            }
            else{
                current=current->next;
            }
        }
        prev=prev->next;
    }
    prev=head;
    printf("Linked list after removing duplicate elements\n");
    display(prev);
}
//main function
int main(){
    int n;
    printf("Enter Number of nodes to be created: ");
    scanf("%d",&n);
    printf("\n");
    int arr[n];
    printf("Enter the values at the nodes one by one: \n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        fflush(stdin);
    }
    struct node* head=NULL, *temp=NULL;
    for(int i=0;i<n;i++){
        struct node* newNode=create(arr[i]);
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
    removingDuplicate(temp);
    return 0;
}
