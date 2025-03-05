#include <iostream>
using namespace std;

class Solution {
   public:
    void solve(int n) {
        // story of vector were just given for distractions in this questions
        // you can simply say if its k'th person turn then you can print his name
        // since there are only 2 players we take n % 2
        if (n % 2 == 0) {
            cout << "Sakurako" << endl;
        } else {
            cout << "Kosuke" << endl;
        }
    }
};

int main() {
    int t;
    cin >> t;
    Solution sol;
    while (t--) {
        int n;
        cin >> n;
        sol.solve(n);
    }
    return 0;
}
