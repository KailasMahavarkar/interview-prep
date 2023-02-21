#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next = NULL;

        // constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }

        // destructor
        ~Node()
        {
            // when node is deleted
            // check if node is already null
            if (this->next != NULL)
            {
                delete this->next;
                this->next = NULL;
            }
        }
};

void printLL(Node* head){
    if (head == NULL){
        cout << "head is empty" << endl;
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}

void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    tail->next = newNode;    
    tail = newNode;
}

void isPallindrome(Node* &head){

    Node* fast = head->next;
    Node* slow = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        prev = slow;
    }

    // set prev as slow
    prev = slow;

    slow = slow->next;

    // important: break its chain
    prev->next = NULL;


    cout << slow->data << endl;
    cout << "fast:" << fast << endl;
}

int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 20);
    insertAtTail(tail, 10);

    // printLL(head);
    // cout << "tail is at " << tail->data << endl;
    isPallindrome(head);
}