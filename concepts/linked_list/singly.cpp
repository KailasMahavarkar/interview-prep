#include <bits/stdc++.h>
using namespace std;

// refid -> 101
class Node{
    public:
    int data;
    Node *next = NULL;

    // constructor of type Node(int)
    Node(int data){
        this ->data = data;
        this ->next = NULL;
    }

    // destructor
    ~Node(){
        // mem free
        if (this->next != NULL){
            delete this->next; // clean up chain after current node
            this->next = NULL; // set next to NULL or it will point to garbage memory
        }
        cout << "mem free for node with data: " << (this ->data) << endl;
    }

};

void printLL(Node* &head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
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

void insertAtMiddle(Node* &head, Node* &tail, int position, int data){
    Node *temp = head;
    int count = 1;

    // when insert at head
    if (position == 1){
        insertAtHead(head, data);
        return;
    }

    // iterate over n-1
    while(count < position - 1){
        temp = temp->next;
        count++;
    }

    // inserting at last postion
    if (temp->next == NULL){
        insertAtTail(tail, data);
        return;
    }

    // creating new node for data
    Node* nodeToInsert = new Node(data);

    // temp is pointing to head initally
    // as we loop temp will change to next node
    // I loop through (n - 1) and stop

    // node1([10, 0x1])--->node2([30, 0x2])
    // NodeToInsert([60, null]) [NTI is shortform]

    // image explaination -> https://bit.ly/3vs11GB

    // NTI.next -> node2  (wrong since we don't know node2)
    // NTI.next -> temp.next (loop will stop n-1 position)
    // temp.next = NTI
    

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;


}

void deleteAtTail(Node* &head){
    // loop through n-1
    Node *temp = head;
    Node *prev = NULL;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL;
    head = prev;   

    // free memory
    delete temp;
}

// reference
void deleteNode(Node* &head, int position){

    if (position == 1){
        Node* temp = head;
        // shift head to next node
        head = head->next;

        // set prev next to null
        // since head is already overwritten 
        // we need to store head reference before overwriting
        temp->next = NULL;

        // mem free start node
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;

        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;

        // the current node which we want to delete set it to NULL
        curr->next = NULL;
        delete curr;

    }
}

// self
void deleteAtNode(Node* &head, int position){
    if (position == 1){
        Node *prev = head;
        head = head->next;

        // before calling delete prev 
        // make sure to set its next pointer to null
        prev->next = NULL;
        delete prev;
    }else{

        int count = 1;
        Node* curr = head;
        Node* prev = NULL;

        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);

    printLL(head);
    deleteAtNode(head, 2);
    printLL(head);

    // cout << head->data << endl;
    // cout << tail->data << endl;

    return 0;
}