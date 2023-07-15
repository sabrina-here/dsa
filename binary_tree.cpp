#include<bits/stdc++.h>
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
    Node* root;
    int h; cin>>h;
    if(h!= -1) root->v = h;
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

void levelOrder(Node* root){
    queue<Node*> q ;
    if(root) q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->v<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        q.pop();
    }
}

void preOrder(Node* root){
    if(root==NULL) return;
    cout<<root->v<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->v<<" ";
}

void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->v<<" ";
    inOrder(root->right);
    
}
int totalNodes(Node* root){
    if(root==NULL) return 0;
    int l,r;
    l = totalNodes(root->left);
    r = totalNodes(root->right);
    return l+r+1;
}

int leafNodes(Node* root){
    if(root==NULL) return 0;
    int l,r;
    if(root->left==NULL && root->right==NULL) return 1;
    else{
        l = leafNodes(root->left);
        r = leafNodes(root->right);
    }
    return l+r;
}

int treeHeight(Node* root){
    if(root == NULL) return 0;
    int l = treeHeight(root->left);
    int r = treeHeight(root->right);
    return max(l,r)+1;
}


//----------sum of all left nodes in the tree-------------


// long long int inOrder(Node* root){
//     if(root==NULL) return 0;
// 	long long int count=0;
// 	if(root->left) count=root->left->data;
//     long long int a= inOrder(root->left);
//     long long int b= inOrder(root->right);
//     return count+a+b;
// }

// long long leftSum(Node* root)
// {
// 	// Write your code here.
// 	long long int count = inOrder(root);
	
// 	return count;
	
// }

int main(){

    // Node* root = inputTree();

    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);
    Node* f = new Node(70);
    Node* g = new Node(80);
    Node* h = new Node(90);
    Node* i = new Node(100);

    root->left= a;
    root->right = b;
    a->left= c;
    a->right= h;
    b->right = d;
    c->right = e;
    h->right = i;
    d->left = f;
    d->right = g;

    levelOrder(root);
    // cout<<endl;
    // preOrder(root);
    // postOrder(root);
    // inOrder(root);
    cout<<endl;
    cout<<totalNodes(root)<<endl;
    cout<<leafNodes(root)<<endl;
    cout<<"height: "<<treeHeight(root)<<endl;

    return 0;
}