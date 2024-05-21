#include <bits/stdc++.h>
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

class Solution {
   public:
    ListNode* deleteAllOccurOfX(ListNode* head, int x) {
        ListNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == x) {
                if (temp == head) {
                    head = temp->next;
                }

                ListNode* nextNode = temp->next;
                ListNode* prevNode = temp->back;

                if (nextNode != nullptr) {
                    nextNode->back = prevNode;
                }
                if (prevNode != nullptr) {
                    prevNode->next = nextNode;
                }

                delete temp;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main() {
    vector<int> arr = {3, 2, 1, 0, 2};
    ListNode* ll = vectorToDLL(arr);
    Solution sol;
    ListNode* newLL = sol.deleteAllOccurOfX(ll, 2);
    printDLL(newLL);
}