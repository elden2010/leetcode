#include <vector>
#include <iostream>

using namespace std;

class Solution {
    static const int maxn = 100;
    vector<int> dp;
public:
    Solution() {
	dp.resize(maxn,0);
	dp[0]=1;
	dp[1]=1;
    }

    int numTrees(int n) {
	if(n<maxn && dp[n]!=0)
	    return dp[n];

	int ret = 0;
	for(int i=0;i<n;++i)
	    ret += numTrees(i) * numTrees(n-1-i);

	if(n<maxn)
	    dp[n] = ret;
	return ret;
    }
};

int main() {
    Solution s;
    for(int i=0;i<100;++i)
	cout << s.numTrees(i) << endl;
}
