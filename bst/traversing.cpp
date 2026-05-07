#include <iostream>
using namespace std;
struct Node 
{
    int data;;
    Node* left;
    Node* right ;

    Node (int value)
    {
        data = value ;
        left = NULL;
        right = NULL;
    }
};
Node* insert (Node* root ,  int value )
{
    if (root == NULL)
    {
        return new Node (value);
    }
    if (value <root -> data)
    root -> left = insert (root -> left , value );
    else 
    root ->right = insert (root -> right , value);
    return root;
}
void inorder (Node* root)
{
    if (root == NULL)
    return ;
    inorder (root ->left );
    cout << root -> data <<"";
    inorder (root -> right );
}
void preorder  (Node* root)
{
    if (root == NULL)
    return ;
     cout << root -> data <<"";
    preorder (root ->left );
    preorder (root -> right );
}
void postorder  (Node* root)
{
    if (root == NULL)
    return ;
    postorder (root ->left );
    postorder (root -> right );
    cout << root -> data <<" ";
}

int main ()
{
    Node* root = NULL;
    root = insert(root, 50); 
insert(root, 30); 
insert(root, 70); 
insert(root, 20); 
insert(root, 40); 
insert(root, 60); 
insert(root, 80); 
    cout << "Inorder";
    inorder (root);

    cout <<"Preorder"<<endl;
    preorder (root);

    cout <<"Postorder"<<endl;
    postorder(root);

    return 0;

}