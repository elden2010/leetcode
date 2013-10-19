/*
O(n) with in place copy
*/

class Solution {
public:
    int removeDuplicates(int A[], int n) {
	int dst = 0, cur;
	for(int src=0;src<n;++src)
	    if(src==0) {
		cur = A[src];
		dst ++;
	    } else
		if(cur!=A[src]) {
		    cur = A[src];
		    A[dst] = cur;
		    dst ++;
		}

	return dst;
    }
};
