//(b) Maximum and minimum element of the BST
// sbse pehle make bst and then maximum would be the extreme right

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *root = NULL;

struct node *newinsert(int num)
{
    struct node *temp = new node();
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}
void maxelm(node *temp)
{
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    cout << temp->data;
}

void minelm(node *temp)
{
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    cout << temp->data;
}
int main()
{
    // Constructing a simple BST manually
    root = newinsert(17);
    root->left = newinsert(16);
    root->left->left = newinsert(15);
    root->left->left->left = newinsert(14);
    root->right = newinsert(18);
    root->right->right = newinsert(19);
    root->right->right->right = newinsert(20);

    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;

    maxelm(root);
    cout << endl;

    minelm(root);
}
