#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    string color;
    Node *left, *right, *parent;

    Node(int value)
    {
        data = value;
        color = "RED";
        left = right = parent = NULL;
    }
};

class RBTree
{
public:
    Node* root;

    RBTree()
    {
        root = NULL;
    }

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

    void fixInsert(Node* k)
    {
        while(k != root && k->parent->color == "RED")
        {
            if(k->parent == k->parent->parent->left)
            {
                Node* u = k->parent->parent->right;

                if(u != NULL && u->color == "RED")
                {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else
                {
                    if(k == k->parent->right)
                    {
                        k = k->parent;
                        leftRotate(k);
                    }

                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    rightRotate(k->parent->parent);
                }
            }
            else
            {
                Node* u = k->parent->parent->left;

                if(u != NULL && u->color == "RED")
                {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else
                {
                    if(k == k->parent->left)
                    {
                        k = k->parent;
                        rightRotate(k);
                    }

                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    leftRotate(k->parent->parent);
                }
            }
        }

        root->color = "BLACK";
    }

    void insert(int value)
    {
        Node* node = new Node(value);
        Node* y = NULL;
        Node* x = root;

        while(x != NULL)
        {
            y = x;

            if(node->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        node->parent = y;

        if(y == NULL)
            root = node;

        else if(node->data < y->data)
            y->left = node;

        else
            y->right = node;

        if(node->parent == NULL)
        {
            node->color = "BLACK";
            return;
        }

        if(node->parent->parent == NULL)
            return;

        fixInsert(node);
    }

    void inorder(Node* root)
    {
        if(root == NULL)
            return;

        inorder(root->left);

        cout << root->data << "(";

        if(root->color == "RED")
            cout << "R";
        else
            cout << "B";

        cout << ") ";

        inorder(root->right);
    }
};

int main()
{
    RBTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    cout << "Red Black Tree Inorder Traversal:\n";
    tree.inorder(tree.root);

    return 0;
}