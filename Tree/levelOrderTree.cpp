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

int height(Node *root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    return 1 + max(h1,h2);
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int d1 = height(root->left) + height(root->right);
    int d2  = diameter(root->left);
    int d3  = diameter(root->right);

    return max(d1,max(d2,d3));
}

int main(){
   Node* root = levelOrderBuildTree();
   cout<<endl;
   printLeveorder(root);
   cout<<endl;
   cout<<height(root)<<endl;
   cout<<diameter(root)<<endl;
    return 0;
}