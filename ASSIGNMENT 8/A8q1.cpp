// 1. Write program using functions for binary tree traversals: Pre-order, In-order and Post
//  order using recursive approach.

// we keep the basic structre same as linked list, we will use recursion and temp would remain the same so we will use
// its address

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *newinsert(int num)
{
    struct node *temp = new node();
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
};
// preorder -nlr= node left right
void preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

// inorder-lnr

void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}
// postorder -lrn
void postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

int main()
{
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

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}