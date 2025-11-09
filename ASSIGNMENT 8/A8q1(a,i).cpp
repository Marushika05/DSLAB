/*2. Implement following functions for Binary Search Trees
(a) Search a given item (Recursive & Non-Recursive)*/
#include <iostream>
using namespace std;

// recursive ; pehle tree bnalete using preoder
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
void preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

// creating tree serach
struct node *treesearch(node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return treesearch(root->left, key);
    }
    else
    {
        return treesearch(root->right, key);
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

    if (treesearch(root, 15))
    {
        cout << "found" << endl;
    }
    return 0;
}
