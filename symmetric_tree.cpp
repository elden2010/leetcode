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
    bool sym(TreeNode *r1,TreeNode *r2) {
	if(r1==NULL && r2==NULL)
	    return true;

	if((r1==NULL && r2!=NULL) 
	   || (r1!=NULL && r2==NULL))
	    return false;

	// both not empty
	bool ret0 = r1->val == r2->val;
	bool ret1 = sym(r1->left,r2->right);
	bool ret2 = sym(r1->right,r2->left);
	return ret0 && ret1 && ret2;
    }

public:
    bool isSymmetric(TreeNode *root) {
	if(root==NULL)
	    return true;
	return sym(root->left,root->right);
    }
};
