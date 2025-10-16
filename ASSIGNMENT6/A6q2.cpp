// Display all the node values in a circular linked list, repeating value of head node at the end too
// Input: 20 → 100 → 40 → 80 → 60,
// Output: 20 100 40 80 60 20.

#include<iostream>
using namespace std;
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void insertbeg(int num){
    struct node *curr=head;
    struct node *temp=new node();

    temp->data=num;
if(head==NULL){
    head=temp;
    temp->next=head;
}
else{
temp->next=head;
while(curr->next!=head){
curr=curr->next;
}
head=temp;
curr->next=head;


}

}

void insertend(int num){
    
    struct node *curr=head;
    struct node *temp=new node();

    temp->data=num;
if(head==NULL){
    head=temp;
    temp->next=head;
}
else{

while(curr->next!=head){
curr=curr->next;
}
curr->next=temp;
temp->next=head;


}
}

void display(){
    struct node *curr=head;
    do{
        cout<<curr->data<<"->";
        curr=curr->next;
    }while(curr->next!=head);


    cout<< head->data <<endl;
}

int main(){
    insertbeg(20);
    insertend(100);
    insertend(40);
    insertend(80);
    insertend(60);
    display();

}
