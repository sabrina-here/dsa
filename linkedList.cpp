#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int v){
        val = v;
        this->next = NULL;
    }
};

void insert_tail(Node* &head,Node* &tail, int v){
    Node* newNode = new Node(v);
    if(head== NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void reverse(Node* &head, Node* cur){
    if(cur->next == NULL){
        head=cur;
        return;
    }
    reverse(head, cur->next);
    cur->next->next=cur;
    cur->next=NULL;
    
}

void print_reverse(Node* head){
    if(head==NULL)return;
    print_reverse(head->next);
    cout<<head->val<<" ";
}

void print_list(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

void insert_head(Node* &head,Node* &tail, long long v){
    Node* newNode = new Node(v);
    if(head== NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head= newNode;
    
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    while(true){
        int n ; cin>>n;
        if(n==-1) break;
        insert_tail(head, tail, n);
    }

    print_reverse(head);
    cout<<endl;
    print_list(head);

    // -------------------- Remove duplicates from list------------------------
    Node* temp = head;
     while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val) {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;
        } else {
            temp = temp->next;
        }
    }

    return 0;
}
