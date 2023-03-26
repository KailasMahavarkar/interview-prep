#include <bits/stdc++.h>
using namespace std;

// union with duplicates;
int main() {
    vector<int> arr1 = {1, 2, 4, 6, 8, 10};
    vector<int> arr2 = {3, 4, 5, 6};

    set<int> s;

    for(int i=0; i< arr1.size(); i++){
        s.insert(arr1[i]);
    }

    for(int i=0; i< arr2.size(); i++){
        s.insert(arr2[i]);
    }
    
    vector<int> vec(s.begin(), s.end());
    
    for (auto x: vec){
        cout << x << " ";
    } cout << endl;
}