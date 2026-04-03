#include <iostream>
#include <stack>
using namespace std;

class QueueTwoStacks {
    stack<int> s1, s2;
public:
    void enqueue(int x) { s1.push(x); }

    void dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) { cout << "Queue Empty\n"; return; }
        cout << s2.top() << " removed\n";
        s2.pop();
    }
};

int main() {
    QueueTwoStacks q;
    q.enqueue(10); q.enqueue(20); q.enqueue(30);
    q.dequeue(); q.dequeue();
    q.enqueue(40);
    q.dequeue(); q.dequeue(); q.dequeue(); // empty test
    return 0;
}