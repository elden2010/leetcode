class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
	//
	int p1=m-1,p2=n-1,target=m+n-1;
	while(p1>=0 || p2>=0)
	    if(p1>=0 && p2>=0)
		// both array have elements left
		if(A[p1]>B[p2])
		    A[target--] = A[p1--];
		else
		    A[target--] =B[p2--];
	    else if(p1<0)
		// original A ends
		A[target--] = B[p2--];
	    else 
		// B ends
		A[target--] = A[p1--];
        
	return;
    }
};
