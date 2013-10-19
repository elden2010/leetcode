#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
	if(matrix.empty())
	    return 0;

        int m=matrix.size();
	int n=matrix[0].size();

	vector<int> row(n,0);
	vector<vector<int>> dp1(m,row),dp2(m,row),dp3(m,row),dp4(m,row);
	
	// dp1 for longest consecutive 1's for the row so far, ending at (i,j)
	for(int i=0;i<m;++i)
	    for(int j=0;j<n;++j)
		if(j==0)
		    if(matrix[i][j]=='1')
			dp1[i][j] = 1;
		    else
			dp1[i][j] = 0;
		else		    
		    if(matrix[i][j]=='1')
			dp1[i][j] = dp1[i][j-1] + 1;
		    else
			dp1[i][j] = 0;

	// dp2 for longest consecutive 1's for the column so far, ending at (i,j)
	for(int i=0;i<m;++i)
	    for(int j=0;j<n;++j)
		if(i==0)
		    if(matrix[i][j]=='1')
			dp2[i][j] = 1;
		    else
			dp2[i][j] = 0;
		else		    
		    if(matrix[i][j]=='1')
			dp2[i][j] = dp2[i-1][j] + 1;
		    else
			dp2[i][j] = 0;

        // dp3 for largest rectangle of 1s ending at (i,j)
/*	for(int i=0;i<m;++i)
	    dp3[i][0] = dp2[i][0];
	for(int j=0;j<n;++j)
	    dp3[0][j] = dp1[0][j];
*/
	for(int i=0;i<m;++i)
	    for(int j=0;j<n;++j) {
		int maxret = 0;      // something too small for possible values
		int minheight = m+1; // something too big for possible values
		// check dp1[i][j] numbers from dp2[i][j],dp2[i][j-1],dp2[i][j-2]...
		for(int k=0;k<dp1[i][j];++k) {
		    if(minheight>dp2[i][j-k])
			minheight = dp2[i][j-k];
		    if(maxret<minheight*(k+1))
			maxret=minheight*(k+1);
		}
		dp3[i][j] = maxret;
	    }

	// dp4 for largest rectangle so far, not necessarily ending at [i][j]
	dp4[0][0]=dp3[0][0];
	for(int i=1;i<m;++i)
	    dp4[i][0] = max(dp3[i][0],dp4[i-1][0]);
	for(int j=1;j<n;++j)
	    dp4[0][j] = max(dp3[0][j],dp4[0][j-1]);
	for(int i=1;i<m;++i)
	    for(int j=1;j<n;++j)
		dp4[i][j] = max(dp3[i][j],max(dp4[i-1][j],dp4[i][j-1]));

	return dp4[m-1][n-1];
    }
};

int main() {
    vector<vector<char>> mat{{'1','1'}};
    Solution s;
    cout << s.maximalRectangle(mat) << endl;
}
