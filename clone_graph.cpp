#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	UndirectedGraphNode* ret = NULL;
	if(node==NULL)
	    return ret;

	vector<UndirectedGraphNode*> ind2addr2;   // save mapping from index to node* in dst graph
	map<UndirectedGraphNode*,int> addr2ind1; // save mapping from node* to index in src graph

	// 1st BFS to clone nodes, using addr2ind1 as indicator of visited
        // it has to work since each iteration, we copy one node only
	queue<UndirectedGraphNode*> Q;
	int n = 0;
	Q.push(node);
	while(!Q.empty()) {
	    UndirectedGraphNode* cur = Q.front();
	    Q.pop();

	    // record mapping for src node
	    addr2ind1[cur] = n;
	    ++n;

	    // clone cur to node2
	    UndirectedGraphNode* node2 = new UndirectedGraphNode(cur->label);
	    node2->neighbors.resize(cur->neighbors.size(),NULL);
	    if(ret==NULL) // one time deal to assign first node
		ret = node2;

	    // record mapping for cloned node
	    ind2addr2.push_back(node2);

	    // neighbors
	    for(auto kid : cur->neighbors)
		if(addr2ind1.count(kid)==0) // not visited
		    Q.push(kid);
	}

	cout << "1st BFS done" << endl;

	// 2nd BFS to clone edges
  	Q.push(node);
	set<UndirectedGraphNode*> visited; // need this
	while(!Q.empty()) {
	    UndirectedGraphNode* cur = Q.front();
	    Q.pop();
	    	    
	    // process all childen of cur, no nullptr
	    int curInd = addr2ind1[cur];
	    UndirectedGraphNode* cur2 = ind2addr2[curInd];
	    for(int i=0;i<cur->neighbors.size();++i) {
		int kidInd = addr2ind1[cur->neighbors[i]];
		UndirectedGraphNode* kid2 = ind2addr2[kidInd];
		cur2->neighbors[i] = kid2;
	    }		

	    // neighbors
	    for(auto kid : cur->neighbors)
		if(visited.count(kid)==0)
		    Q.push(kid);

	    visited.insert(cur);
	}   

	return ret;
    }
};

int main() {
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(1);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node1);

    Solution s;
    UndirectedGraphNode* ret1 = s.cloneGraph(node1);
    cout << "cloned" << endl;
}
