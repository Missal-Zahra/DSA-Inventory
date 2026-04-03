#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(vector<int>& arr, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) res.push_back(arr[dq.front()]);
    }
    return res;
}

int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = slidingWindowMax(arr, k);
    for (int x : res) cout << x << " ";
    return 0;
}