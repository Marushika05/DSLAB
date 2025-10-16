// Write a program to check if a doubly linked list of characters is palindrome or not.word=LEVEL
#include <iostream>
using namespace std;
struct node
{
    string data;
    struct node *prev, *next;
};
struct node *head = NULL;

void insertbeg(string num)
{
    struct node *temp = new node();
    temp->prev = temp->next = NULL;
    temp->data = num;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
    }
}

void insertend(string num)
{
    struct node *temp = new node();
    struct node *curr = head;
    temp->prev = temp->next = NULL;
    temp->data = num;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}
bool isPalindrome()
{
    struct node *first = head;
    struct node *last = head;
    last->prev = last->next = NULL;
    int count = 0;
    while (last->next != NULL)
    {
        count++;
        last = last->next;
    }
    // while both the ptrs doesnt point towards the exact same address and first doessnt cross last
    while (first != last && last->next != first)
    {
        if (first->data != last->data)
        {
            return false;
        }

        first = first->next;
        last = last->prev;
    }
    return true;
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        cout << "LIST IS EMPTY!" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
}

int main()
{
    insertbeg("L");
    insertend("E");
    insertend("V");
    insertend("E");
    insertend("L");
    display();
    cout << endl;
    if (isPalindrome)
    {
        cout << "IS A PALINDROME" << endl;
    }

    else
    {
        cout << "NOT A PALINDROME";
    }
}
