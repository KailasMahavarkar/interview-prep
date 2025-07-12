#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void solve(int n) {
    if ((n / 2) % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    vector<int> evens, odds;

    // saare evens fill karo
    for (int i = 2; evens.size() < n / 2; i += 2) {
        evens.push_back(i);
    }

    // saare odds fill karo
    for (int i = 1; odds.size() < n / 2 - 1; i += 2) {
        odds.push_back(i);
    }

    // Remember:
    // we have two formulas for sum of arithmetic sequence
    // S = (n / 2) * [2a + (n - 1) * d]
    // S = (n / 2) * (first_term + last_term)
    // S_even = (n * (n + 1))
    // S_odd = (n * n)

    // S_even_modified =  (n / 2) * ((n / 2) + 1) -> refer S_even
    int even_sum = (n / 2) * (n / 2 + 1);
    int odd_sum = 0;

    for (int num : odds) odd_sum += num;
    int last_odd = even_sum - odd_sum;
    odds.push_back(last_odd);

    // Print final sequence
    for (int num : evens) cout << num << " ";
    for (int num : odds) cout << num << " ";
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
    return 0;
}
