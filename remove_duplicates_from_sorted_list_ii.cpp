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
	int cur,curcount;
	ListNode *src,*dst,*pdst;
	src = head;

	while(src)
	    if(src==head) {
		cur = src->val;
		curcount = 1;
		dst = src;
		pdst = NULL;
		src = src->next;
	    } else
		if(cur == src->val) {// repeating
		    src = src->next;
		    ++ curcount;
		} else if(curcount==1) {// got a different char and cur is unique so save it
		    dst->val = cur;
		    cur = src->val;
		    curcount = 1;
		    src = src->next;
		    pdst = dst;
		    dst = dst->next;
		} else { // got a different char but cur has repeating
		    cur = src->val;
		    curcount = 1;
		    src = src->next;
		}

	if(curcount==1) {
	    dst->val = cur;
	    dst->next = NULL;
	} else { // >1
	    if(pdst)
		pdst->next = NULL;
	    else
		head = NULL;
	}
	
	return head;
    }
};

int main() {
    ListNode a(1),b(1);
    a.next = &b;
    // b.next= &c;

    Solution s;
    ListNode* ret = s.deleteDuplicates(&a);
    while(ret) {
	cout << ret->val << "->";
	ret=ret->next;
    }
    cout << endl;

}
