#include <iostream>

using namespace std;

class Solution {
    int search(int A[],int be,int en,int target) {
	if(target<A[be])
	    return be;
	else if(target==A[be])
	    return be;
	else if(A[en]==target)
	    return en;
	else if(A[en]<target)
	    return en+1;
	else {// A[be]<target<A[en]
	    int mid = (be+en)/2;
	    if(A[mid]==target)
		return mid;
	    else if(A[mid]<target)
		return search(A,mid+1,en,target);
	    else
		return search(A,be,mid-1,target);
	}
    }
public:
    int searchInsert(int A[], int n, int target) {
	return search(A,0,n-1,target);
    }
};

int main() {

    Solution s;
    int A[] = {1,3,5,6};

    cout << s.searchInsert(A,4,0) << endl;
}
