/*
both v1 and v2 have the memory problem for the large test
coz:
I used double loop to multiply existing path with current choices
even if I just save one last node for each path, that multiplication is approximately exponential for long T
I ought to use DP as others do

V3: DP here

*/

#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int numDistinct(string S, string T) {
	int m=S.size();
	int n=T.size();
	if(m<n)
	    return 0;

	vector<int> row(n,0);
	vector<vector<int> > dp(m,row); // just save the last node of each path

	// initialization first column
	int cc = 0;
	for(int i=0;i<m;++i)
	    if(S[i]==T[0])
		dp[i][0] = ++cc;
	    else
		dp[i][0] = cc;
		
	// bottom up dp
	for(int i=0;i<m;++i)
	    for(int j=1;j<n;++j)
		if(i>=j)
		    if(S[i]==T[j])
			dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
		    else
			dp[i][j] = dp[i-1][j];

	return dp[m-1][n-1];
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("rabbbit","rabbit") << endl;
}
