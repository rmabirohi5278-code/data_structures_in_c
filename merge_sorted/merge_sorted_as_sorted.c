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
//to get two linked list without doing another time
struct node* used(){
    int n;
    printf("Enter Number of nodes to be created: ");
    scanf("%d",&n);
    printf("\n");
    int arr[n];
    printf("Enter the values of each nodes\n");
    for(int i=0;i<n;i++){
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
    return temp;
}
//merging two linked list
void mergingLinkedList(struct node* head1, struct node* head2){
    struct node* resultant=NULL;
    struct node* tempResult=NULL;
    struct node* temp1=head1, *temp2=head2;
    //if 1st ll is null, then the sorted result is 2nd ll.
    if(temp1==NULL){
        resultant=temp2;
    }
    //if 2nd ll is null, then the sorted result is 1st ll.
    if(temp2==NULL){
        resultant=temp1;
    }
    //checking and adding values until both ll have values;
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data<=temp2->data){
            if(resultant==NULL){
                resultant=temp1;
                tempResult=temp1;
            }
            else{
                resultant->next=temp1;
                resultant=resultant->next;
            }
            temp1=temp1->next;
        }
        else{
            if(resultant==NULL){
                resultant=temp2;
                tempResult=temp2;
            }
            else{
                resultant->next=temp2;
                resultant=resultant->next;
            }
            temp2=temp2->next;
        }
    }
    //when 2nd ll has small nodes than 1st ll, this will be executed.
    while(temp1!=NULL){
        resultant->next=temp1;
        resultant=resultant->next;
        temp1=temp1->next;
    }
    //when 1st ll has small nodes than 2nd ll, this will be executed.
    while(temp2!=NULL){
        resultant->next=temp2;
        temp2=temp2->next;
        resultant=resultant->next;
    }
    resultant=tempResult;
    printf("\n");
    printf("Resultant Linked List after merging in correct sorted order\n");
    display(resultant);
}


//main function
int main(){
    printf("Sorted Linked List 1\n");
    struct node* head1=used();
    struct node* head2=used();
    mergingLinkedList(head1, head2);
    return 0;
}
