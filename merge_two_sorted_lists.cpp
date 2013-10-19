class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1,ListNode *l2) {

	ListNode *ret1 = l1;
	ListNode *ret2 = l2;

	// if one list is empty
	if(ret1==NULL)
	    return ret2;
	if(ret2==NULL)
	    return ret1;
	
	ListNode *ret12head = NULL;
	ListNode *ret12tail = NULL;
	// if neither list is empty at first
	while(ret1!=NULL || ret2!=NULL) // loop till both empty
	    if(ret1==NULL) {// no need to update ret12tail itself, since it is no longer needed after this
		ret12tail->next = ret2;
		ret2 = NULL;
	    }
	    else if(ret2==NULL) {
		ret12tail->next = ret1;
		ret1 = NULL;
	    } else {
		ListNode* tmp;
		if(ret1->val < ret2->val) {
		    tmp  = new ListNode(ret1->val);
		    ret1 = ret1->next;
		} else {
		    tmp  = new ListNode(ret2->val);
		    ret2 = ret2->next;
		}
		if(ret12head==NULL) {
		    ret12head = tmp;
		    ret12tail = tmp;
		} else {
		    ret12tail->next = tmp;
		    ret12tail = tmp;
		}
	    } 
	
	// 
	return ret12head;
    }
};
