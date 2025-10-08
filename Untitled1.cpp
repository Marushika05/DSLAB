#include <iostream>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};

struct Node *head=NULL;

void createlist(){
	//struct Node *temp =(struct Node*) malloc(sizeof(struct Node));
	struct Node* temp = new Node(); 
	int num;
	cout<<"enter the number: "<<endl;
	cin>>num;
	temp->data=num;
	temp->next=NULL;
	
	
}
void insertbeg(int newdata) {
   struct Node* newnode = new Node();   
   newnode->data = newdata;            
   newnode->next = head;                
   head = newnode;                      
}

void insertend(int newdata){
	struct Node* newnode= new Node();
		struct Node* curr=head;
		while(curr->next!=NULL){
			curr=curr->next;
			
		}
		curr->next=newnode;
		newnode->next=NULL;
		newnode->data=newdata;
		
	 
}

void delbeg(){
	struct Node *temp= new Node();
	temp=head;
	head=head->next;
	delete(temp);
}

void delend(){
	struct Node *curr= new Node();
	struct Node *prev= new Node();

	
	curr=head;
	//curr=curr->next
	while(curr->next!=NULL){
	    prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	delete(curr);
}
void delnode(){
	struct Node *curr=new Node();
	struct Node *prev=new Node();
	//to delete value 3;
	curr=head;
	while(curr->data!= 3){
		prev=curr;
		curr=curr->next;
		
	}
	prev->next=curr->next;
	delete(curr);
	
}

void display(){
	struct Node* curr=head;
	while(curr!=NULL){
	cout<<curr->data<<"-> ";
	curr=curr->next;
		
	}
	cout<<endl;
}
int main(){
	struct Node* head = NULL;
	insertbeg(1);
	insertbeg(2);
	insertbeg(3);
	insertend(4);
	insertbeg(5);
	display();
	delbeg();
	display();
	delend();
	display();
	insertbeg(7);
	insertbeg(9);
	insertbeg(8);
	display();
	delnode();
	display();
	
}
