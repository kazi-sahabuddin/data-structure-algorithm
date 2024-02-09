#include <iostream>
#include <queue>
using namespace std;
// Input : 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
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

Node* levelOrderBuildTree(){
    int d;
    cin>>d;
    Node* root = new Node(d);
    queue<Node*> qu;
    qu.push(root);
    while(!qu.empty()){
        Node * current = qu.front();
        qu.pop();
        int c1, c2;
        cin>>c1>>c2;
        if(c1 != -1){
            current->left = new Node(c1);
            qu.push(current->left);
        }

        if(c2 != -1){
            current->right = new Node(c2);
            qu.push(current->right);
        }

    }
    return root;
}



void printLeveorder(Node* root){
    if(root == NULL){
        return;
    }  
    queue<Node*> qu;
    qu.push(root);  
    qu.push(NULL);

    while(!qu.empty()){
        Node *node = qu.front();
        qu.pop();
        if(node != NULL){
            cout<<node->data<<", ";
            if(node->left != NULL){
                qu.push(node->left);
            }
            if(node->right != NULL){
                qu.push(node->right);
            }
        } else {
            cout<<endl;
            if(!qu.empty()){
                qu.push(NULL);
            }
        }
    }
   
}

int main(){
   Node* root = levelOrderBuildTree();
   cout<<endl;
   printLeveorder(root);
    return 0;
}