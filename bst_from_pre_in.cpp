/*passed small test but not large (memory limit)*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef vector<int>::iterator vii;

class Solution {
 
    TreeNode *buildTree(vii pre1,vii pre2,vii in1,vii in2) {
	// 0. 
	if(in1==in2 || pre1==pre2)
	    return NULL;

        // 1. find root from pre
	int rootv = *pre1;
	TreeNode* root = new TreeNode(rootv);
	
	// 2. find root index in inorder
	vii rootIt = find(in1,in2,rootv);
	int leftLen = rootIt - in1;

	// 3. left tree
	TreeNode *left = buildTree(pre1+1,pre1+1+leftLen,in1,rootIt);
	root->left = left;

	// 4. right tree
	TreeNode *right = buildTree(pre1+1+leftLen,pre2,rootIt+1,in2);
	root->right = right;

	return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	return buildTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
};

int main() {
    Solution s;
    vector<int> in(1,-1),pre(1,-1);
    TreeNode *root = s.buildTree(pre, in);
    cout << endl;
}
