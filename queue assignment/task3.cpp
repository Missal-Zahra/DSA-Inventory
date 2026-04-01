#include <iostream>
#include <queue>
using namespace std;

int main() {
    string str = "aabc";
    queue<char> q;
    int freq[26] = {0};

    for (char ch : str) {
        q.push(ch);
        freq[ch - 'a']++;

        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
}