#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {

	int ret = 0;
	int n = height.size();
	for(int i=0,j=n-1;i<j;) {
	    int area = (j-i)*min(height[i],height[j]);
	    if(ret<area)
		ret = area;
	    if(height[i]<height[j])
		++i;
	    else
		--j;
	}

	return ret;
		
    }
};

int main() {
    vector<int> vi{1,2,4,3};

    Solution s;
    cout << s.maxArea(vi) << endl;
}
