#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class CircularLinkedQueue {
    Node* front;
    Node* rear;
public:
    CircularLinkedQueue() { front = rear = NULL; }

    void enqueue(int x) {
        Node* temp = new Node();
        temp->data = x; temp->next = NULL;
        if (!front) { front = rear = temp; rear->next = front; return; }
        rear->next = temp; rear = temp; rear->next = front;
    }

    void dequeue() {
        if (!front) { cout << "Queue Empty\n"; return; }
        Node* temp = front;
        cout << temp->data << " removed\n";
        if (front == rear) { front = rear = NULL; delete temp; return; }
        front = front->next; rear->next = front;
        delete temp;
    }

    void display() {
        if (!front) { cout << "Queue Empty\n"; return; }
        Node* temp = front;
        do { cout << temp->data << " "; temp = temp->next; } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularLinkedQueue q;
    q.enqueue(10); q.enqueue(20); q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.display();
    return 0;
}