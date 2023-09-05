#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < arr.size(); i++) {
            pq.push({abs(arr[i] - x), i});

            while (pq.size() > k) {
                pq.pop();  // remove element from pq when window size is more than k
            }
        }

        vector<int> answer;
        while (pq.size() > 0) {
            pair<int, int> element = pq.top();
            answer.push_back(arr[element.second]);
            pq.pop();
        }

        sort(answer.begin(), answer.end());
        return answer;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    Solution sol;
    vector<int> ans = sol.findClosestElements(arr, k, x);

    cout << "answer --> ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}