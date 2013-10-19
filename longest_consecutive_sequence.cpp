#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
	int n = num.size();
	
        // build hashtable so we can quickly check if a value exists
	unordered_set<int> ht(num.begin(),num.end());
	
        // use another hashtable to check if a value is visited
	unordered_set<int> visited;
	vector<int> sz;
	for(int i=0;i<n;++i)
	    if(visited.count(num[i])==0) {
		int tsz = 0;
               // BFS with i as root
		visited.insert(num[i]);
		queue<int> Q;
		Q.push(num[i]);
		
		while(!Q.empty()) {
		    int cur = Q.front();
		    Q.pop();
		    ++tsz;
		    
		    if(ht.count(cur+1)>0 && visited.count(cur+1)==0) {
			visited.insert(cur+1);
			Q.push(cur+1);
		    }
		    if(ht.count(cur-1)>0 && visited.count(cur-1)==0) {
			visited.insert(cur-1);
			Q.push(cur-1);
		    }
		    
		}
		sz.push_back(tsz);
	    }
	
	int ret = sz[0];
	for(int i=1;i<sz.size();++i)
	    if(ret<sz[i])
		ret = sz[i];
	
	return ret;
    }
};

int main() {
    vector<int> num;
    num.push_back(100);
    num.push_back(4);
    num.push_back(200);
    num.push_back(1);
    num.push_back(3);
    num.push_back(2);
    
    Solution s;
    cout << s.longestConsecutive(num) << endl;
}
