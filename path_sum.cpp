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
    vector<int> sums;
    void work(TreeNode *root,int pv) {	
	if(root==NULL)
	    return;
	// leaf
	if(root->left==NULL && root->right==NULL) {
	    sums.push_back(pv+root->val);
	    return;
	}
	//
	if(root->left!=NULL)
	    work(root->left,pv+root->val);
	if(root->right!=NULL)
	    work(root->right,pv+root->val);
	return;
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
	sums.clear();
	work(root,0);
	bool ret = false;
	for(int i=0;i<sums.size();++i)
	    if(sums[i]==sum) {
		ret = true;
		break;
	    }
	return ret;        
    }
};
