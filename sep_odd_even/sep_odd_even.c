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
//separating odd, even in two different ll's. if we needed can concatenate it
void separating(struct node* temp){
    struct node* dummy=temp;
    struct node* oddHead=NULL, *evenHead=NULL;
    struct node* odd=NULL, *even=NULL;
    while(temp!=NULL){
        if(temp->data%2!=0){
            if(odd==NULL){
                odd=temp;
                oddHead=temp;
            }
            else{
                odd->next=temp;
                odd=odd->next;
            }
        }else{
            if(even==NULL){
                even=temp;
                evenHead=temp;
            }
            else{
                even->next=temp;
                even=even->next;
            }
        }
        temp=temp->next;
    }
    if(odd!=NULL){odd->next=NULL;}
    if(even!=NULL){even->next=NULL;}
    odd=oddHead;
    even=evenHead;
    printf("\n");
    printf("Odd Values in this LL\n");
    display(odd);
    odd=oddHead;
    printf("\n");
    printf("Even values in this LL\n");
    display(even);
    even=evenHead;
    printf("\n");
    printf("Do you need as odd-even(single List): 1/2");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        while(odd->next!=NULL){
            odd=odd->next;
        }
        odd->next=even;
        odd=oddHead;
        display(odd);
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
