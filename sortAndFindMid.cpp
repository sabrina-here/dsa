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

int getValue(Node* head, int pos){
    Node* temp = head;
    while(temp!=NULL && pos--){
        temp= temp->next;
    }
    return temp->val;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0; 
    while(true){
        int n ; cin>>n;
        if(n==-1) break;
        insert_tail(head, tail, n);
        size++;
    }
    for(Node* i=head; i->next!=NULL; i=i->next){
        for(Node* j=i->next; j!=NULL; j=j->next){
            if(i->val< j->val) swap(i->val, j->val);
        }
    }
    if(size%2==0){
        int pos1 = (size/2)-1;
        int pos2 = size/2;
        int value1 = getValue(head, pos1);
        int value2 = getValue(head, pos2);
        cout<<value1<<" "<<value2<<endl;
    }
    else{
        int pos = size/2;
        int value = getValue(head, pos);
        cout<<value<<endl;
    }

    return 0;
}
