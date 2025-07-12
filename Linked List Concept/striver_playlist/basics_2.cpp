#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;

    ListNode(int x) {
        data = x;
        next = nullptr;
    }

    ListNode(int x, ListNode* n) {
        data = x;
        next = n;
    }
};

ListNode* vectorToLinkedList(vector<int> arr) {
    if (arr.size() == 0){
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        mover->next = new ListNode(arr[i]);
        mover = mover->next;
    }

    return head;
}

void printLL(ListNode* head) {
    if (head == nullptr) return;

    ListNode* temp = head;

    while (temp != nullptr) {
        cout << (temp->data) << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* deleteHead(ListNode* head) {
    if (head == nullptr) {
        return head;
    }

    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

ListNode* deleteTail(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;

    ListNode* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    ListNode* tail = temp->next;
    temp->next = nullptr;
    delete tail;

    return temp;
}

ListNode* deleteKNode(ListNode* head, int k) {
    if (head == nullptr) return nullptr;
    ListNode* temp = head;

    if (k == 1) {
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    ListNode* prev = nullptr;

    while (temp != nullptr) {
        count++;
        if (count == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

ListNode* removeElement(ListNode* head, int el) {
    if (head == nullptr) return nullptr;
    ListNode* temp = head;

    if (temp->data == el) {
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0;
    ListNode* prev = nullptr;

    while (temp != nullptr) {
        count++;
        if (temp->data == el) {
            prev->next = prev->next->next;
            delete temp;
            break;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

ListNode* insertBeforeHead(ListNode* head, int val) {
    // X->[1, a]->[2, b]->[3, c]
    ListNode* newHead = new ListNode(val, head);
    return newHead;
}

ListNode* insertAfterTail(ListNode* head, int val) {
    if (head == nullptr) {
        return new ListNode(val);
    }

    ListNode* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new ListNode(val);
    return head;
}

ListNode* insertAtK(ListNode* head, int k, int data) {
    if (head == nullptr) {
        if (k == 0) {
            return new ListNode(data);
        } else {
            return nullptr;
        }
    }

    if (k == 1) {
        return new ListNode(50, head);  // -> same as saying (new ListNode(50)).next = head;
    }

    int count = 0;
    ListNode* temp = head;

    while (temp != nullptr) {
        count++;

        if (count == (k - 1)) {
            ListNode* newNode = new ListNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main() {
    vector<int> arr = {3, 2, 1, 0};
    ListNode* head = vectorToLinkedList(arr);
    head = insertAtK(head, 1, 50);
    printLL(head);
}