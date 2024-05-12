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

ListNode* deleteHeadDLL(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* temp = head;
    head = head->next;

    temp->back = nullptr;
    temp->next = nullptr;
    delete temp;

    head->back = nullptr;

    return head;
}

ListNode* deleteTailDLL(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    // temp must be pointing at last element in linked list
    ListNode* tail = temp->next;
    temp->next = nullptr;

    // de-refer tail's pointers
    tail->back = nullptr;
    tail->next = nullptr;

    return head;
}

void printDLL(ListNode* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {3, 2, 0, 1};

    ListNode* ll = vectorToDLL(arr);
    printDLL(deleteTailDLL(ll));
}