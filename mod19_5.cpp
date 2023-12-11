// ----------------------------------------------Leetcode practice problems-----------------------------------------------------

// -----------univalued binary tree--------------
// class Solution {
// public:
//     bool isSameVal(TreeNode* root, int v){
//         if(root==NULL) return false;
//         bool currentNode= true, left=true, right=true;
//         if(root->left) left=isSameVal(root->left,v);
//         if(root->right) right=isSameVal(root->right,v);
//         if(root->val!=v) currentNode = false;
//         if(currentNode && left && right) return true;
//         return false;
//     }
//     bool isUnivalTree(TreeNode* root) {
//         if(root==NULL) return false;
//         return isSameVal(root, root->val);
//     }
// };

// -----------------leaf similar trees-----------------
// class Solution {
// public:
//     vector<int> v1, v2;
//     void leftTraversal(TreeNode* root, int x){
//         if(root== NULL) return;
//         if(root->left) leftTraversal(root->left, x);
//         if(root->right) leftTraversal(root->right, x);
//         if(root->left==NULL && root->right==NULL){
//             if(x==1) v1.push_back(root->val);
//             if(x==2) v2.push_back(root->val);
//         }
//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         v1.clear(); v2.clear();
//         leftTraversal(root1,1);
//         leftTraversal(root2,2);
//         if(v1==v2) return true;
//         return false;
//     }
// };

// ---------------------------same tree---------------------
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL && q==NULL) return true;
//         if(p==NULL || q==NULL) return false;
//         if(p->val != q->val) return false;
//         return (isSameTree(p->right, q->right) && isSameTree(p->left,q->left));
//     }
// };

// ---------------------------binary tree tilt-----------------
// class Solution {
// public:
//     int tilt=0;
//     int countTilt(TreeNode* root) {
//         if(root==NULL) return 0;
//         int left = countTilt(root->left);
//         int right = countTilt(root->right);
//         tilt += (abs(left-right));
//         return left + right + root->val;
//     }
//     int findTilt(TreeNode* root) {
//         if(root) countTilt(root);
//         return tilt;

//     }
// };