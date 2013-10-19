/*
this one just uses dp (memorization+bottom up) to do it
it is easy once you got the dp idea clear
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<bool> > dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
	int m = s1.size();
	int n = s2.size();
	if(m+n!=s3.size())
	    return false;

	// storage
	dp.clear();
	for(int i=0;i<m+1;++i) {
	    vector<bool> row(n+1,false);
	    dp.push_back(row);
	}
	// initialization of boundary row and column
	dp[0][0] = true;
	for(int i=1;i<m+1;++i)
	    dp[i][0] = s1[i-1]==s3[i-1];
	for(int j=1;j<n+1;++j)
	    dp[0][j] = s2[j-1]==s3[j-1];

	// loop through m*n
	for(int i=1;i<m+1;++i)
	    for(int j=1;j<n+1;++j)
		if( (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]) )
		    dp[i][j] = true;

	return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("aacaac", "aacaaeaac", "aacaaeaaeaacaac") << endl;
}
