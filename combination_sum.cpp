#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    vector<vector<int> > cs(vector<int> &can,int n,int t) {
	// use only the first n elements of can as basis, to get t
	vector<vector<int> > ret;
	if(n==1) { // base for recursion: only 1st candidate
	    if(t % can[0] == 0) { // if multiples of the 1st candidate
		vector<int> retrow;
		retrow.push_back(t/can[0]);
		ret.push_back(retrow);
	    }
	} else {    // recursion with one less candidates for different targets
	    for(int k=0;k*can[n-1]<=t;++k) {
		vector<vector<int> > ret2 = cs(can,n-1,t-k*can[n-1]);
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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	sort(candidates.begin(),candidates.end());

	vector<vector<int> > freq = cs(candidates,candidates.size(),target);

	// convert from frequency representation to as required
	vector<vector<int> > ret;
	for(int i=0;i<freq.size();++i) {
	    vector<int> retrow;
	    for(int j=0;j<candidates.size();++j)		
		for(int k=0;k<freq[i][j];++k)
		    retrow.push_back(candidates[j]);
	    ret.push_back(retrow);
	}
	
	return ret;
    }

};

int main() {

    vector<int> candidates;
    candidates.push_back(1);
    candidates.push_back(2);
//    candidates.push_back(3);

    Solution s;
    vector<vector<int> > ret = s.combinationSum(candidates,3);

    for(int i=0;i<ret.size();++i) {
	for(int j=0;j<ret[i].size();++j)
	    cout << ret[i][j] << " ";
	cout << endl;
    }
}
