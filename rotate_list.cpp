struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    ListNode *rotateRight1(ListNode *head) {
	// at least 2 elements

	// find the one before tail
	ListNode* last2 = head;
	while(last2->next->next)
	    last2 = last2->next;

	// move tail to before head
	ListNode *ret = last2->next;
	ret->next = head;
	last2->next = NULL;
	
	return ret;
    }

public:
    ListNode *rotateRight(ListNode *head, int k) {
	// if empty or 1 element, do nothing
	if(head==NULL || head->next==NULL)
	    return head;

	ListNode *ret = head;
	for(int i=0;i<k;++i)
	    ret = rotateRight1(ret);
	
	return ret;
    }

};
