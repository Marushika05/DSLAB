//3. Write a program to find the middle of a linked list.
// Input: 1->2->3->4->5
// Output: 3

//we need to define a fast and a slow ptr
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

void mid(){
    struct Node *slow= head;
    struct Node *fast= head;
    // struct Node*curr= head;
   // Move fast by 2 and slow by 1 until fast reaches end
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element: " << slow->data << endl;

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

int main(){
    insertbeg(5);
    insertbeg(4);
    insertbeg(3);
    insertbeg(2);
    insertbeg(1);
    mid();
    display();

}
