#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

class Solution {
   public:
    void printHeap(priority_queue<int, vector<int>, greater<int>> heap) {
        cout << "heap: ";
        while (heap.size() > 0) {
            cout << heap.top() << " ";
            heap.pop();
        }
        cout << endl;
    }

    vector<int> solve(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> heap;

        auto pushToHeap = [&](int num) {
            while (heap.size() >= 3) {
                heap.pop();
            }
            heap.push(num);
            printHeap(heap);
        };

        pushToHeap(10);
        pushToHeap(20);
        pushToHeap(30);
        pushToHeap(40);
        pushToHeap(50);
        pushToHeap(60);
        pushToHeap(70);
        pushToHeap(80);
        pushToHeap(90);
        pushToHeap(100);

        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {5, 2, 6, 1};

    Solution sol;
    vector<int> ans = sol.solve(nums);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
