#include <bits/stdc++.h>
using namespace std;

int findUnique(int *arr, int n){
    int answer = 0;
    for(int x=0; x<n;x++){
        answer = answer ^ arr[x]; // XOR
    }
    return answer;
}

int main(){
    int arr[5] = {10, 20, 10, 20, 30};
    int ans = findUnique(arr, 5);
    cout << ans << endl;   
    return 1;
}