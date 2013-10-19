/* v1 used recursion and this v2 will use iteration) */
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
    bool isSymmetric(TreeNode *root) {
	if(root==NULL)
	    return true;

	bool ret = true;;
	stack<TreeNode*> st;
	st.push(root->right);
	st.push(root->left);
	while(!st.empty()) {
	    TreeNode *p1 = st.top();
	    st.pop();
	    TreeNode *p2 = st.top();
	    st.pop();
	    if(p1==NULL && p2==NULL)
		continue;
	    if((p1==NULL && p2!=NULL) ||
	       (p1!=NULL && p2==NULL) ||
	       (p1->val!=p2->val)) {
		ret = false;
		break;
	    }
	    st.push(p2->left);
	    st.push(p1->right);
	    st.push(p2->right);
	    st.push(p1->left);
	}
	return ret;
    }
};
