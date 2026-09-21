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

//to detect loop in sll
void detectionOfLoop(struct node* temp){
    struct node* fast=temp;
    struct node* slow=temp;
    int loop=0;
    //here the concept is when fast==slow then there will be a loop
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if (slow==fast){
            loop=1;
            break;
        }
    }
    if (loop==1){
        printf("\n");
        printf("Loop is found in the SLL!!\n");
    }
    else{
        printf("\n");
        printf("No Loop is found in this SLL!!\n");
    }
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
    detectionOfLoop(temp);
    return 0;
}
