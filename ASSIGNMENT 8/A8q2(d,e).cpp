// (d) In-order successor of a given node in BST
// (e) In-order predecessor of a given node in BST
#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *root = NULL;

node *newinsert(int num)
{
    node *temp = new node();
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder traversal
void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

// Minimum element in a subtree
node *minelm(node *temp)
{
    while (temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// Maximum element in a subtree
node *maxelm(node *temp)
{
    while (temp && temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

// Inorder successor
node *tree_successor(node *x, node *root)
{
    if (x->right != NULL)
    {
        return minelm(x->right);
    }

    node *succ = NULL;
    node *temp = root;

    while (temp != NULL)
    {
        if (x->data < temp->data)
        {
            succ = temp;
            temp = temp->left;
        }
        else if (x->data > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            break;
        }
    }
    return succ;
}

// Inorder predecessor
node *tree_predecessor(node *y, node *root)
{
    if (y->left != NULL)
    {
        return maxelm(y->left);
    }

    node *pred = NULL;
    node *temp = root;

    while (temp != NULL)
    {
        if (y->data < temp->data)
        {
            temp = temp->left;
        }
        else if (y->data > temp->data)
        {
            pred = temp;
            temp = temp->right;
        }
        else
        {
            break;
        }
    }
    return pred;
}

int main()
{
    // BST where RIGHT TREE DOESN'T EXIST (only left side)
    root = newinsert(50);
    root->left = newinsert(40);
    root->left->left = newinsert(30);
    root->left->left->left = newinsert(20);
    root->left->left->left->left = newinsert(10);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    node *x = root->left->left; // Node 30

    node *succ = tree_successor(x, root);
    node *pred = tree_predecessor(x, root);

    cout << "Node: " << x->data << endl;
    if (succ)
        cout << "Inorder Successor: " << succ->data << endl;
    else
        cout << "No Inorder Successor (Right subtree doesn't exist)" << endl;

    if (pred)
        cout << "Inorder Predecessor: " << pred->data << endl;
    else
        cout << "No Inorder Predecessor" << endl;

    return 0;
}
