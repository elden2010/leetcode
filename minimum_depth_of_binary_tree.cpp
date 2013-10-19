/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int minDepth(TreeNode *root) {
    if(!root)
	    return 0;
    if(!root->left && !root->right)
        return 1;
	if(root->left && !root->right)
        return 1+minDepth(root->left);        
    if(!root->left && root->right)
        return 1+minDepth(root->right);        

    // now with both children
    int left = minDepth(root->left);
    int right = minDepth(root->right);
	return left<right?left+1:right+1;        
    }
};
