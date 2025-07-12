#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class SmallestInfiniteSet {
   public:
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> st;

    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            pq.push(i);
            st.insert(i);
        }
    }

    int popSmallest() {
        int n = pq.top();

        // clear data from pq and set
        pq.pop();
        st.erase(n);
        return n;
    }

    void addBack(int num) {
        // check if our search has reached it end, if yes then we didnt find answer
        if (st.find(num) == st.end()) {
            pq.push(num);
            st.insert(num);
        }
    }
};

int main() {
    SmallestInfiniteSet* obj = new SmallestInfiniteSet();
    int param_1 = obj->popSmallest();
    obj->addBack(param_1);
}
