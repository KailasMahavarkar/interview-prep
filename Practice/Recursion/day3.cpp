#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

bool isSorted(int arr[], int size)
{
    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}

bool isPowerof2(int n)
{

    if (n == 0 || n == 1 || n % 2 == 1)
    {
        return false;
    }

    if (n == 2)
    {
        return true;
    }

    return isPowerof2(n >> 1);
}

bool linearSearch(int arr[], int size, int k)
{

    if (size == 0)
    {
        return false;
    }

    if (arr[0] == k)
    {
        return true;
    }
    else
    {
        return linearSearch(arr + 1, size - 1, k);
    }
}

bool binarySearch(int arr[], int s, int e, int k)
{

    // element not found
    if (s > e)
    {
        return false;
    }

    int mid = s + (e - s) / 2;

    // element found
    if (arr[mid] == k)
    {
        return true;
    }

    // if k=10000 and mid = 50 [ k is more than 50 so no ways its on left]
    // discard left and search only right
    if (k > arr[mid])
    {
        // when searching right we need to update start to mid + 1
        return binarySearch(arr, mid + 1, e, k);
    }
    else
    {
        // when searching left we need to update end to mid - 1
        return binarySearch(arr, s, mid - 1, k);
    }
}

int main()
{
    // powerofTwo
    // for (int x = 0; x < 128; x++)
    // {
    //     cout << x << " " << isPowerof2(x) << endl;
    // }

    int arr[6] = {2, 4, 6, 10, 14, 16};
    // cout << linearSearch(arr, 5, 5) << endl;

    cout << binarySearch(arr, 0, 5, 14) << endl;

    return 0;
}