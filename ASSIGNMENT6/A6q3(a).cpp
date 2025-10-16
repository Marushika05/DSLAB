/*Write a program to find size of
i. Doubly Linked List.
ii. Circular Linked List. */

// implementing doubly first
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL;
void insertbeg(int num)
{
    struct node *temp = new node();
    temp->data = num;
    temp->next = temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertend(int num)
{
    struct node *newnode = new node();
    newnode->data = num;
    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    struct node *curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = newnode;
    newnode->prev = curr;
}

void display()
{
    struct node *prev, *next = NULL;
    struct node *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "size is: " << count << endl;
}

int main()
{
    insertbeg(1);
    insertend(2);
    insertend(3);
    insertend(4);
    insertend(5);
    display();
}
