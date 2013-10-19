class Solution {
    int dp[101][101];
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	if(obstacleGrid[0][0]==1)
	    return 0;
	
	int m=obstacleGrid.size();
	int n=obstacleGrid[0].size();
	
	for(int i=0;i<101;++i)
	    for(int j=0;j<101;++j)
		dp[i][j]=1;
	
	int firstbad = 1;
	for(;firstbad<=m;firstbad++)
	    if(obstacleGrid[firstbad-1][0]==1)
		break;
	if(firstbad<m+1) // there is a obs
	    for(int i=firstbad;i<=m;++i)
		dp[i][1]=0;
	
	firstbad = 1;
	for(;firstbad<=n;firstbad++)
	    if(obstacleGrid[0][firstbad-1]==1)
		break;
	if(firstbad<n+1) // there is a obs
	    for(int i=firstbad;i<=n;++i)
		dp[1][i]=0;
        
	for(int i=2;i<=m;++i)
	    for(int j=2;j<=n;++j)
		if(obstacleGrid[i-1][j-1]==1)
		    dp[i][j]=0;
		else
		    dp[i][j] = dp[i-1][j]+dp[i][j-1];
	
	
	return dp[m][n];
    }
};
