/*3. Write a program for binary search tree (BST) having functions for the following
operations:
(a) Insert an element (no duplicates are allowed),
*/
//this is the recurrsive approach withpout the parent approach
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
    temp->right = temp->left = NULL;
    return temp;
};

void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

struct node *insert_withoutparent(node *temp, int key)
{
    if (temp == NULL)
    {
        return newinsert(key);
    }
    if (temp->data > key)
    {
        temp->left = insert_withoutparent(temp->left, key);
    }
    else if (temp->data < key)
    {
        temp->right = insert_withoutparent(temp->right, key);
    }
    else
    {
        cout << "duplicate value exists i.e " << key << endl;
    }
    return temp;
};
int main()
{
    root = newinsert(15);
    root->left = newinsert(6);
    root->left->right = newinsert(7);
    root->left->right->right = newinsert(13);
    root->left->right->right->left = newinsert(9);
    root->left->left = newinsert(3);
    root->left->left->left = newinsert(2);
    root->left->left->right = newinsert(4);
    root->right = newinsert(18);
    root->right->right = newinsert(20);
    root->right->left = newinsert(17);

    insert_withoutparent(root, 56);
    insert_withoutparent(root, 2);
    inorder(root);
    return 0;
}
