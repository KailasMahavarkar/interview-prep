#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;

        Node(int data){
            this ->data = data;
            this ->next = NULL;
        }

        ~Node(){
            if (this->next != NULL){
                delete this->next;
                this ->next = NULL;
            }
        }
};

// https://youtu.be/fi2vh0nQLi0?list=PLDzeHZWIZsTr54_TH_NK4ibFojS4mmQA6&t=297
void insertAtTail(Node* &tail, int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
}

// using iteration
Node* reverseLLByIteration(Node* &head){

    if (head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
    return prev;

}


void reverse(Node* &head, Node* curr, Node* prev){
    if (curr == NULL){
        head = prev;
        return;
    }

    // store the pointer
    Node* forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}

// using recursion
Node* reverseLLbyRecursion(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    reverse(head, curr, prev);
    return head;
}



Node* reverseInKGroups(Node* &head, int k){
    if (head == NULL){
        return NULL;
    }

    // reverse first k nodes;
    Node* prev = NULL;
    Node* forward = NULL;
    Node* curr = head;
    int count = 0;

    while(curr != NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step2: recursion 
    // (5,7)-[(3,4)-(9, 1)]  --> [] recurse box
    if (forward != NULL){
        curr->next = reverseInKGroups(forward, k);
    }

    cout << "head is at: " << head->data << endl;

    // step3: return reversed list
    return prev;
}



int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 7);
    insertAtTail(tail, 3);
    insertAtTail(tail, 8);

    // Node* save = reverseInKGroups(head, 2);

    printLL(save);

}