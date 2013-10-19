#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  int getMinBST(TreeNode *root);
  int getMaxBST(TreeNode *root);
public:
  bool isValidBST(TreeNode *root);
};


int Solution::getMinBST(TreeNode *root) {
  TreeNode *cur = root;
  while(cur->left)
    cur = cur->left;
  return cur->val;
}

int Solution::getMaxBST(TreeNode *root) {
  TreeNode *cur = root;
  while(cur->right)
    cur = cur->right;
  return cur->val;
}

bool Solution::isValidBST(TreeNode *root) {
  bool ret = true;

  if(root) {
      if(root->left)
	  if(!isValidBST(root->left) || root->val <= getMaxBST(root->left))
	      ret = false;
      
      if(root->right)
	  if(!isValidBST(root->right) || root->val >= getMinBST(root->right))
	      ret = false;
  }
  return ret;
}

int main() {
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(1);
  //  TreeNode *right = new TreeNode(8); 
  root->left = left;
  //root->right = right;

  Solution s;
  bool result = s.isValidBST(root);
  cout << result << endl;

  delete root;
  delete left;
}
