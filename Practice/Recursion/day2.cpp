#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

// fibonacci number
// 0 1 1 2 3 5 8 13 21 34 55
// 0 1 2 3 4 5 6 7  8  9  10

int fibo(int n)
{

    // base case for 0
    if (n == 0)
    {
        return 0;
    }
    // base case for 1
    if (n == 1)
    {
        return 1;
    }

    // recurance relation
    // f(n) = f(n - 1) + f(n - 2)
    int answer = fibo(n - 1) + fibo(n - 2);
    return answer;
}

// climb stairs
int climbStairs(int n)
{

    // base case
    if (n < 0)
    {
        return 0;
    }

    // n --> 0
    if (n == 0)
    {
        return 1;
    }

    // recursive relation
    // f(n) = fn(n - 1) + fn(n - 2)
    int ans = climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}

// say digits
void sayDigits(int n, string arr[])
{
    // base case
    if (n == 0)
        return;

    // processing
    int digit = n % 10;
    n = n / 10;

    // recursive call
    sayDigits(n, arr);

    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven",
        "eight", "nine"};

    sayDigits(123, arr);
    return 1;
}