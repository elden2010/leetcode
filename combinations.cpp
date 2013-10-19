#include <algorithm>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
	vector<vector<int> > ret;
	set<vector<int> > ret0;

	vector<int> raw(n,0);
	for(int i=0;i<n;++i)
	    raw[i] = i+1;

	do {
	    vector<int> kofn;
	    copy(raw.begin(),raw.begin()+k,back_inserter(kofn));
	    sort(kofn.begin(),kofn.end());
	    ret0.insert(kofn);
	} while(next_permutation(raw.begin(),raw.end()));

	for(set<vector<int> >::iterator it=ret0.begin();it!=ret0.end();++it)
	    ret.push_back(*it);

	return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int> > ret = s.combine(4,2);

    for(int i=0;i<ret.size();++i) {
	for(int j=0;j<ret[i].size();++j)
	    cout << ret[i][j] << " ";
	cout << endl;
    }
}
