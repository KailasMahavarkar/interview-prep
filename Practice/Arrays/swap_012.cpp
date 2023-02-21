#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void sort012(int arr[], int n)
{

    int i = 0, j = n - 1;

    // approach
    // sort 0 & 1
    // since (j--) j will point to last index where we dont have 2
    // reset i pointer
    // check from 0 to j
    // sort 0 & 2
    while (i < j)
    {
        while (arr[i] == 0 || arr[i] == 1)
        {
            i++;
        }
        while (arr[j] == 2)
        {
            j--;
        }
        if (arr[i] == 2 && (arr[j] == 0 || arr[j] == 1) && i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    i = 0;
    while (i < j)
    {

        while (arr[i] == 0)
        {
            i++;
        }

        while (arr[j] == 1)
        {
            j--;
        }

        if (arr[i] == 1 && arr[j] == 0 && i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

int main()
{
    int arr[9] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    sort012(arr, 9);

    printArray(arr, 9);
    return 1;
}