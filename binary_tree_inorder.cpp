class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    if(root) {
      vector<int> ret1 = inorderTraversal(root->left);
      for(vector<int>::iterator it=ret1.begin();it!=ret1.end();++it)
	ret.push_back(*it);

      ret.push_back(root->val);

      vector<int> ret2 = inorderTraversal(root->right);
      for(vector<int>::iterator it=ret2.begin();it!=ret2.end();++it)
	ret.push_back(*it);    
    }
    return ret;
  }
};
