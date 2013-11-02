/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
class Solution {
public:
    bool hasCycle(ListNode *head) {
	// use associative container to check if we meet the same node again
	set<ListNode*> nodes;
	ListNode* cur=head;
	while(cur) {
	    if(nodes.count(cur)==0) { // not found
		nodes.insert(cur);
		cur = cur->next;
	    } else {
		return true;
	    }
	}
	return false;
    }
};
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
	// use two pointers to check if they meet
	ListNode *fast=head, *slow=head;
	while(fast!=NULL && fast->next!=NULL) {
	    if(fast==fast->next || fast==fast->next->next)
		return true;
	    if(slow!=head && slow==fast)
		return true;
	    fast = fast->next->next;
	    slow = slow->next;
	}
	return false;
    }
};
