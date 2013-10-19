/*
O(n^2) complexity, cannot pass large test
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
	int largest = 0;

	int n = height.size();
	for(int i=0;i<n;++i) {
	    // find out the left most index from which all >= height[i]
	    int left = i;
	    while(left>=0 && height[left]>=height[i])
		--left;
	    ++left;
            // find out the right most index from which all  >=height[i]
	    int right = i;
	    while(right<n && height[right]>=height[i])
		++right;
	    --right;
	    // 
	    int current = (right-left+1)*height[i];
	    if(current>largest)
		largest = current;
	}

	return largest;
    }
};
