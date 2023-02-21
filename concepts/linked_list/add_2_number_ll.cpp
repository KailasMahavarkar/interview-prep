#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        // define property
        int data = data;
        Node* next = NULL;

        // set values by constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            if (this->next != NULL){
                delete this->next;
                this->next = NULL;
            }
        }
};


void insertAtTail(Node* &tail, int data){
    Node* newNode = new Node(data);
    
    tail->next = newNode;
    tail = newNode;
}

Node* reverseLL(Node* &head){

    if (head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* temp = NULL;
    
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void printLL(Node* head){
    cout << "----------" << endl;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
    cout << "head is at " << (head->data) << endl; 
    cout << "----------" << endl;

}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);


    Node* reversedHead = reverseLL(head);

    printLL(reversedHead);

    cout << node1->data << endl;

}