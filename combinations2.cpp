#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ret;

	if(k==0 || n<k)
	    return ret;

	for(int i=0;i<n-k+1;++i) {
	    vector<vector<int> > ret2 = combine(n-i-1,k-1);
	    if(ret2.empty()) {
		//cout << "damn:n="<<n<<",k="<<k << endl;
		vector<int> one;
		one.push_back(i+1);
		ret.push_back(one);
	    } else
		for(int ii=0;ii<ret2.size();++ii) {
		    vector<int> one;
		    one.push_back(i+1);
		    for(int j=0;j<ret2[ii].size();++j)
			one.push_back(i+1+ret2[ii][j]);
		    ret.push_back(one);
		}
	}
	
	return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int> > ret = s.combine(5,3);

    for(int i=0;i<ret.size();++i) {
	for(int j=0;j<ret[i].size();++j)
	    cout << ret[i][j] << " ";
	cout << endl;
    }
}
