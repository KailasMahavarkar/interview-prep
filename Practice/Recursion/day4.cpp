#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void reverse(string &str, int i, int j)
{

    // base case
    if (i > j)
    {
        return;
    }

    swap(str[i], str[j]);
    i++;
    j--;

    // recursive call
    reverse(str, i, j);
}

bool pallindrome(string &str, int i, int j)
{

    // basecase
    if (i > j)
    {
        return true;
    }

    // stop condition
    if (str[i] != str[j])
    {
        return false;
    }
    else
    {
        // play with pointers
        return pallindrome(str, i + 1, j - 1);
    }
}

int powerN(int n, int p)
{
    // when a is even -> a^b = a^(1/2) * a^(1/2)
    if (p == 0)
    {
        return 1;
    }

    if (p == 1)
    {
        return n;
    }

    int ans = powerN(n, p / 2);

    if (p % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return ans * ans * n;
    }
}

// worst case n^2 
void bubbleSortArray(int arr[], int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return;
    }

    // this will put largest element at end
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    // recursive call to sort all element
    bubbleSortArray(arr, n - 1);
}

// Homework
void selectionSort(int *arr, int n){
    
}

int main()
{

    // string name = "ioi";
    // bool result = pallindrome(name, 0, name.length() - 1);

    int arr[5] = {5, 4, 3, 2, 1};
    bubbleSortArray(arr, 5);

    cout << "Sorted :" << arr << endl;
    for (auto x : arr) cout << x << endl;
    
    return 1;
}