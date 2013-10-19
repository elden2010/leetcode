#include <iostream>
#include <cstdlib>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* generate(int n) {
    if(n==0)
	return NULL;

    int v = rand() % 100; 
    ListNode *head = new ListNode(v);
    ListNode* head2 = generate(n-1);
    head->next = head2;
    return head;
}

void print(ListNode* head) {
    if(head==NULL) {
	cout << "NULL" << endl;
	return;
    } 
    cout << head->val << "->";
    print(head->next);
}

class Solution {
    void rev(ListNode *head,ListNode *tail,ListNode **newhead,ListNode **newtail) {
	if(head==tail) {
	    *newhead = head;
	    *newtail = head;
	    return;
	}
	
	ListNode *h2,*t2;
	rev(head->next,tail,&h2,&t2);
	t2->next = head;

	*newhead = h2;
	*newtail = head;
	return;
    }
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(m==n)
	    return head;

	// remember all 4 important nodes, in addition to newhead	
	
	ListNode *cur = head;
	int ind=1;
	
	// before m exist?
	ListNode *before_m,*at_m;
	while(ind<m-1) { // to make ind==m-1 so ind is at before_m
	    cur = cur->next;
	    ind++;
	}
	if(ind==m-1) {
	    before_m = cur;
	    cur = cur->next;
	    ind++;
	    at_m = cur;
	} else {
	    before_m = NULL;
	    at_m = cur;
	}
	
	// at n
	while(ind<n) {
	    cur = cur->next;
	    ind++;
	}
	ListNode *at_n = cur;	
        ListNode *after_n = cur->next;
	    
	ListNode *new_at_m,*new_at_n;
	rev(at_m,at_n,&new_at_m,&new_at_n);
	
	if(before_m!=NULL)
	    before_m->next = new_at_m;
	else
	    head = new_at_m;
	new_at_n->next = after_n;

	return head;
    }
};

int main() {
    Solution s;
    for(int z=2;z<3;++z) {
	ListNode *head = generate(z);
	cout << "before:" << endl;
	print(head);

	ListNode * newhead = s.reverseBetween(head,1,2);
	cout << "after:" << endl;
	print(newhead);

	cout << endl;
    }
}
