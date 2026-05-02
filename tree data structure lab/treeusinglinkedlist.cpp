// Create a general tree using linked representation and print all nodes

#include <iostream>
using namespace std;

struct node {
    int data;
    node* child;
    node* sibling;
};

node* create(int val) {
    node* n = new node;
    n->data = val;
    n->child = NULL;
    n->sibling = NULL;
    return n;
}

void print(node* root) {
    if (root == NULL) return;

    cout << root->data << " ";

    print(root->child);
    print(root->sibling);
}

int main() {
    node* root = create(1);
    root->child = create(2);
    root->child->sibling = create(3);
    root->child->child = create(4);

    print(root);
}