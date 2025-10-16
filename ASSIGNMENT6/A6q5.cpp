
// Write a program to check if a linked list is Circular Linked List or not.
// LinkedList: 2->4->6->7->5
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node*head=NULL;
void insertbeg(int num)
{
    struct node *newnode = new node();
    newnode->data = num;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head; 
    }
    else
    {
        struct node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = newnode;
        newnode->next = head;
        head = newnode; 
    }
}

void insertend(int num)
{
    struct node *temp = new node();
    struct node *curr = head;
    temp->data = num;
    // struct node*prev=NULL;
    while (curr->next != head)
    {
        // prev=curr;
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = head;
}
void display(){
    struct node *curr=head;
    do{
        cout<<curr->data<<" ->";
        curr=curr->next;
    }while(curr!=head);
}
bool isCircular() {
    if (head == NULL)
        return false;

    struct node *curr = head->next;

    while (curr != NULL && curr != head) { //we need null because what if not circular list
        curr = curr->next;
    }

    return (curr == head);
}


int main(){
    insertbeg(2);
    insertend(4);
    insertend(6);
    insertend(7);
    insertend(8);
    display();
    cout<<endl;
    if(isCircular()){
        cout<<"is circular"<<endl;
    }
    else{
        cout<<"not circular"<<endl;
    }
    

}
