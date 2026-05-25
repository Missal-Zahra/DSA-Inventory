#include <iostream>
using namespace std;

class Node 
{
    public :
     
    int data ;
    Node* left;
    Node* right;
    int height  ;

    Node (int value){
        data = value ;
        left = NULL;
        right = NULL;
        height = 1;

    }
};

class AVL
{
public:

    int getHeight (Node* node)
    { if ( node == NULL)
        return 0;

        return node->height;
    }

  int getBalance( Node* node)
  {
    if (node ==NULL)
          return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    int max(int a, int b)
    {
        if(a > b)
            return a;

        return b;
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* t2 = x->right;

        x->right = y;
        y->left = t2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* t2 = y->left;

        y->left = x;
        x->right = t2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* root, int value)
    {
        if(root == NULL)
            return new Node(value);

        if(value < root->data)
            root->left = insert(root->left, value);

        else if(value > root->data)
            root->right = insert(root->right, value);

        else
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));

        int balance = getBalance(root);

        // LL
        if(balance > 1 && value < root->left->data)
            return rightRotate(root);

        // RR
        if(balance < -1 && value > root->right->data)
            return leftRotate(root);

        // LR
        if(balance > 1 && value > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // RL
        if(balance < -1 && value < root->right->data)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorder(Node* root)
    {
        if(root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    AVL tree;
    Node* root = NULL;

    root = tree.insert(root, 30);
    root = tree.insert(root, 20);
    root = tree.insert(root, 10);

    cout << "Inorder Traversal: ";
    tree.inorder(root);

    return 0;
}