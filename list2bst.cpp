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
    TreeNode *sortedListToBST(ListNode *head) {
	vector<int> num;
	ListNode *cur=head;
	while(cur) {
	    num.push_back(cur->val);
 	    cur = cur->next;
	}
        return  sortedArrayToBST(num.begin(),num.end());
    }
};
