#include <vector>
#include <iostream>

using namespace std;

class Solution {
    static int pattern[4];    
public:
    vector<int> grayCode(int n) {
	int m = 1<<n;

	vector<vector<int> > retbin;
	for(int i=0;i<m;++i) {
	    vector<int> retbinrow(n,0);
	    retbin.push_back(retbinrow);
	}

	for(int j=n-1;j>=0;--j) {
	    int multi = 1 << (n-1-j);	
	    for(int i=0;i<m;++i) { // loop through pattern
		int ind = i/multi % 4;
		retbin[i][j] = pattern[ind];
	    }
	}

	vector<int> ret;
	for(int i=0;i<m;++i) {
	    int rowv = 0;
	    for(int j=0;j<n;++j)
		if(retbin[i][j])
		    rowv += 1 << (n-1-j);
	    ret.push_back(rowv);
	}

	return ret;
    }
};

int Solution::pattern[4] = {0,1,1,0}; 

int main() {
    Solution s;
    vector<int> seq = s.grayCode(3);

    for(int i=0;i<seq.size();++i)
	cout << seq[i] << endl;
}
