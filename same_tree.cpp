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
    bool isSameTree(TreeNode *p, TreeNode *q) {
	if(p==NULL && q==NULL)
	    return true;
	if(p==NULL && q!=NULL)
	    return false;
	if(p!=NULL && q==NULL)
	    return false;
	if(p->val!=q->val)
	    return false;
	bool ret1 = isSameTree(p->left,q->left);
	bool ret2 = isSameTree(p->right,q->right);
	return ret1 && ret2;
    }
};
