#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")

// Let 's describe the process more precisely.
// Let' s say that the positions in the queue are sequentially numbered by integers from 1 to n,
// at that the person in the position number 1 is served first.
// Then, if at time x a boy stands on the i - th position and a girl stands on the(i + 1) - th position,
// then at time x + 1 the i - th position will have a girl and the(i + 1) - th position will have a boy.
// The time is given in seconds.

/*
    Problem Link   : None
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

// Approach-1 (Normal)
// TC : O(t * n)
// SC : O(1)
class Solution {
   public:
    string processQueue(int n, int t, string s) {
        for (int time = 0; time < t; time++) {
            string str_copy = s;
            for (int i = 0; i < n - 1; i++) {
                if (str_copy[i] == 'B' && str_copy[i + 1] == 'G') {
                    swap(s[i], s[i + 1]);
                    i++;
                }
            }
        }
        return s;
    }
};

int main() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    Solution sol;
    string result = sol.processQueue(n, t, s);
    cout << result << endl;
    return 0;
}