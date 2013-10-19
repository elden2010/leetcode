
class Solution {
public:
    int minDistance(string word1, string word2) {
    // initialization
	int m = word1.size();
	int n = word2.size();
	vector<vector<int> > dp;
	for(int i=0;i<m+1;++i) {
	    vector<int> row(n+1,0);
	    dp.push_back(row);
	}
	for(int j=1;j<n+1;++j)
	    dp[0][j] = j;
	for(int i=1;i<m+1;++i)
	    dp[i][0] = i;
		
	for(int i=1;i<m+1;++i)
	    for(int j=1;j<n+1;++j)
		if(word1[i-1]==word2[j-1])
		    dp[i][j] = dp[i-1][j-1];
		else
		    dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;

	return dp[m][n];        
    }
};
