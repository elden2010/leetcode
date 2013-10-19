/*
can pass only small test
*/
class Solution {
    int doit(vector<vector<int> > &obs,int r1,int r2,int c1,int c2) {
	if(obs[r1][c1]==1)
	    return 0;
	if(r1==r2 && c1==c2)
	    return 1;
	int ret = 0;
	if(c1<c2)
	    ret += doit(obs,r1,r2,c1+1,c2);
	if(r1<r2)
	    ret += doit(obs,r1+1,r2,c1,c2);
	return ret;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m=obstacleGrid.size();
	int n=obstacleGrid[0].size();
	return doit(obstacleGrid,0,m-1,0,n-1);
    }
};
