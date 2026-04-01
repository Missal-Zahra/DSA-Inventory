#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n = 5;
    queue<string> q;

    q.push("1");

    for (int i = 0; i < n; i++) {
        string s = q.front();
        q.pop();

        cout << s << " ";

        q.push(s + "0");
        q.push(s + "1");
    }
}