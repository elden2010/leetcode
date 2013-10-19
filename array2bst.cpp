typedef vector<int>::iterator vii;
class Solution {
    TreeNode *sortedArrayToBST(vii be,vii en) {
    if(be==en)
	    return NULL;

 	int n = en-be;
	int mid = n/2;

	TreeNode *root = new TreeNode(*(be+mid));
	TreeNode *left = sortedArrayToBST(be,be+mid);
	TreeNode *right = sortedArrayToBST(be+mid+1,en);

	root->left = left;
	root->right = right;
	
	return root;
    }	
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
       return  sortedArrayToBST(num.begin(),num.end());
    }
};
