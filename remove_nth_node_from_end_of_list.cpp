#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
	ListNode *cur = head;
	vector<ListNode*> vl;
	while(cur) {
	    vl.push_back(cur);
	    cur=cur->next;
	}

	if(vl.empty())
	    return NULL;
	
	if(vl.size()==1) 
	    if(n==0)
		return head;
	    else
		return NULL;
	    
	// now assume more than 2 nodes

	if(n==1) { // to remove the last
	    ListNode *before = vl[vl.size()-2];
	    before->next = NULL;
	} else if(n==vl.size()) {// to remove the first
	    head = head->next;
	} else {
	    ListNode *before = vl[vl.size()-n-1];
	    ListNode *after = vl[vl.size()-n+1];
	    before->next = after;
	}

	return head;
    }
};

int main() {

    ListNode a(1),b(2);
    a.next = &b;

    Solution s;
    ListNode *ret =s.removeNthFromEnd(&a,2);

    while(ret) {
	cout << ret->val << "->";
	ret = ret->next;
    }
    cout << endl;
    
    return 0;
}
