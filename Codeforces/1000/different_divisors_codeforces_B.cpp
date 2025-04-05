#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> primes;
    // We gave you an integer d and asked you to find the smallest positive integer a, such that
    // 1. a has at least 4 divisors -> solved using (1, p, q, p*q) -> smallest will be p*q
    // 2. difference between any two divisors of a is at least d   -> (d + 1) & (x + d)
    void solve(int d) {
        int divisor_1 = 1;                                  // dont need this but keeping here for reference;
        int divisor_2 = lowerBound(d + 1, primes);          // p
        int divisor_3 = lowerBound(d + divisor_2, primes);  // q (p + d)
        int divisor_4 = divisor_2 * divisor_3;
        cout << divisor_4 << endl;
    }

    vector<int> sieve(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = false;
        is_prime[1] = false;

        for (int i = 2; i * i <= n; i++) {  // i*i <= n is same as saying i <= sqrt(n)
            if (is_prime[i]) {
                // mark all prime multiples of that i -> 1i, 2i, 3i... till root(n)
                for (int x = i * i; x <= n; x += i) {
                    is_prime[x] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

   private:
    int lowerBound(int target, vector<int> &nums) {
        int s = 0;
        int e = nums.size();

        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return nums[s];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    sol.sieve(1000000);

    int t;
    cin >> t;

    while (t--) {
        int d;
        cin >> d;
        sol.solve(d);
    }

    return 0;
}