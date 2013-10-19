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
    vector<int> pathV;
    int process(TreeNode *root) {
	if(!root)
	    return 0;

	int ret;
	if(root->left)
	    if(root->right) {
		int lv = process(root->left);
		int rv =  process(root->right);
		ret = max(root->val,max(root->val+lv,root->val+rv));
		pathV.push_back(ret);
		pathV.push_back(lv);
		pathV.push_back(rv);
		pathV.push_back(root->val+lv+rv);
	    } else {
		int lv = process(root->left);
		ret = max(root->val,root->val+lv);
		pathV.push_back(ret);
		pathV.push_back(lv);
	    }
	else
	    if(root->right) {
		int rv = process(root->right);
		ret = max(root->val,root->val+rv);
		pathV.push_back(ret);
		pathV.push_back(rv);
	    } else {
		ret = root->val;
		pathV.push_back(ret);
	    }

	return ret;
    }

public:
    int maxPathSum(TreeNode *root) {
	if(!root)
	    return 0;

	pathV.clear();

	process(root);
	
	int ret=pathV[0];
	for(int i=1;i<pathV.size();++i)
	    if(ret<pathV[i])
		ret=pathV[i];

	return ret;
    }
};
