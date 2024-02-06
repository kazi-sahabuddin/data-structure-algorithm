#include <iostream>
using namespace std;
// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node* n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<", ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printInorder(Node* root){
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<", ";
    printInorder(root->right);
}

void printPostorder(Node* root){
    if(root == NULL){
        return;
    }    
    printPostorder(root->left);
    printPostorder(root->right);
    cout<<root->data<<", ";
}

int main(){
   Node* root = buildTree();
   printPreorder(root);
   cout<<endl;
   printInorder(root);
   cout<<endl;
   printPostorder(root);
   cout<<endl;
    return 0;
}