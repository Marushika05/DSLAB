// Write a program to reverse a linked list.
// Input: 1->2->3->4->NULL
// Output: 4->3->2->1->NULL
#include<iostream>
using namespace std;

//creating a struct node and func to add elem at the end of the list and display func
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

void insertbeg(int newdata){
    struct Node*newnode=new Node();//creating a new node
    newnode->data=newdata;
    newnode->next=head;
    head= newnode; // assign newnode as the heads


}//before inserting at end we will always need a beg otherwise temp=null
void insertend(int num){
struct Node *newnode=new Node();
struct Node*curr=head;
while(curr->next!=NULL){
    curr=curr->next;
}
curr->next=newnode;
newnode->next=NULL;
newnode->data=num;
}

void display(){
struct Node *temp=head;
while(temp!=NULL){//if temp->next is used then last value wont bhi diplayed as its next is null
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<endl;
}

void reverse(){
    //to reverse a linked list we need three pts, prev,curr and next;
    // initialize prev to null
    struct Node *curr=head;
    struct Node *prev=NULL;
    struct Node *next=NULL;
    
while(curr!=NULL){
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
}
head=prev;
}

int main(){
    insertbeg(1);
    insertend(2);
    insertend(3);
    insertend(4);
    display();
    reverse();
    display();
}
