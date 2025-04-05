#include <bits/stdc++.h>
using namespace std;

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

    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    vector<int> primes = sieve(100);
    for (auto &x : primes) {
        cout << x << endl;
    }
    return 0;
}