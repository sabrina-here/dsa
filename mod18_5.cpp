
// -----------------------------------------------coding ninja problems(last three)---------------------------------


// -------------------------count leaf nodes---------------------
// int noOfLeafNodes(BinaryTreeNode<int> *root){
//     // Write your code here.
//     if(root==NULL) return 0;
//     int l,r;
//     if(root->left==NULL && root->right==NULL) return 1;
//     else{
//         l = noOfLeafNodes(root->left);
//         r = noOfLeafNodes(root->right);
//     }
//     return l+r;
// }

// ---------------------------left sum---------------------
// long long int inOrder(BinaryTreeNode<int> *root){
//     if(root==NULL) return 0;
// 	long long int count=0;
// 	if(root->left) count=root->left->data;
//     long long int a= inOrder(root->left);
//     long long int b= inOrder(root->right);
//     return count+a+b;
// }

// long long leftSum(BinaryTreeNode<int> *root)
// {
// 	// Write your code here.
// 	long long int count = inOrder(root);
	
// 	return count;
	
// }

// ---------------------------height of binary tree--------------------
// int treeHeight(TreeNode<int> *root){
//     if(root == NULL) return 0;
//     int l = treeHeight(root->left);
//     int r = treeHeight(root->right);
//     return max(l,r)+1;
// }
// int maxDepth(TreeNode<int> *root) {
//     // Write your code here.
//     int ans = treeHeight(root);
//     return ans-1;
// }