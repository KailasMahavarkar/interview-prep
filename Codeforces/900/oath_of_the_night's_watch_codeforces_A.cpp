#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SolutionBruteforce {
   public:
    int solve(const vector<int>& a) {
        set<int> unique_strengths(a.begin(), a.end());

        if (unique_strengths.size() <= 2) {
            return 0;
        }

        int min_strength = *unique_strengths.begin();
        int max_strength = *unique_strengths.rbegin();

        int count = 0;
        for (int strength : a) {
            if (strength > min_strength && strength < max_strength) {
                count++;
            }
        }

        return count;
    }
};

class Solution {
   public:
    int solve(const vector<int>& a) {
        int min_strength = *min_element(a.begin(), a.end());
        int max_strength = *max_element(a.begin(), a.end());

        int min_count = count(a.begin(), a.end(), min_strength);
        int max_count = count(a.begin(), a.end(), max_strength);

        return max(0, (int)a.size() - min_count - max_count);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // vector<int> a = {1, 3, 5};

    Solution sol;
    cout << sol.solve(a) << endl;

    return 0;
}
