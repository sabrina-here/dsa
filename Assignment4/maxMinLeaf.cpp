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
int mx=INT_MIN, mn= INT_MAX;
void leafNodes(Node* root){
    if(root==NULL) return ;
    leafNodes(root->left);
    leafNodes(root->right);
    if(root->left==NULL && root->right==NULL){
        mx = max(mx,root->v);
        mn = min(mn, root->v);
    }
    
}

int main()
{
    // Write your code here
    Node* root = inputTree();
    if(root) leafNodes(root);
    cout<<mx<<" "<<mn<<endl;

    return 0;
}
