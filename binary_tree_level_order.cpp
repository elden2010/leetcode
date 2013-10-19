class Solution {
public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    vector<vector<int> > ret;
    vector<vector<TreeNode*> > allLvl; // store all TreeNodes in levels

    if(root) {
      // initial set up
      vector<TreeNode*> newLvl;
      newLvl.push_back(root);
      allLvl.push_back(newLvl);

      // iteration through levels
      do {
	newLvl.clear();
	vector<TreeNode*> &oldLvl = allLvl.back();
	
	//
	for(vector<TreeNode*>::iterator it=oldLvl.begin();it!=oldLvl.end();++it) {
	  TreeNode* tnode = (*it);
	  if(tnode->left)
	    newLvl.push_back(tnode->left);
	  if(tnode->right)
	    newLvl.push_back(tnode->right);
	}
	
	if(!newLvl.empty()) 
	  allLvl.push_back(newLvl);

      } while (!newLvl.empty());

      // store val
      for(vector<vector<TreeNode*> >::iterator it1 = allLvl.begin();it1!=allLvl.end();++it1) {
	vector<TreeNode*> tNodes = *it1;
	vector<int> tVals;
	for(vector<TreeNode*>::iterator it2 = tNodes.begin();it2!=tNodes.end();++it2)
	  tVals.push_back((*it2)->val);
	ret.push_back(tVals);
      }
    }

    return ret;
  }
};
