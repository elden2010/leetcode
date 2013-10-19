
class Solution {
  int getHeight(TreeNode *root) {
    int h;
    if(!root) {
      h = 0;
    } else {
      int h1 = getHeight(root->left);
      int h2 = getHeight(root->right);
      h = h1>h2 ? h1+1 : h2+1;
    }      
    return h;
  }
public:
  bool isBalanced(TreeNode *root) {
    bool ret = false;
    if(!root)
      ret = true;
    else
      if(isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left)-getHeight(root->right))<=1)
	ret = true;
    
    return ret;

  }
};
