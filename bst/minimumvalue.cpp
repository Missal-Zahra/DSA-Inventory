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
int findmin (Node* root )
{
    while (root -> left !=NULL)
    root = root -> left;
    return root -> data ;
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
        cout << "MIN value is " << findmin (root);
        return 0;

}