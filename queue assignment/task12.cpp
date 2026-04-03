#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int start, vector<int> adj[], int n) {
    bool visited[100] = {false};
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int v : adj[node]) {
            if (!visited[v]) { visited[v] = true; q.push(v); }
        }
    }
}

int main() {
    int n = 5;
    vector<int> adj[5];
    adj[0] = {1,2};
    adj[1] = {0,3,4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    bfs(0, adj, n); // Output: 0 1 2 3 4
    return 0;
}