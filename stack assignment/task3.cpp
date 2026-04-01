#include <iostream>
#include <stack>
using namespace std;

int prec(char c) {
    if(c == '+' || c == '-') return 1;
    if(c == '*' || c == '/') return 2;
    return 0;
}

int main() {
    string exp = "A+B*C";
    stack<char> s;

    for(char c : exp) {
        if(isalnum(c))
            cout << c;
        else {
            while(!s.empty() && prec(s.top()) >= prec(c)) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}