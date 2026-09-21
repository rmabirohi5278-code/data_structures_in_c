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
//separating negative, positive in two different ll's. if we needed can concatenate it
void separating(struct node* temp){
    struct node* dummy=temp;
    struct node* negHead=NULL, *posHead=NULL;
    struct node* neg=NULL, *pos=NULL;
    while(temp!=NULL){
        if(temp->data<0){
            if(neg==NULL){
                neg=temp;
                negHead=temp;
            }
            else{
                neg->next=temp;
                neg=neg->next;
            }
        }else{
            if(pos==NULL){
                pos=temp;
                posHead=temp;
            }
            else{
                pos->next=temp;
                pos=pos->next;
            }
        }
        temp=temp->next;
    }
    if(pos!=NULL){pos->next=NULL;}
    if(neg!=NULL){neg->next=NULL;}
    neg=negHead;
    pos=posHead;
    printf("\n");
    printf("Negative Values in this LL\n");
    display(neg);
    neg=negHead;
    printf("\n");
    printf("Positive values in this LL\n");
    display(pos);
    pos=posHead;
    printf("\n");
    printf("Do you need as neg-pos(single List): 1/2");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        while(neg->next!=NULL){
            neg=neg->next;
        }
        neg->next=pos;
        neg=negHead;
        display(neg);
    }
    else{
        return;
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
    separating(temp);
    free(head);
    return 0;
}
