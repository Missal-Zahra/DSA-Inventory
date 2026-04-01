#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = NULL;

        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Empty\n";
            return;
        }

        Node* temp = front;
        cout << temp->data << " removed\n";

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }
};