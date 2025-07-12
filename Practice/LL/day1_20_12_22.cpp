#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Node{
    public:
        Node* next = NULL;
        int data;

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


void printLL(Node* &head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << endl;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node* &head, Node* &tail, int position, int data){
    if (position == 1){
        insertAtHead(head, data);
        return;
    }
    
    int counter = 1;
    Node* nodeToInsert = new Node(data);
    Node* temp = head;


    // why position - 1 ?? n-1 will be target since we are chasing n
    while (counter < position - 1){
        temp = temp->next;
        counter++;
    }

    if (temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

}

int main(){

    Node* node1 = new Node(10);
    Node* node2 = new Node(30);

    node1->next = node2;
    Node* head = node1;
    Node* tail = node2;

    insertAtMiddle(node1, node2, 0, 500);

    cout << "Head is at " << head->data << endl;
    cout << "Tail is at " << tail->data << endl; 


    printLL(node1);
}