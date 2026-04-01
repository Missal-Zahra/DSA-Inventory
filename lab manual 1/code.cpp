#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class SinglyLinkedList
{
private:
    Node* head;

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    void display()
    {
        Node* temp = head;

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    void addAtStart(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = head;

        head = newNode;
    }

    void addAtEnd(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteFirstNode()
    {
        Node* temp = head;

        head = head->next;

        delete temp;
    }
};

int main()
{
    SinglyLinkedList list;

    list.addAtEnd(10);
    list.addAtEnd(20);
    list.addAtEnd(30);

    list.display();

    list.addAtStart(5);

    list.display();

    list.deleteFirstNode();

    list.display();
}