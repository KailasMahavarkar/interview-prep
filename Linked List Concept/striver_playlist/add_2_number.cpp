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

ListNode* vectorToLinkedList(vector<int> arr) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        mover->next = new ListNode(arr[i]);
        mover = mover->next;
    }

    return head;
}

void printLL(ListNode* head) {
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

ListNode* addNumbers(ListNode* node1, ListNode* node2) {
    ListNode* head = new ListNode(-1);  // Dummy head
    ListNode* sum = head;
    int carry = 0;

    while (node1 != nullptr || node2 != nullptr || carry) {
        int val1 = (node1 != nullptr) ? node1->data : 0;
        int val2 = (node2 != nullptr) ? node2->data : 0;

        int localSum = val1 + val2 + carry;
        carry = localSum / 10;

        sum->next = new ListNode(localSum % 10);
        sum = sum->next;

        if (node1 != nullptr) node1 = node1->next;
        if (node2 != nullptr) node2 = node2->next;
    }

    ListNode* result = head->next;
    delete head;  // Clean up the dummy head
    return result;
}

int main() {
    vector<int> arr1 = {4, 5, 9, 9};
    vector<int> arr2 = {3, 5};

    ListNode* node1 = vectorToLinkedList(arr1);
    ListNode* node2 = vectorToLinkedList(arr2);

    ListNode* node3 = addNumbers(node1, node2);
    printLL(node3);
}