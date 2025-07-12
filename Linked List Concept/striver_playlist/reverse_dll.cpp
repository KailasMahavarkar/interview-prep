#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <stack>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;
    ListNode* back;

    ListNode(int x) {
        this->data = x;
        this->next = nullptr;
        this->back = nullptr;
    }

    ListNode(int x, ListNode* backward, ListNode* forward) {
        this->data = x;
        this->back = backward;
        this->next = forward;
    }
};

ListNode* vectorToDLL(vector<int>& arr) {
    if (arr.size() == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        // create a new node that is floating in space -> call it temp
        ListNode* temp = new ListNode(arr[i]);

        // connect that mid's back to prev
        // [prev which is head]-----[temp]-----[next which is nullptr]
        temp->back = prev;

        // now this new prev will be current temp
        // so we move pointer of prev->next to temp (our new previous)
        prev->next = temp;

        prev = prev->next;
    }

    return head;
}

class Solution {
   public:
    // TC: O(2*n)
    // SC: O(n)
    ListNode* reverseNaive(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;

        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while (temp != nullptr) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }

    // TC: O(n)
    // SC: O(1)
    ListNode* reverseDLLOptimal(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            prev = temp->back;
            temp->back = temp->next;
            temp->next = prev;
            // temp.next is actually temp.back now so to move forward we do it opposite
            temp = temp->back;
        }
        prev = prev->back;
        return prev;
    }
};

void printDLL(ListNode* head) {
    if (head == nullptr) {
        cout << "ll is empty" << endl;
        return;
    }
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> arr = {3, 2, 0, 1};
    ListNode* ll = vectorToDLL(arr);
    ListNode* reverseNaive = sol.reverseDLLOptimal(ll);
    printDLL(reverseNaive);
}