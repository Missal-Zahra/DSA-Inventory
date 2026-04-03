#include <iostream>
using namespace std;

class CircularQueue {
    int arr[5], front, rear;
public:
    CircularQueue() { front = rear = -1; }

    void enqueue(int x) {
        if ((rear+1)%5 == front) {
            cout<<"Full\n"; return;
        }
        if (front == -1) front = 0;
        rear = (rear+1)%5;
        arr[rear] = x;
    }

    void display() {
        if (front == -1) { cout << "Empty\n"; return; }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % 5;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  

    q.display();

    return 0;
}