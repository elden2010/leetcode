/*
 using iterative way for in-order traversal
 the key is to use stack to store all nodes with a left tree
 
 */

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;

    stack<TreeNode*> stk;
    TreeNode *cur=root;
    bool curVisited=false;

    while(!stk.empty() || cur) {

      if(cur) // non empty
	if(cur->left && !curVisited) { //has left child and cur is first visit
	  stk.push(cur); // store it
	  cur = cur->left; // descend left
	  curVisited = false;
	} else { // no left child, or cur is popped from stack
	  ret.push_back(cur->val); // print cur
	  cur = cur->right; // descend right	 
	  curVisited = false;
	}
      else { // empty, so pop the top out
	cur = stk.top();
	stk.pop();
	curVisited = true;
      }

    }

    return ret;
  }
};
