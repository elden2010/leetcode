#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> num;
    void work(TreeNode *node, int p) {
	if(node==NULL)
	    return;

	int p2 = 10*p + node->val;

	// leaf node
	if(node->left==NULL && node->right==NULL) {
	    num.push_back(p2);
	    return;
	}

	// has left branch
	if(node->left)
	    work(node->left,p2);

	if(node->right)
	    work(node->right,p2);

	return;
    }
public:
    int sumNumbers(TreeNode *root) {
	num.clear();

	work(root,0);

	int sum = 0;
	for(size_t i=0;i<num.size();++i)
	    sum += num[i];

	return sum;
    }
};

int main() {
    TreeNode a(0),b(1);
    a.left = &b;

    Solution s;
    cout << s.sumNumbers(&a) << endl;
}
