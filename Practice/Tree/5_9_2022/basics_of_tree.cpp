#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class node{
    public:
        int data;
        node* left = NULL;
        node* right = NULL;
    
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node* buildTree(node* root){

    cout << "enter data" << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1){
        return NULL;
    }

    cout << "Enter node left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter node right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}


void printLevelOrder(node* root){

    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }

        }else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }


    }



}

void printLevelOrderTraversal(node* root){
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if (temp == NULL){
            // means no further elements exists
            if (!q.empty()){
                cout << endl;
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }

    }

}


void inorder(node* root){
    
    if (root == NULL){
        return;
    }

    // recurse left
    inorder(root->left);
    
    // print
    cout << root->data << " ";

    // recurse right
    inorder(root->right);

}

void preorder(node* root){
    
    if (root == NULL){
        return;
    }

    // print
    cout << root->data << " ";

    // recurse left
    preorder(root->left);
    
    // recurse right
    preorder(root->right);
}



int main(){

    node* root = NULL;
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 3 1 -1 -1 5 -1 -1 -1

    printLevelOrderTraversal(root);

    cout << "inorder : ";
    inorder(root);
    cout << endl;

    cout << "preorder : ";
    preorder(root);
    cout << endl;


    cout << "postorder : ";
    postorder(root);
    cout << endl;

    

}