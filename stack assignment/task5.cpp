#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num = 10;
    stack<int> s;

    while(num > 0) {
        s.push(num % 2);
        num /= 2;
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}