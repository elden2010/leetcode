#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
    int checkme(long ilb,long iub,long jlb,long jub) {
	// three results: i move right, move left, or stay there (meaning i,j fits each other)
	int ret;
	if(iub<jlb)
	    ret=1;
	else if(jub<ilb)
	    ret=-1;
	else // there is overlap
	    ret=0;
	return ret;
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {

	if(m==0)
	    return n%2==1?B[(n-1)/2]:(B[n/2]+B[n/2-1])/2.0;
	if(n==0)
	    return m%2==1?A[(m-1)/2]:(A[m/2]+A[m/2-1])/2.0;

	/* A has 2m+1 locations (including m elements and the m+1 spaces between elements): 0,1,...2m
	   similarly, B has 2n+1 locations: 0,1,...2n
	   the median must be at m, n respectively 
	   we use i or j to represent such location index, moving from m,n
	   note when it is even, it means the location between two real elements i/2-1 and i/2, except at two ends
                           odd,               element (i-1)/2
	 */
	int i=m,j=n;
	long ilb = i%2==1?A[(i-1)/2]:A[i/2-1];
	long iub = i%2==1?A[(i-1)/2]:A[i/2];
	long jlb = j%2==1?B[(j-1)/2]:B[j/2-1];
	long jub = j%2==1?B[(j-1)/2]:B[j/2];

	int idir = checkme(ilb,iub,jlb,jub);
	int step = m<n?m:n;
	while(idir!=0 && step>=1) {
	    i += idir*step;
	    j -= idir*step;
	    
	    if(i==0) {
		ilb = numeric_limits<long>::min();
		iub = A[0];
	    } else if(i==2*m) {
		ilb = A[m-1];
		iub = numeric_limits<long>::max();
	    } else {
		ilb = i%2==1?A[(i-1)/2]:A[i/2-1];
		iub = i%2==1?A[(i-1)/2]:A[i/2];
	    }

	    if(j==0) {
		jlb = numeric_limits<long>::min();
		jub = B[0];
	    } else if(j==2*n) {
		jlb = B[n-1];
		jub = numeric_limits<long>::max();
	    } else {
		jlb = j%2==1?B[(j-1)/2]:B[j/2-1];
		jub = j%2==1?B[(j-1)/2]:B[j/2];
	    }

	    idir = checkme(ilb,iub,jlb,jub);
	    if(step>1)
		step /= 2;
	    
	}
	
	// grab the overlap between [ilb,iub] and [jlb,jub], or just the gap between
	vector<long> vec4(4,0);
	vec4[0] = ilb;
	vec4[1] = iub;
	vec4[2] = jlb;
	vec4[3] = jub;
	sort(vec4.begin(),vec4.end());
	
	double ret = (vec4[1]+vec4[2])/2.0;
	return ret;
        
    }
};

int main() {
    int A[] = {3,4,5,6,7};
    int B[] = {1,2,8,9,10};

    Solution s;
    double ret = s.findMedianSortedArrays(A,5,B,5);
    cout << ret << endl;

}
