/*
another double loop, not really dp
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
	if(height.empty())
	    return 0;
	int n = height.size();
	vector<int> dp1(n,0);

	// dp1 for max rec ending at i
	for(int i=0;i<n;++i) {
	    int minh = height[i];
	    int maxrec = 0;
	    for(int j=i;j>=0;--j) {
		if(minh>height[j])
		    minh=height[j];
		if(maxrec<minh*(i-j+1))
		    maxrec=minh*(i-j+1);
	    }
	    dp1[i] = maxrec;
	}
	   
	// 
	int ret = dp1[0];
	for(int i=1;i<n;++i)
	    if(ret<dp1[i])
		ret=dp1[i];
	return ret;
    }
};
