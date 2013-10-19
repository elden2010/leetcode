/*cannot pass large scale test, coz too slow*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int> > comb(int n,int k) {
//	cout << "n=" << n << ",k=" << k << endl;
	vector<vector<int> > ret;
	if(k==0)
	    return ret;
	if(k==1) {	    
	    for(int i=0;i<n;++i) {
		vector<int> row;
		row.push_back(i);
		ret.push_back(row);
	    }
	    return ret;
	}
	// k>1
	for(int i=0;i<n-k+1;++i) {
	    vector<vector<int> > tmp = comb(n-1-i,k-1);
	    for(unsigned j=0;j<tmp.size();++j) {
		vector<int> row;
		row.push_back(i);
		for(unsigned k=0;k<tmp[j].size();++k)
		    row.push_back(tmp[j][k]+i+1);
		ret.push_back(row);
	    }
	}
	return ret;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
	int m = s1.size();
	int n = s2.size();

	if(m==0)
	    return s2==s3;
	if(n==0)
	    return s1==s3;

	vector<vector<int> > combs = comb(m+n,m);
	bool ret = false;

	for(int i=0;i<combs.size();++i) {

	    vector<int> tComb = combs[i];
	    vector<int> tIndicator(m+n,0);
	    for(int j=0;j<tComb.size();++j)
		tIndicator[tComb[j]] = 1;

	    string s12;
	    int z1=0,z2=0;
	    for(int z=0;z<m+n;++z)
		if(tIndicator[z]==1) {
		    s12 += s1[z1];
		    z1++;
		} else {
		    s12 += s2[z2];
		    z2++;
		}

	    cout << "s12=" << s12<<endl;

	    if(s12==s3) {
		ret = true;
		break;
	    }
		
	}
	
	return ret;
        
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("","b","b") << endl;
}
