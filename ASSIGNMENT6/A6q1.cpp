#include<iostream>
using namespace std;
//doubly linked list
struct node{
	int data;
	struct node *prev ,*next;
};
struct node *head=NULL;

void insertbeg(int num){
	struct node *temp= new node();
	temp->data=num;
	temp->next=temp->prev=NULL;
	if(head==NULL){
	     head=temp;
	}
	else{
		
	    temp->next=head;
	    head->prev=temp;
	    head=temp;
	}
}
	
	
void insertend(int num){
	struct node *temp= new node();
	temp->data=num;
	temp->next=temp->prev=NULL;
	struct node* curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->next=temp;
	temp->prev=curr;
	
}	

void insertspecific(int num){
	struct node *temp= new node();
	temp->data=num;
	temp->next=temp->prev=NULL;
	struct node* curr=head;
	//suppose we want to insert after 2
	while(curr->data!=2){
		curr=curr->next;
	}
 
	temp->prev=curr;
	temp->next=curr->next;
	curr->next=temp;
	temp->next->prev=temp;
}

void delbeg(){
		struct node* curr=head;
		head=head->next;
		head->prev=NULL;
		delete(curr);
		
}
void delend(){
	struct node* curr=head;
	while(curr->next!=NULL){
		curr=curr->next;
	}
	curr->prev->next=NULL;
	delete(curr);
	
}
void delspecific(){
	//suppose have to delete 10
	struct node* curr=head;
	while(curr->data!=10){
		curr=curr->next;
	}
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;
	delete(curr);
	
}

void nodesearch(int num){
	struct node*curr=head;
	int count=0;
	while(curr->next!=NULL){
		if(head->data==num){
			cout<<"found at head";
			break;
		}
		else{
		
		while(curr->data!=num){
			curr=curr->next;
			count++;
		}
		cout<<"found at:"<<count+1<<endl;
		break;
		
	}
		
		
	}

	
}
void display(){
	struct node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
}

int main(){
	insertbeg(2);
	insertbeg(1);
	insertend(3);
	insertend(4);
	insertend(5);
	insertspecific(8);
	
	display();
	delbeg();
	delend();
	insertend(9);
	insertend(10);
	insertend(11);
	display();
	delspecific();
	nodesearch(9);
	//nodesearch(12);
	display();
	
}
