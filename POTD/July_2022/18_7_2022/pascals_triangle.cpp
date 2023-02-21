#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

void printVII(vvi arr){
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[0].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

vvi pascalTriangle(int n){
    vvi arr(n);

    for (int line=0; line < n; line++){
        arr[line].resize(line+1);
        for (int i=0; i <= line; i++){
            if (i == 0 || line == n){
                arr[line][i] = 1;
            }else{
                arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
            }
        }
    }
    return arr;
}

int main(){
    pascalTriangle(5);
    // printVVI(answer);
}