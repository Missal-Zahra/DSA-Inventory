#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string s) {
    int freq[256] = {0};
    queue<char> q;

    for (char c : s) {
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1) q.pop();
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
}

int main() {
    string s = "aabc";
    firstNonRepeating(s); // Output: a -1 b b
    return 0;
}