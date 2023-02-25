#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

void printPQ(priority_queue<int>& pq) {
    // print pq elements and then restore it
    priority_queue<int> temp = pq;
    while (temp.empty() == false) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // restore pq
    while (pq.empty() == false) {
        temp.push(pq.top());
        pq.pop();
    }

    while (temp.empty() == false) {
        pq.push(temp.top());
        temp.pop();
    }
}

class Solution {
   public:
    int findMaximizedCapital(int k, int money, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int, int>> projects;

        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end(), [&](pi a, pi b) {
            return (a.first < b.first);
        });

        // priority queue  (max heap)
        priority_queue<int> pq;

        int i = 0;
        while (k) {
            for (int i = 0; i < n; i++) {
                if (projects[i].first <= money) {
                    pq.push(projects[i].second);
                }
            }

            if (!pq.empty()) {
                money += pq.top();
                pq.pop();
            }

            k--;
        }

        return money;
    }
};

int main() {
    int k = 2;
    int w = 0;
    vector<int> profits = {1, 2, 3};
    vector<int> capitals = {0, 1, 2};

    Solution sol;
    int ans = sol.findMaximizedCapital(k, w, profits, capitals);
    cout << "ans -->" << ans << endl;
}