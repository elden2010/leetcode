#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *lst) {
    while(lst) {
	cout << lst->val << "->";
	lst = lst->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {

	int k = lists.size();
	if(k==0)
	    return NULL;
	if(k==1)
	    return lists[0];

	ListNode *ret1 = lists[0];
	for(int i=1;i<k;++i) {
	    ListNode *ret2 = lists[i];
	    // if one list is empty
	    if(ret1==NULL) {
		ret1 = ret2;
		continue;
	    }
	    if(ret2==NULL) {
		ret1 = ret1;
		continue;
	    }

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
	    ret1 = ret12head;
	}

	return ret1;
    }
};

int main() {

    ListNode *e1=new ListNode(-1);
    ListNode *e2=new ListNode(5);
    ListNode *e3=new ListNode(1);
    ListNode *e4=new ListNode(4);
    ListNode *e5=new ListNode(6);
    ListNode *e6=new ListNode(4);
    ListNode *e7=new ListNode(5);
    ListNode *e8=new ListNode(6);

    ListNode *l1 = NULL;

    ListNode *l2 = e1;
    e1->next = e2;

    ListNode *l3 = e3;
    e3->next = e4;
    e4->next = e5;

    ListNode *l4 = e6;
    e6->next = e7;
    e7->next = e8;

    print(l1); 
    print(l2); 
    print(l3); 
    print(l4); 


    vector<ListNode*> ls{l1,l2,l3,l4};
    Solution s;
    ListNode *l1234 = s.mergeKLists(ls);
    print(l1234);
}
