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

//deletion at the beginning
void deleteAtBeg(struct node* temp){
    struct node* current=temp;
    temp=temp->next;
    free(current);
    printf("After deleting the first node\n");
    display(temp);
}

//deletion of node at a particular position
void deleteAtPos(struct node* temp, int pos){
    struct node* current=temp;
    if(pos<1|| current==NULL){
        printf("There is no node to be deleted!!\n");
    }
    if(pos==1){
        deleteAtBeg(current);
    }
    else{
        for(int i=1;i<pos-1;i++){
            current=current->next;
        }
        current->next=current->next->next;
        display(temp);
    }
}

//deletion of node at the end
void deleteAtEnd(struct node* temp){
    struct node* current=temp;
    while(current->next->next!=NULL){
        current=current->next;
    }
    current->next=NULL;
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
    //deleting a node
    int choice;
    printf("\n1. Deleting at the Beginning of LL \n");
    printf("2. Deleting at the particular position \n");
    printf("3. Deleting at the end of the LL \n");
    printf("Choose any option 1/2/3\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:{
            deleteAtBeg(temp);
            break;
        }
        case 2:{
            printf("Enter a position at which the node to be deleted: ");
            int pos;
            scanf("%d",&pos);
            printf("\n");
            deleteAtPos(temp,pos);
            break;
        }
        case 3:{
            deleteAtEnd(temp);
            break;
        }
        default:{
            printf("Invalid choice\n");
        }
    }
    return 0;
}
