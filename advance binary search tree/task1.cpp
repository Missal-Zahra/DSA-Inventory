#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        return new Node(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }

    else if(value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node* findMin(Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node* deleteNode(Node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }

    // SEARCHING NODE

    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        // CASE 1 : LEAF NODE

        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // CASE 2 : ONE CHILD

        else if(root->left == NULL)
        {
            Node* temp = root->right;

            delete root;

            return temp;
        }

        else if(root->right == NULL)
        {
            Node* temp = root->left;

            delete root;

            return temp;
        }

        // CASE 3 : TWO CHILDREN

        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

int main()
{
    Node* root = NULL;

    root = insert(root, 50);

    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Before Deletion:\n";

    inorder(root);

    root = deleteNode(root, 50);

    cout << "\nAfter Deletion:\n";

    inorder(root);

    return 0;
}
