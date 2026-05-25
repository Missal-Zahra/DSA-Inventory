#include <iostream>
using namespace std;

enum Color {RED, BLACK};

class Node
{
public:
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int value)
    {
        data = value;
        color = RED;
        left = right = parent = NULL;
    }
};

class RBTree
{
public:
    Node* root = NULL;

    void leftRotate(Node* x)
    {
        Node* y = x->right;

        x->right = y->left;

        if(y->left != NULL)
            y->left->parent = x;

        y->parent = x->parent;

        if(x->parent == NULL)
            root = y;

        else if(x == x->parent->left)
            x->parent->left = y;

        else
            x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y)
    {
        Node* x = y->left;

        y->left = x->right;

        if(x->right != NULL)
            x->right->parent = y;

        x->parent = y->parent;

        if(y->parent == NULL)
            root = x;

        else if(y == y->parent->left)
            y->parent->left = x;

        else
            y->parent->right = x;

        x->right = y;
        y->parent = x;
    }

    void fixViolation(Node* z)
    {
        while(z != root && z->parent->color == RED)
        {
            Node* grandparent = z->parent->parent;

            if(z->parent == grandparent->left)
            {
                Node* uncle = grandparent->right;

                if(uncle != NULL && uncle->color == RED)
                {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    z = grandparent;
                }
                else
                {
                    if(z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }

                    z->parent->color = BLACK;
                    grandparent->color = RED;
                    rightRotate(grandparent);
                }
            }
            else
            {
                Node* uncle = grandparent->left;

                if(uncle != NULL && uncle->color == RED)
                {
                    z->parent->color = BLACK;
                    uncle->color = BLACK;
                    grandparent->color = RED;
                    z = grandparent;
                }
                else
                {
                    if(z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }

                    z->parent->color = BLACK;
                    grandparent->color = RED;
                    leftRotate(grandparent);
                }
            }
        }

        root->color = BLACK;
    }

    void insert(int value)
    {
        Node* z = new Node(value);
        Node* y = NULL;
        Node* x = root;

        while(x != NULL)
        {
            y = x;

            if(z->data < x->data)
                x = x->left;

            else
                x = x->right;
        }

        z->parent = y;

        if(y == NULL)
            root = z;

        else if(z->data < y->data)
            y->left = z;

        else
            y->right = z;

        fixViolation(z);
    }

    void inorder(Node* root)
    {
        if(root == NULL)
            return;

        inorder(root->left);

        cout << root->data;

        if(root->color == RED)
            cout << "(R) ";

        else
            cout << "(B) ";

        inorder(root->right);
    }
};

int main()
{
    RBTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    tree.inorder(tree.root);

    return 0;
}