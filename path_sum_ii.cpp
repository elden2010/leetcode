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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
	vector<vector<int> > ret;
	// empty
	if(root==NULL)
	    return ret;
	// leaf node as base
	if(root->left==NULL && root->right==NULL && root->val==sum) {
	    vector<int> path(1,root->val);
	    ret.push_back(path);
	}
	// recursive
	if(root->left!=NULL) {
	    vector<vector<int> > ret2 = pathSum(root->left,sum-root->val);
	    for(int i=0;i<ret2.size();++i) {
		vector<int> row(1,root->val);
		for(int j=0;j<ret2[i].size();++j) 
		    row.push_back(ret2[i][j]);
		ret.push_back(row);
	    }
	}
	
	if(root->right!=NULL) {
	    vector<vector<int> > ret2 = pathSum(root->right,sum-root->val);
	    for(int i=0;i<ret2.size();++i) {
		vector<int> row(1,root->val);
		for(int j=0;j<ret2[i].size();++j) 
		    row.push_back(ret2[i][j]);
		ret.push_back(row);
	    }
	}

	return ret;	

    }
};
