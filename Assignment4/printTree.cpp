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
Node* inputTree(){
    Node* root= NULL;
    int h; cin>>h;
    if(h!= -1) root = new Node(h);
    queue<Node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        Node* newNode = q.front();
        int l, r; cin>>l>>r;
        if(l!= -1){
             Node* leftNode = new Node(l);
             newNode->left = leftNode;
             q.push(leftNode);
        }
        if(r!= -1){
             Node* rightNode = new Node(r);
             newNode->right = rightNode;
             q.push(rightNode);
        }
        q.pop();
        
    }
    return root;
}

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second>b.second;
}

int main()
{
    // Write your code here
    Node* root = inputTree();
    vector<int> v;
    queue<Node*> q ;
    if(root) q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        v.push_back(temp->v);
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
        q.pop();
    }
    reverse(v.begin(),v.end());
    for(int i:v) cout<<i<<" ";

    return 0;
}
