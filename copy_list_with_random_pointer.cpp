#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
}; 

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode* head) {
	// copy nodes by following next pointer
	RandomListNode *cur = head, *retHead=NULL,*retTail=NULL;
	int n = 0;
	// iterate through original list to record the next
	map<RandomListNode*,int> addr2ind;
	// to record the next for copied list as well
	vector<RandomListNode*> ind2addr;

	while(cur) {
	    RandomListNode* newNode = new RandomListNode(cur->label); 
	    if(retHead==NULL) { // first node
		retHead = newNode;
		retTail = newNode;
	    } else { // attach to end of the new list
		retTail->next = newNode;
		retTail = newNode;
	    }
	    addr2ind[cur] = n;
	    ind2addr.push_back(newNode);
	    ++n;
	    cur = cur->next;
	}

	// iterate through original list to check random pointer
	// and save to ind2ind
	map<int,int> ind2ind;
	cur = head;
	n = 0;
	while(cur) {
	    int iRandom = -1;
	    if(cur->random) 
		iRandom = addr2ind[cur->random];
	    ind2ind[n] = iRandom;
	    ++n;
	    cur = cur->next;
	}

	// iterate through the new list and update random pointer
	for(int i=0;i<n;++i) {
	    int targetInd = ind2ind[i];
	    if(targetInd!=-1)
		ind2addr[i]->random = ind2addr[targetInd];
	}

	return retHead;

    }
};


//not sure how to print out random pointer as well
void print(RandomListNode* head) {
    RandomListNode* cur = head;
    while(cur) {
	cout << cur->label << "->";
	cur = cur->next;
    }
    cout << endl;
}

int main() {
    RandomListNode *h1 = new RandomListNode(-1);

    Solution s;
    RandomListNode *ret = s.copyRandomList(h1);

    print(ret);
    
}
