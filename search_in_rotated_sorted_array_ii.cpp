#include <iostream>

using namespace std;

class Solution {
private:
    int search0(int A[],int be,int en,int target) {
	if(A[be]==target)
	    return be;
	if(A[en]==target)
	    return en;
	if(en==be || en-be==1)
	    return -1;	 
	if(A[be]==A[en])  // duplicate removed
	    return search0(A,be+1,en-1,target);

	int mid = (be+en)/2;
	if(A[mid]==target)
	    return mid;
	
	if(A[be]<A[en]) { // a maybe non-strictly increasing array from be to en
	    if(A[mid]<target)
		if(A[en]>target)
		    return search0(A,mid,en,target);
		else
		    return -1;
	    else
		if(A[be]<target)
		    return search0(A,be,mid,target);
		else
		    return -1;
	} else {// a rotated sorted array
	    if(A[mid]==A[be])
		return search0(A,mid+1,en,target);
	    if(A[mid]==A[en])
		return search0(A,be,mid-1,target);

	    if(A[mid]>A[be]) // [be,mid] strictly increasing
		if(A[mid]>target && A[be]<target)
		    return search0(A,be,mid,target);
		else
		    return search0(A,mid,en,target);
	    else 
		if(A[mid]<A[en]) // [mid,en] strictly increasing
		    if(A[mid]<target && A[en]>target)
			return search0(A,mid,en,target);   
		    else
			return search0(A,be,mid,target);
/*		else { // 
	     	    cout << "debug impossible" << endl;
		    return 0;
		    }*/
	}
    }
    
public:
    bool search(int A[], int n, int target) {
	return search0(A,0,n-1,target)!=-1;
    }
};

int main() {
    int A[] = {3,1,1};
    Solution s;
    cout << s.search(A,3,2) << endl;

}
