/*
this one can  pass large scale test:
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<int> > cs(vector<int> &can,vector<int> freqmax,int n,int t) {
	// use only the first n elements of can as basis, to get t
	vector<vector<int> > ret;
	if(n==1) { // base for recursion: only 1st candidate
	    if(t % can[0] == 0 && t/can[0]<=freqmax[0]) {
		vector<int> retrow;	
		retrow.push_back(t/can[0]);
		ret.push_back(retrow);
	    }
	} else {    // recursion with one less candidates for different targets
	    for(int k=0;k<=freqmax[n-1] && k*can[n-1]<=t;++k) {
		vector<vector<int> > ret2 = cs(can,freqmax,n-1,t-k*can[n-1]);
		for(int z=0;z<ret2.size();++z) {
		    vector<int> retrow;
		    for(int zz=0;zz<ret2[z].size();++zz)
			retrow.push_back(ret2[z][zz]);
		    if(!retrow.empty()) {
			retrow.push_back(k);
			ret.push_back(retrow);
		    }
		}
	    }
	}

	return ret;

    }

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
	// find freq of elements by counting
	map<int,int> basFreq;
	for(int i=0;i<num.size();++i)
	    ++ basFreq[num[i]];
	vector<int> basis,freqmax;
	for(map<int,int>::iterator it=basFreq.begin();it!=basFreq.end();++it) {
	    basis.push_back(it->first);
	    freqmax.push_back(it->second);
	}
	
	// do it
	vector<vector<int> > freq = cs(basis,freqmax,basis.size(),target);

	// convert from frequency representation to as required
	vector<vector<int> > ret;
	for(int i=0;i<freq.size();++i) {
	    vector<int> retrow;
	    for(int j=0;j<basis.size();++j)		
		for(int k=0;k<freq[i][j];++k)
		    retrow.push_back(basis[j]);
	    ret.push_back(retrow);
	}

	return ret;
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
