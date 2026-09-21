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

//to find the nth node from the end
void findingByFast_Slow(struct node* head,int pos){
    struct node* fast=head;
    struct node* slow=head;
    /*here the logic is (both pointers first points to the same address), but by keeping their distance as the n we can easily find the nth node from end*/
    //fast-slow=n;
    for (int i=0;i<pos;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    printf("\n");
    printf("This is by Fast and Slow Pointer Method!!\n");
    printf("The value at the position \'%d\' from end is %d\n",pos,slow->data);
}
//This is by actually reversing the linked list
void findingByReversing(struct node* head, int pos){
    struct node* current=head;
    struct node *next=NULL, *prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    for (int i=1;i<pos;i++){
        prev=prev->next;
    }
    printf("\n");
    printf("This is by Actually Reversing the Linked List!");
    printf("The value at the position \'%d\' is %d",pos, prev->data);
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
    printf("Enter the position from where the element to be find: ");
    int pos;
    scanf("%d",&pos);
    printf("\n");
    findingByFast_Slow(temp,pos);
    temp=head;
    findingByReversing(temp, pos);
    return 0;
}
