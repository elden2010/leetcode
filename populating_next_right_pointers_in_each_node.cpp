/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    int ind;
public:
    void connect(TreeLinkNode *root) {
	if(root==NULL)
	    return;

	// children
	connect(root->left);
	connect(root->right);

	// connect between two children
	TreeLinkNode *l=root->left, *r=root->right;
	while(l!=NULL) {
	    l->next = r;
	    l = l->right;
	    r = r->left;
	}

	return;

    }
};
