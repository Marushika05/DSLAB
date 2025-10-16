#include <iostream>
using namespace std;

// Circular linked list
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertbeg(int num)
{
    struct node *newnode = new node();
    newnode->data = num;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head; // circular link for 1st node
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
        head = newnode; // newnode becomes new head
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
void inspecific(int num)
{
    if (head == NULL)
    {
        cout << "List is empty. Insert at least one node first!" << endl;
        return;
    }

    int value;
    cout << "Enter the value after which you want to insert: ";
    cin >> value;

    struct node *curr = head;
    struct node *temp = new node();
    temp->data = num;

    // traverse circularly to find value
    bool found = false;
    do
    {
        if (curr->data == value)
        {
            found = true;
            break;
        }
        curr = curr->next;
    } while (curr != head);

    if (!found)
    {
        cout << "Value " << value << " not found in the list!" << endl;
        delete temp; // prevent memory leak
        return;
    }

    // insert after current node
    temp->next = curr->next;
    curr->next = temp;

    cout << "Inserted " << num << " after " << value << "." << endl;
}

void delspecific(int num)
{
    bool found = false;
    struct node *curr = head;
    struct node *prev = NULL;
    do
    {
        if (curr->data == num)
        {
            found = true;
            break;
        }

        prev = curr;
        curr = curr->next;

    } while (curr->next != head);
    if (!found)
    {
        cout << "value not found! " << endl;
    }
    else
    {
        prev->next = curr->next;
        delete (curr);
        cout << num << " deleted succesfully!  " << endl;
    }
}
void delbeg()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    // Case 1: Only one node
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }
    struct node *temp = head;
    struct node *curr = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    // becuse our temp is the last node
    delete (curr);
}

void delend()
{
    struct node *curr = head;
    struct node *prev = NULL;

    while (curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = head;
    delete (curr);
}

void search(int num)
{
    bool found = false;
    int count = 0;
    struct node *curr = head;
    struct node *prev = NULL;
    do
    {
        if (curr->data == num)
        {
            found = true;
            break;
        }
        count++;
        curr = curr->next;

    } while (curr->next != head);
    
    if(curr->next==head && curr->data==num){
        cout<<"found at last"<<endl;
    }
    else if (!found)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "found at count: " << count+1 << endl;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
        return;
    }

    struct node *curr = head;
    do
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    } while (curr != head);

    cout << "(back to head)" << endl;
}

int main()
{
    insertbeg(3);
    insertbeg(2);
    insertbeg(1);
    insertend(4);
    insertend(5);
    insertend(6);
    delbeg();
    delend();
    inspecific(11);
    display();
    insertend(10);
    insertend(12);
    insertend(13);
    insertend(14);
    delspecific(5);
    display();
    search(2);
    search(14);
    display();
    return 0;
}
