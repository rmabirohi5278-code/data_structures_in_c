/* we have 3 steps:
        1. find middle of the Linked list(fast and slow pointer).
        2. reverse the right part of the Linked list(right side of slow pointer).
        3. check with head and prev pointer(reversed).
           this is checking like forwarded with reversed one.*/
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
//to find a middle
struct node* middle(struct node* temp){
    struct node* fast=temp;
    struct node* slow=temp;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}
struct node* reverse(struct node* temp){
    struct node* next=NULL, *prev=NULL;
    struct node* curr=middle(temp);
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
//comparing forward and backward
void compare(struct node* temp1){
    struct node* head1=temp1;
    struct node* head2=reverse(temp1);
    int true=0;
    while(head2!=NULL){
        if(head1->data==head2->data){
            true=1;
            head1=head1->next;
            head2=head2->next;
        }
        else{
            true=0;
            break;
        }
    }
    if(true){
        printf("This Linked list is a palindrome!!\n");
    }
    else{
        printf("This Linked list is not a palindrome!!\n");
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
    compare(temp);
    return 0;
}
