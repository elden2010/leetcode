#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    static const int maxn = 100;
    vector<vector<TreeNode *> > dp;

    void add(TreeNode* root,int v) {
	if(root!=NULL) {
	    add(root->left,v);
	    root->val += v;
	    add(root->right,v);
	}
    }

    TreeNode* clone(TreeNode* root) {
	if(root==NULL)
	    return NULL;

	TreeNode* ret = new TreeNode(root->val);
	TreeNode* left = clone(root->left);
	TreeNode* right = clone(root->right);
	ret->left = left;
	ret->right = right;
	return ret;
    }
/*
    void printInOrder(TreeNode* root) {
	if(root!=NULL) {
	    printInOrder(root->left);
	    cout << " " << root->val;
	    printInOrder(root->right);
	}
    }
*/
public:
    Solution() {
	vector<TreeNode*> emptyBSTset;
	dp.resize(maxn,emptyBSTset);
    }

    vector<TreeNode *> generateTrees(int n) {

	if(n<maxn && !dp[n].empty())
	    return dp[n];

	vector<TreeNode*> ret;
	if(n==0)
	    ret.push_back(NULL);
	else
	    for(int i=1;i<=n;++i) {
		vector<TreeNode*> retl = generateTrees(i-1);
		vector<TreeNode*> retr = generateTrees(n-i);
		for(int j=0;j<retl.size();++j)
		    for(int k=0;k<retr.size();++k) {
			TreeNode* root = new TreeNode(i);
			root->left = clone(retl[j]);
			root->right = clone(retr[k]);
			add(root->right,i);

			ret.push_back(root);
		    }
	    }

	if(n<maxn)
	    dp[n] = ret;
	return ret;
    }
};

int main() {
    Solution s;
    vector<TreeNode *> ret = s.generateTrees(2);
    
}
