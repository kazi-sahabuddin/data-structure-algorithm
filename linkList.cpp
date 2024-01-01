
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int n){
        this->val = n;
        this->next = NULL;
    }
};

class List{
    public:
    Node* head;
    List () {
        head = NULL;
    }

    void pushBack(int a){
        Node* node = new Node(a);
        if(head == NULL){
            head = node;
            return;
        }
        Node* temp = head;
        while(temp -> next != NULL){
        temp = temp->next;
        }
        temp->next = node;
        return;
    }
    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;

        }
    }

    void reverseList(){
        Node * current = head;
        Node * prev = NULL;
        Node * temp;
        while(current != NULL){
            temp = current -> next;
            current -> next = prev;
            prev = current;
            current = temp;
        }

        if(prev != NULL)
            head = prev;

    }

};


int main() {
    List l;
    int n;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        l.pushBack(a);
    }

    l.reverseList();

    l.print();

    return 0;
}
