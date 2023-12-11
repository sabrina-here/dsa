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

int treeHeight(Node* root){
    if(root == NULL) return 0;
    int l = treeHeight(root->left);
    int r = treeHeight(root->right);
    return max(l,r)+1;
}

int main()
{
    // Write your code here
    Node* root = inputTree();
    int h ; cin>>h;
    vector<pair<int,int>> v;
    queue<pair<Node*, int>> q ;
    if(root) q.push({root,0});
    while(!q.empty()){
        pair<Node*,int> p = q.front();
        Node* temp = p.first;
        int level = p.second;
        v.push_back({temp->v,level});
        if(temp->left) q.push({temp->left,level+1});
        if(temp->right) q.push({temp->right,level+1});
        q.pop();
    }
    int th = treeHeight(root)-1;
    for(pair<int,int> p:v){
        if(p.second==h) cout<<p.first<<" ";
    }
    if(h>th){
        cout<<"Invalid"<<endl;
    }

    return 0;
}
