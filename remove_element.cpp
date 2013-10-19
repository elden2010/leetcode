class Solution {
public:
    int removeElement(int A[], int n, int elem) {
	int i,j;
	for(i=0,j=n-1;i<=j;++i)
	    if(A[i]==elem) {
		while(j>i && A[j]==elem)
		    --j;
		if(j==i) {// not found anything differnt
		    break;
		} else { // found A[j] != elem
		    int tmp = A[i];
		    A[i] = A[j];
		    A[j] = elem;
		}
	    }

	return i;
    }
};

