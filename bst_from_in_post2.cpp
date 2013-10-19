/*passed large test*/

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
 
    TreeNode *buildTree(vii in1,vii in2,vii po1,vii po2) {
	// 0. 
	if(in1==in2 || po1==po2)
	    return NULL;

        // 1. find root
	int rootv = *(po2-1);
	TreeNode* root = new TreeNode(rootv);
	
	// 2. find root index in inorder
	vii rootIt = find(in1,in2,rootv);
	int leftLen = rootIt - in1;

	// 3. left tree
	TreeNode *left = buildTree(in1,rootIt,po1,po1+leftLen);
	root->left = left;

	// 4. right tree
	TreeNode *right = buildTree(rootIt+1,in2,po1+leftLen,po2-1);
	root->right = right;

	return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	return buildTree(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
};

int main() {
    Solution s;
    vector<int> in(1,-1),po(1,-1);
    TreeNode *root = s.buildTree(in, po);
    cout << endl;
}
