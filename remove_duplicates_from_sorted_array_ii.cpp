class Solution {
public:
    int removeDuplicates(int A[], int n) {
	int dst = 0, cur,curcount;
	for(int src=0;src<n;++src)
	    if(src==0) {
		cur = A[src];
		curcount = 1;
		dst ++;
	    } else
		if(cur!=A[src]) {
		    cur = A[src];
		    curcount = 1;
		    A[dst] = cur;
		    dst ++;
		} else 
		    if(curcount==1) {
			++ curcount;
			A[dst] = cur;
			dst ++;		
		    }

	return dst;
    }
};
