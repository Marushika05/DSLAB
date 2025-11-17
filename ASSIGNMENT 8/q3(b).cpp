// delete node with no children

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

// abb delete krne ke liye iteraative approach use hogi

struct node *deleten(node *root, int key)
{
    if (root == NULL)
        return root;

    // Search
    if (key < root->data)
        root->left = deleten(root->left, key);

    else if (key > root->data)
        root->right = deleten(root->right, key);

    else // key found
    {
        // case 1: no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // case 2: only right child
        else if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // case 3: only left child
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        // case 4: both children → replace with inorder successor
        else
        {
            node *succ = root->right;
            while (succ->left != NULL)
                succ = succ->left; // find the minimum in right subtree

            root->data = succ->data;                        // copy successor data
            root->right = deleten(root->right, succ->data); // delete successor
        }
    }
    return root;
}

int main()
{
    root = newinsert(5);
    root->left = newinsert(2);
    root->left->left = newinsert(-4);
    root->left->right = newinsert(3);
    root->right = newinsert(18);

    inorder(root);
    deleten(root, -4);
    cout << " " << endl;
    inorder(root);

    return 0;
}
