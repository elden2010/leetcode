#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
	int cur;
	ListNode *src,*dst,*pdst;
	src = head;
	dst = head;
	pdst = NULL; // parent to dst

	while(src)
	    if(src==head) {
		cur = src->val;
		src = src->next;
		pdst = dst;
		dst = src;
	    } else
		if(cur == src->val)
		    src = src->next;
		else {
		    dst->val = src->val;
		    cur = src->val;
		    src = src->next;
		    pdst = dst;
		    dst = dst->next;
		}
	
        // cut off useless tails
	if(pdst)
	    pdst->next = NULL;

	/*       // free tail nodes
	while(dst) {
	    ListNode* tnode = dst;
	    dst = dst->next;
	    if(tnode) 
		delete tnode; 
		}*/

	return head;
    }
};

int main() {
    ListNode a(1),b(1);
    a.next = &b;

    Solution s;
    ListNode* ret = s.deleteDuplicates(&a);
    while(ret) {
	cout << ret->val << "->";
	ret=ret->next;
    }
    cout << endl;

}
