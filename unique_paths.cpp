#include <iostream>
using namespace std;

class Solution {
    int dp[101][101];
public:
    
    Solution() {
	for(int i=0;i<101;++i)
	    for(int j=0;j<101;++j)
		dp[i][j] = 0;
    }

    int uniquePaths(int m, int n) {
	if(m==1 || n==1)
	    return 1;

	if(dp[m][n]!=0)
	    return dp[m][n];

	int ret=0;
	for(int i=1;i<=m;++i)
	    ret += uniquePaths(i,n-1);

	dp[m][n] = ret;

	return ret;
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(100,3) << endl;
}
