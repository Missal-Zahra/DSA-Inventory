#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq; // max-heap
    pq.push(10); pq.push(30); pq.push(20);
    cout << pq.top() << endl; // 30
    pq.pop();
    cout << pq.top() << endl; // 20
    return 0;
}