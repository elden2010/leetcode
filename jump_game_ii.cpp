class Solution {
public:
    int jump(int A[], int n) {
	vector<int> dp(n,0);

	for(int i=n-2;i>=0;--i) {
	    // check the following A[i] elements after the ith
	    if(A[i]==0)
		dp[i] = n; // sentinel, anything bigger than n-1 works
	    else {
		int minStep = n;
		for(int j=i+1;j<=i+A[i] && j<=n-1;++j)
		    if (dp[j]<minStep)
			minStep = dp[j];
		dp[i] = minStep + 1;
	    }		
	}

	return dp[0];

    }
};
