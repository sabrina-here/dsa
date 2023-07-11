#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        string val;
        Node* next;
        Node* prev;
    Node(string v){
        val = v;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head= newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

Node* getNode(Node* head, string word){
    while(head!=NULL && head->val != word){
        head = head->next;
    }
    return head;
}

int main()
{
    Node* head=NULL;
    Node* tail = NULL;
    while(true){
        string add; cin>>add;
        if(add == "end") break;
        insert_at_tail(head,tail,add);
    }
    int q; cin>>q;
    cin.ignore();
    for(int i=0; i<q; i++){
        Node* cur = NULL;
        string name; getline(cin,name);
        stringstream ss(name);
        string word ;
        ss >> word;
        if(word == "visit"){
            ss >> word;
            cur = getNode(head, word);
        }
        else if(word == "next"){
            cur = cur->next;
        }
        else{
            cur = cur->prev;
        }
        if(cur==NULL) cout<<"Not Available"<<endl;
        else cout<<cur->val<<endl;
    }

    return 0;
}
