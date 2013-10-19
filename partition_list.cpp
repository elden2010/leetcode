#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
	if(head==NULL)
	    return NULL;
	if(head->next==NULL)
	    return head;

	ListNode *cur=head;
	ListNode *toInsertAfter=NULL;
	ListNode *xPlus1st=NULL;

        // keep the first node there 
	if(cur->val>=x)
	    xPlus1st = cur;
	else
	    toInsertAfter = cur;

	// loop through the rest nodes
	while(cur->next!=NULL) { // next node is not empty
	    if(cur->next->val<x) { // next node < x
		if(xPlus1st!=NULL) {// there is a node >=x already
		    // remove from current position
		    ListNode *node2remove = cur->next;
		    cur->next = cur->next->next;;
		    // insert into a proper position
		    if(toInsertAfter==NULL)
			head = node2remove;
		    else
			toInsertAfter->next = node2remove;
		    toInsertAfter = node2remove;
		    node2remove->next = xPlus1st;
		} else {// else leave it there
		    cur = cur->next;
		    toInsertAfter = cur;
		}
	    } else {// next node >= x
		if(xPlus1st==NULL)
		    xPlus1st = cur->next;
		cur = cur->next;
	    }
	}
	    
	return head;
    }
};

void print(ListNode* head) {
    if(head==NULL) {
	cout << "NULL" << endl;
	return;
    } 
    cout << head->val << "->";
    print(head->next);
}


int main() {
    ListNode *l1=new ListNode(1);
    ListNode *l2=new ListNode(2);
    ListNode *l3=new ListNode(0);
    ListNode *l4=new ListNode(1);
    ListNode *l5=new ListNode(2);
    ListNode *l6=new ListNode(4);
    ListNode *l7=new ListNode(1);
    ListNode *l8=new ListNode(2);
    ListNode *l9=new ListNode(0);
    ListNode *l10=new ListNode(0);
    ListNode *l11=new ListNode(3);

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;
    l10->next = l11;

    print(l1);

    Solution s;
    ListNode *ret = s.partition(l1, 3);
    print(ret);
    
}
