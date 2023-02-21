#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{

    // basecase
    if (n == 0)
        return 1;

    // recursive call
    int smallProblem = factorial(n - 1);
    int bigProblem = n * smallProblem;

    return bigProblem;
}

int powerofTwo(int n)
{

    // RR -> 2^n = 2^(n-1) * 2^n

    // base case
    if (n == 0)
    {
        return 1;
    }

    int smallProblem = powerofTwo(2 ^ (n - 1));
    int bigProblem = 2 ^ n * smallProblem;

    return bigProblem;
}

void print(int n)
{

    // basecase
    if (n == 0)
    {
        return;
    }

    // recurance relation
    print(n - 1);

    // cout
    cout << n << endl;
}

int main()
{
    int n = 0;
    cout << "Enter Number -->";
    cin >> n;

    print(n);

    return 0;
}