#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	int n = gas.size();
	// gain
	vector<int> leftover;
	for(int i=0;i<n;++i)
	    leftover.push_back(gas[i]-cost[i]);

	//
	int begin = 0;
	int end = 0;
	int sum = 0;
	int cur = begin;
	do {
	    sum += leftover[cur];
	    if(sum>=0) {
		end ++;
		if(end==n)
		    end = 0;
		cur = end;
	    } else {
		begin --;
		if(begin<0)
		    begin = n-1;
		cur = begin;
	    }
	} while(begin!=end);

	if(sum<0)
	    return -1;
	else
	    return begin;        
    }
};

int main() {
    vector<int> gas = {1,2};
    vector<int> cost = {2,1};
    Solution s;
    int ret = s.canCompleteCircuit(gas,cost);
    cout << ret << endl;
}
