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

void printLL(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


Node* reverseLL(Node* &head){

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
    return prev;
}


void reserveRecursion(Node* &head, Node* curr, Node* prev){
    // base case
    if (curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next;
    
    // curr becomes forward (increase one step in next iteration)
    // prev becomes curr (increase one step in next iteration)
    reserveRecursion(head, forward, curr);
    curr->next = prev;

}

Node* reverseLLRecursion(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    reserveRecursion(head, curr, prev);
    return head;
}

void insertAtHead(Node* &head, int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}


Node* getMiddle(Node* &head){
    Node* turtle = head;
    Node* rabbit = head->next;

    if (head == NULL || head->next == NULL){
        return head;
    }

    // only two nodes
    if (head->next->next == NULL){
        return head->next;
    }

    while (rabbit != NULL){
        // rabbit hops 2 times in single iteration
        // turtle hops 1 time in single iteration
        rabbit = rabbit->next;
        if (rabbit != NULL){
            rabbit = rabbit->next;
        }
        turtle = turtle->next;
    }
    return turtle;
}

int main(){
    Node* node1 = new Node(3);
    
    Node* tail = node1;
    Node* head = node1;


    insertAtHead(head, 4);

    Node* mid = getMiddle(head);

    cout << "mid: " << (mid->data) << endl;

    printLL(head);
}