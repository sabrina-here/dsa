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

int treeHeight(Node* root){
    if(root == NULL) return 0;
    int l = treeHeight(root->left);
    int r = treeHeight(root->right);
    return max(l,r)+1;
}

int main()
{
    // Write your code here
    int totalNodes=0;
    Node* root= NULL;
    int h; cin>>h;
    if(h!= -1) {
        root = new Node(h);
        totalNodes++;
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
            totalNodes++;
        }
        if(r!= -1){
             Node* rightNode = new Node(r);
             newNode->right = rightNode;
             q.push(rightNode);
            totalNodes++;
        }
        q.pop();
        
    }
    int mh = treeHeight(root);
    int formula = pow(2,mh)-1;
    if(formula==totalNodes) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
