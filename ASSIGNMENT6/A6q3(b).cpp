/*Write a program to find size of
i. Doubly Linked List.
ii. Circular Linked List. */

// implementing  circular
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insertbeg(int num)
{
    struct node *temp = new node();
    temp->data = num;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        struct node *curr = head;

        while (curr->next != head)
        {
            curr = curr->next;
        }
        temp->next = head;
        curr->next = temp;
        head = temp;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    struct node *curr = head;
    int count = 0;
    do
    {
        count++;
        cout << curr->data << "->";
        curr = curr->next;
    } while (curr != head);
    cout << "size is: " << count << endl;
}
int main()
{
    insertbeg(1);
    insertbeg(2);
    insertbeg(3);
    insertbeg(4);
    display();
}
