/*
  this is a much more neat program than the first version
 */
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  void update(ListNode **head,ListNode **tail,int sum) {
    ListNode *latest = new ListNode(sum);
    if(*head) {
      (*tail)->next = latest;
      *tail = latest;	  
    } else {
      *head = latest;
      *tail = latest;	  
    }
  }
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head=NULL,*tail=NULL;
    int carry = 0;
    while(l1 || l2 || carry) {
      int sum = 0;
      if(l1) {
	sum += l1->val;
	l1 = l1->next;
      } 
      if(l2) {
	sum += l2->val;
	l2 = l2->next;	
      } 
      if(carry) 
	sum += carry;
      if(sum>=10) {
	sum -= 10;
	carry = 1;
      } else
	carry=0;
      update(&head,&tail,sum);
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
