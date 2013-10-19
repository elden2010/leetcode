/* this version is to use only constant extra space */
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
    vector<TreeNode*> V;
    vector<int> vals;
    void inorder(TreeNode *root) {
	if(root!=NULL) {
	    inorder(root->left);
	    V.push_back(root);
	    vals.push_back(root->val);
	    inorder(root->right);
	}
    }
public:
    void recoverTree(TreeNode *root) {
	V.clear();
	vals.clear();

	inorder(root);

	vector<int> vals2(vals);
	sort(vals2.begin(),vals2.end());
	vector<int> dif;
	for(int i=0;i<vals.size();++i)
	    if(vals[i]!=vals2[i])
		dif.push_back(i);

	swap(V[dif[0]]->val,V[dif[1]]->val);
    }
};
