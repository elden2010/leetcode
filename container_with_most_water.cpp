/*
O(n*n) complexity, cannot pass large test
thought for 1 hour, still no clue about faster way
*/
class Solution {
public:
    int maxArea(vector<int> &height) {
	int n = height.size();
	int ret = 0;
	for(int i=0;i<n-1;++i)
	    for(int j=i+1;j<n;++j) {
		int h = height[i]<height[j]?height[i]:height[j];
		int tArea = h*(j-i);
		if(ret<tArea)
		    ret = tArea;
	    }
	return ret;
		
    }
};
