#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
        Node* prev;
    Node(int v){
        val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_list(Node* head, Node* tail){
    cout<<"L -> ";
    while(head!=NULL){
        cout<<head->val<<" ";
        head= head->next;
    }
    cout<<endl;
    cout<<"R -> ";
    while(tail!=NULL){
        cout<<tail->val<<" ";
        tail=tail->prev;
    }
    // cout<<tail->val<<" ";
    cout<<endl;
}

int size_dl(Node* head){
    int sz = 0;
    while(head!=NULL){
        head=head->next;
        sz++;
    }
    return sz;
    
}

void insert_tail(Node* &head, Node* &tail, int pos, int v){
    if(head==NULL && pos>0){
        cout<<"Invalid"<<endl;
        return;
    }
    Node* newNode = new Node(v);
    int sz = size_dl(head);
    if(head== NULL && pos==0){
        head = newNode;
        tail = newNode;
        print_list(head,tail);
        return;
    }
    else if(pos==0){
        newNode->next = head;
        head->prev = newNode;
        head= newNode;
        print_list(head, tail);
        return;
    }
    else if(pos>sz){
        cout<<"Invalid"<<endl;
        return;
    }
        
    else if(pos==sz){
        tail->next = newNode;
        newNode->prev= tail;
        tail = newNode;
        print_list(head,tail);
        return;
    }
    else{
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp= temp->next;
        }
        newNode->next= temp->next;
        temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
        print_list(head,tail);
        return;
    }
    
}



int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int q; cin>>q;
    while(q--){
        int pos,v; cin>>pos>>v;
        insert_tail(head,tail,pos,v);
    }

    return 0;
}
