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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	// 0. 
	if(inorder.empty() || postorder.empty())
	    return NULL;

        // 1. find root
	int rootv = postorder.back();
	TreeNode* root = new TreeNode(rootv);
	
	// 2. find root index in inorder
	vector<int>::iterator rootIt = find(inorder.begin(),inorder.end(),rootv);
	int leftLen = rootIt - inorder.begin();

	// 3. left tree
	vector<int> inorderLeft,postorderLeft;
	copy(inorder.begin(),rootIt,back_inserter(inorderLeft));
	copy(postorder.begin(),postorder.begin()+leftLen,back_inserter(postorderLeft));
	TreeNode *left = buildTree(inorderLeft,postorderLeft);
	root->left = left;

	// 4. right tree
	vector<int> inorderRight,postorderRight;
	copy(rootIt+1,inorder.end(),back_inserter(inorderRight));
	copy(postorder.begin()+leftLen,postorder.end()-1,back_inserter(postorderRight));
	TreeNode *right = buildTree(inorderRight,postorderRight);
	root->right = right;

	return root;
    }
};

