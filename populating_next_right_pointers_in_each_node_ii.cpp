/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    int getDepth(TreeLinkNode *root) {
	if(root==NULL)
	    return 0;
	int dl = getDepth(root->left);
	int dr = getDepth(root->right);
	return 1+max(dl,dr);
    }

    TreeLinkNode* getLeftMost(TreeLinkNode *root,int depth) {
	if(root==NULL)
	    return NULL;
	if(depth==1)
	    return root;
	TreeLinkNode *l = getLeftMost(root->left,depth-1);
	if(l==NULL)
	    l = getLeftMost(root->right,depth-1);
	return l;
    }

    TreeLinkNode* getRightMost(TreeLinkNode *root,int depth) {
	if(root==NULL)
	    return NULL;
	if(depth==1)
	    return root;
	TreeLinkNode *r = getRightMost(root->right,depth-1);
	if(r==NULL)
	    r = getRightMost(root->left,depth-1);
	return r;
    }


public:
    void connect(TreeLinkNode *root) {
	if(root==NULL)
	    return;

	// children
	connect(root->left);
	connect(root->right);

	// connect between two children
	int dl = getDepth(root->left);
	int dr = getDepth(root->right);
	for(int i=1;i<=min(dl,dr);++i) {
	    TreeLinkNode *l=getRightMost(root->left,i);
	    TreeLinkNode *r=getLeftMost(root->right,i);
	    l->next = r;
	}

	return;

    }
};
