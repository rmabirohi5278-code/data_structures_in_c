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
//deleting the given element
void deleteElement(struct node* head, int target){
    int found=0;
    struct node* prev=head;
    struct node* next=head->next;
    if (head==NULL){
        printf("No element to be deleted!\n");
    }
    else if (head->data==target){
        struct node * temp=head;
        head=head->next;
        free(temp);
    }
    while(next!=NULL){
        if (next->data==target){
            /*if we put break near free(temp), then this will be deletion of single element. if not , then this will be deletion of occurence of all the particular element*/
            found=1;
            prev->next=next->next;
            struct node* temp=next;
            next=next->next;
            free(temp);
        }
        else{
            prev=next;
            next=next->next;
        }
    }if(found){
    printf("After Deleting the element\n");
    display(head);
    }
    else{
        printf("No such element is found\n");
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
    printf("Enter the element to be deleted: ");
    int target;
    scanf("%d",&target);
    printf("\n");
    deleteElement(temp, target);
    return 0;
}
