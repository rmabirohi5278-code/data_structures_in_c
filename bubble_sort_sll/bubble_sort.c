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
//bubble sort
void bubbleSort(struct node* head){
    int swapped;
    struct node* temp;
    struct node* track=NULL;
    do{
        swapped=0;
        temp=head;
        while(temp->next!=track){
            if(temp->data>temp->next->data){
                int dummy=temp->data;
                temp->data=temp->next->data;
                temp->next->data=dummy;
                swapped=1;
            }
            temp=temp->next;
        }
        track=temp;
    }while(swapped);
    temp=head;
    printf("\n");
    printf("After Bubble sorting\n");
    display(temp);
}
//main function
int main(){
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
    bubbleSort(temp);
    return 0;
}
