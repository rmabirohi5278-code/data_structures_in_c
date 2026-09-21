#include <stdio.h>
#include <stdlib.h>

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

//Insertion at the beginning
void InsertAtBeg(struct node* temp,int value){
    struct node* newNode=create(value);
    newNode->next=temp;
    temp=newNode;
    display(temp);
}

//Insertion of node at a particular position
void InsertAtPos(struct node* temp, int pos,int value){
        struct node* current=temp;
        struct node* prev=NULL;
        struct node* newNode=create(value);
        for(int i=1;i<pos-1;i++){
            current=current->next;
        }
        prev=current->next;
        current->next=newNode;
        newNode->next=prev;
        display(temp);
    }
//Insertion of node at the end
void InsertAtEnd(struct node* temp,int value){
    struct node* current=temp;
    struct node* newNode=create(value);
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    display(temp);

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
    //Insertion a node
    int choice;
    printf("\n1. Inserting at the Beginning of LL \n");
    printf("2. Inserting at the particular position \n");
    printf("3. Inserting at the end of the LL \n");
    printf("Choose any option 1/2/3\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            printf("Enter a value to be Inserted: ");
            int value;
            scanf("%d",&value);
            printf("\n");
            InsertAtBeg(temp,value);
            break;
        }
        case 2:{
            printf("Enter a position at which the node to be Inserted: ");
            int pos;
            scanf("%d",&pos);
            printf("\n");
            printf("Enter a value to be inserted: ");
            int value;
            scanf("%d",&value);
            printf("\n");
            InsertAtPos(temp,pos,value);
            break;
        }
        case 3:{
            int value;
            printf("Enter a value to be inserted: ");
            scanf("%d",&value);
            printf("\n");
            InsertAtEnd(temp,value);
            break;
        }
        default:{
            printf("Invalid choice\n");
        }
    }
    return 0;
}
