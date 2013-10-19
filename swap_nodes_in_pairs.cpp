/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
	// if 0 or 1 elements in the list
	if(head==NULL || head->next==NULL)
	    return head;
	
	// 2 or more elements
	ListNode* ret = head->next;
	head->next = swapPairs(head->next->next);
	ret->next = head;
	return ret;
    }
};
