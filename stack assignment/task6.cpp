#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str = "madam";
    stack<char> s;

    for(char c : str)
        s.push(c);

    string rev = "";

    while(!s.empty()) {
        rev += s.top();
        s.pop();
    }

    if(str == rev)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}