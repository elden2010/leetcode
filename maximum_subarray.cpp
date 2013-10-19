/* O(n) solution */
class Solution {
public:
    int maxSubArray(int A[], int n) {
	int largest = A[0];
	int largest2 = A[0]; // largest ending at A[i]
	for(int i=1;i<n;++i) {
	    // update largest2
	    if(largest2<=0) // so that largest2+A[i]<=A[i]
		largest2 = A[i];
	    else
		largest2 += A[i];
	    //update largest
	    if(largest2>largest)
		largest = largest2;
	}
	return largest;
    }
};
