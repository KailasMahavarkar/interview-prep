#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

/*
    Problem Link   : https://www.geeksforgeeks.org/problems/sum-of-query-ii5310/1
    Company Tags   : None
    Youtube Link   : None
    Custom  Link   : None
    Similarities   : None
*/

void buildST(int nums[], int st[], int s, int e, int idx) {
    if (s == e) {
        st[idx] = nums[s];
        return;
    }

    int mid = s + (e - s) / 2;
    buildST(nums, st, s, mid, idx * 2 + 1);
    buildST(nums, st, mid + 1, e, idx * 2 + 2);
    st[idx] = min(st[idx * 2 + 1], st[idx * 2 + 2]);
}

int queryRMQ(int st[], int idx, int qs, int qe, int ns, int ne) {
    //                    qs---------qe
    //  ns----------ne                       ns----------ne
    if (qs > ne || qe < ns) {
        return INT_MAX;
    }

    //     qs-------------------qe
    //         ns----------ne
    if (qs <= ns && qe >= ne) {
        return st[idx];
    }

    int mid = ns + (ne - ns) / 2;
    int minLeft = queryRMQ(st, idx * 2 + 1, qs, qe, ns, mid);
    int minRight = queryRMQ(st, idx * 2 + 2, qs, qe, mid + 1, ne);
    return min(minLeft, minRight);
}

// TC: O(n)
// SC: O(4*n)
int* constructST(int arr[], int n) {
    int* st = new int[4 * n];
    buildST(arr, st, 0, n - 1, 0);
    return st;
}

// TC: O(logn)
// SC: O(1)
int RMQ(int st[], int n, int a, int b) {
    return queryRMQ(st, 0, a, b, 0, n - 1);
}

int main() {
    int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int* st = constructST(arr, n);

    int result = RMQ(st, n, 1, 4);
    cout << "Minimum in range [1, 4]: " << result << endl;

    result = RMQ(st, n, 0, 5);
    cout << "Minimum in range [0, 5]: " << result << endl;

    delete[] st;
    return 0;
}