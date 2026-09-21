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
//to rotate the linked list by n position
void rotation(struct node* temp, int pos){
    struct node* current=temp;
    //counting the nodes to check whether the pos exceeds the length of ll.
    int count=0;
    while(current!=NULL){
        current=current->next;
        count++;
    }
    current=temp;
    if(pos>count){
        pos%=count;
    }
    //converting this sll -->cll.
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=temp;
    for (int i=0;i<pos;i++){
        current=current->next;
    }
    temp=current->next;
    current->next=NULL;
    current=temp;
    printf("\n");
    printf("After circulating the linked list by position %d.\n",pos);
    display(current);
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
    printf("Enter the number to rotate the linked list: ");
    int pos;
    scanf("%d",&pos);
    printf("\n");
    rotation(temp, pos);
    return 0;
}
