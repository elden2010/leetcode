#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
    ListNode *reverse(ListNode *head) {
	if(head==NULL || head->next==NULL)
	    return head;
	ListNode *tail = head->next;
	ListNode *ret = reverse(head->next);
	tail->next = head;
	return ret;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
	// count how many nodes are there
	ListNode *p = head;
	int cc = 0;
	while(p) {
	    ++cc;
	    p = p->next;
	}
	if(cc==1 || cc<k) // if less than k, leave as it is
	    return head;

	// break into two pieces, first,second
	ListNode *first=head,*second=head;
	cc=0;
	while(cc<k-1) { // walk k-1 times so I got the parent of second piece
	    second = second->next;
	    ++cc;
	}
	ListNode* tailoffirst = second;
	second = second->next;
	tailoffirst->next = NULL;

	// reverse first in 1 group
	ListNode *ret = reverse(first);
	// reverse second in k group
	ListNode *ret2 = reverseKGroup(second,k);
	// connect the first and second piece
	head->next = ret2;
	
	return ret;
    }
};

int main() {
    ListNode *a1= new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(1);
    a1->next = a2;
    a2->next = a3;


    Solution s;
    ListNode *b = s.reverseKGroup(a1,2);

    while(b) {
	cout << b->val << "->";
	b = b->next;
    }
    cout << endl;

    delete a1;
    delete a2;
    delete a3;

}
