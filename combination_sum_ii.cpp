/*
cannot pass large scale test:
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    set<vector<int> > cs(vector<int> &can,int n,int t) {
	// use only the first n elements of can as basis, to get t
	set<vector<int> > ret;
	if(n==1) { // base for recursion: only 1st candidate
	    vector<int> retrow;	
	    if(t == 0) {
		retrow.push_back(0);
		ret.insert(retrow);
	    } else if(t == can[0]) {// if multiples of the 1st candidate
		retrow.push_back(1);
		ret.insert(retrow);
	    }
	} else {    // recursion with one less candidates for different targets
	    for(int k=0;k<2 && k*can[n-1]<=t;++k) {
		set<vector<int> > ret2 = cs(can,n-1,t-k*can[n-1]);
		for(set<vector<int> >::iterator it=ret2.begin();it!=ret2.end();++it) {
		    vector<int> ret2row=*it,retrow;
		    for(int zz=0;zz<ret2row.size();++zz)
			retrow.push_back(ret2row[zz]);
		    if(!retrow.empty()) {
			retrow.push_back(k);
			ret.insert(retrow);
		    }
		}
	    }
	}

	return ret;

    }

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	sort(num.begin(),num.end());

	set<vector<int> > freq = cs(num,num.size(),target);

	// convert from frequency representation to as required
	set<vector<int> > ret;
	for(set<vector<int> >::iterator it=freq.begin();it!=freq.end();++it) {
	    vector<int> freqrow = *it, retrow;
	    for(int j=0;j<num.size();++j)		
		for(int k=0;k<freqrow[j];++k)
		    retrow.push_back(num[j]);
	    ret.insert(retrow);
	}

	vector<vector<int> > ret2;
	for(set<vector<int> >::iterator it=ret.begin();it!=ret.end();++it) {
	    ret2.push_back(*it);
	}	
	return ret2;
    }

};

int main() {

    vector<int> num;
    num.push_back(1);
    num.push_back(1);
//    num.push_back(3);

    Solution s;
    vector<vector<int> > ret = s.combinationSum2(num,1);

    for(int i=0;i<ret.size();++i) {
	for(int j=0;j<ret[i].size();++j)
	    cout << ret[i][j] << " ";
	cout << endl;
    }
}
