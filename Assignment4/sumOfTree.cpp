#include <bits/stdc++.h>

using namespace std;

class Node{

    public: 
        int v;
        Node* left;
        Node* right;
        Node(int val){
            v = val;
            this->left = NULL;
            this->right = NULL;
        }

};


int main()
{
    // Write your code here
    int count=0;
    Node* root= NULL;
    int h; cin>>h;
    if(h!= -1){
        root = new Node(h);
        count+=h;
    }
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        Node* newNode = q.front();
        int l, r; cin>>l>>r;
        if(l!= -1){
             Node* leftNode = new Node(l);
             newNode->left = leftNode;
             q.push(leftNode);
            count+=l;
        }
        if(r!= -1){
             Node* rightNode = new Node(r);
             newNode->right = rightNode;
             q.push(rightNode);
            count+=r;
        }
        q.pop();
        
    }
    cout<<count<<endl;

    return 0;
}
