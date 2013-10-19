#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head=NULL, *tail=NULL;
    int carry = 0;
    while(l1 || l2) {
      if(l1 && l2) {
	int sum = l1->val + l2->val + carry;
	if(sum>=10) {
	  sum -= 10;
	  carry = 1;
	} else
	  carry=0;
	ListNode *latest = new ListNode(sum);
	if(head) {
	  tail->next = latest;
	  tail = latest;	  
	} else {
	  head = latest;
	  tail = latest;	  
	}
	l1 = l1->next;
	l2 = l2->next;
      } else if(l1) {
	int sum = l1->val + carry;
	if(sum>=10) {
	  sum -= 10;
	  carry = 1;
	} else
	  carry=0;
	ListNode *latest = new ListNode(sum);
	if(head) {
	  tail->next = latest;
	  tail = latest;	  
	} else {
	  head = latest;
	  tail = latest;	  
	}
	l1 = l1->next;	
      } else {
	int sum = l2->val + carry;
	if(sum>=10) {
	  sum -= 10;
	  carry = 1;
	} else
	  carry=0;
	ListNode *latest = new ListNode(sum);
	if(head) {
	  tail->next = latest;
	  tail = latest;	  
	} else {
	  head = latest;
	  tail = latest;	  
	}
	l2 = l2->next;
      }
    }
    if(carry) {
      ListNode *latest = new ListNode(1);
      tail->next = latest;
      tail = latest;	  
    }
    return head;
  }
};

int main() {
  Solution s;
  ListNode a1(2),a2(4),a3(3),b1(5),b2(6),b3(4);
  a1.next = &a2;
  a2.next = &a3;
  b1.next = &b2;
  b2.next = &b3;
  ListNode *ret = s.addTwoNumbers(&a1,&b1);

  while(ret) {
    cout << ret->val;
    if(ret->next)
      cout << "->";
    ret = ret->next;    
  }
  cout << endl;
}
