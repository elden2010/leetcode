#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // return any ind where A[ind]=target
    int search(int A[],int target,int be,int en) {
	int mid = (be+en)/2;
	if(A[mid]==target)
	    return mid;

	if(be>=en)
	    return -1;

	int ret;
	if(A[mid]>target)
	    ret = search(A,target,be,mid-1);
	else
	    ret = search(A,target,mid+1,en);


    }

public:
    vector<int> searchRange(int A[], int n, int target) {
	vector<int> ret(2,-1);

	// find one index
	int ret0 = search(A,target,0,n-1);
	if(ret0==-1) // failed
	    return ret;

	// extend to both direction
	int be;
	for(int i=ret0;i>=0;i--)
	    if(A[i]==target)
		be = i;
	int en;
	for(int i=ret0;i<n;i++)
	    if(A[i]==target)
		en = i;
	ret[0] = be;
	ret[1] = en;
	return ret;
    }
};

int main() {
    int A[] = {2,2};
    Solution s;
    vector<int> ret = s.searchRange(A,2,1);
    cout << "["<<ret[0] <<","<<ret[1]<<"]" << endl;

}
