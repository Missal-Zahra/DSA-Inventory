#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if ((rear + 1) % SIZE == front) {
            cout << "Full\n";
            return;
        }

        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Empty\n";
            return;
        }

        cout << arr[front] << " removed\n";

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        int i = front;

        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
    }
};