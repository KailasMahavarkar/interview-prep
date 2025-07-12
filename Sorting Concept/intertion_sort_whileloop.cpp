#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int *arr, int n)
{
    // round 1
    // temp = arr[i] = 4
    // i = arr[1] = 6
    // j = arr[i - 1] ==> arr[1 - 1] = 0
    // loop backward from arr[j - 1] to 0
    // shift elements to right
    // increment i

    // round 2
    // i = arr[2] = 4
    // j = arr[2-1] = 6
    // loop backward from arr[j - 1] to 0
    // if (6 > 4) then incement this until this is no longer true
    // place arr[j + 1] to arr[j] position (shifted to right basically)
    // whereever j stopped we need to add temp to one block ahead so (j + 1)

    int i = 1;
    while (i < n)
    {

        // save arr[i] for later use
        int temp = arr[i];

        // loop backward and shift all elements to right
        // until j + 1 is no longer more than j
        int j = i - 1;
        for (j; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                // if temp is more than arr[j]
                // lets say temp is 6 and arr[j] = 4 then arr is already sorted to left;
                break;
            }
        }

        // fill the gap of j + 1 with temp which we saved previously
        arr[j + 1] = temp;
        i++;
    }
}

// int main
int main()
{
    int arr[4] = {3, 6, 4, 7};
    printArray(arr, 4);

    insertionSort(arr, 4);
    printArray(arr, 4);

    return 0;
}