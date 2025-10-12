// Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.
// Input: Linked List : 1->2->1->2->1->3->1 , key: 1
// Output: Count: 4 , Updated Linked List: 2->2->3

// lets create a list pehle to add at beg
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertbeg(int num)
{
    struct Node *newnode = new Node();
    newnode->data = num;
    newnode->next = head;
    head = newnode;
}

void display()
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
}
void delkey(int key)
{
  int count=0;
  while(head!=NULL && head->data==key){
     Node *temp = head; //// just point to the node you want to delete
    //  temp=head;
     head=head->next;
     delete(temp);
     count++;
  }
    
    // we will have to define prev and curr
    struct Node *curr = head;
    struct Node *prev = NULL;

    while (curr!=NULL)
    {
        if (curr->data == key)
        {
           
            prev->next = curr->next;
            delete (curr);
            curr=prev->next;
            count++;

        }

        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    cout<<"Your count of the key was: "<<count<<endl;
}

int main()
{
    insertbeg(1);
    insertbeg(3);
    insertbeg(1);
    insertbeg(2);
    insertbeg(1);
    insertbeg(2);
    insertbeg(1);
    delkey(1);
    display();
}
