class Solution {
    void sort2(int A[],int be,int en) {
	// find first non 0 from front
	while(A[be]==0)
	    be++;
	// find first non 2 from behind
	while(A[en]==2)
	    en--;
	// so now A[be]!=0 and A[en]!=2
	if(be>=en) // A[be]==A[en]==1
	    return;
	// at least 2 elements left
	if(A[be]==2) {
	    A[be] = A[en];
	    A[en] = 2;
	    sort2(A,be,en-1);
	} else // A[be]==1
	    if(A[en]==0) {
		A[en] = 1;
		A[be] = 0;
		sort2(A,be+1,en);
	    } else { // A[en]==1
		if(en-be==1) // two 1,1: that's it
		    return;
		// at least 1 more element between 1 and 1
		// find the first non 1
		int non1 = -1;
		for(int i=be+1;i<=en-1;++i)
		    if(A[i]!=1) {
			non1 = i;
			break;
		    }
		if(non1==-1) // did not find 0 or 2
		    return;
		else
		    if(A[non1]==0) {
			A[be]=0;
			A[non1] = 1;
			sort2(A,be+1,en);
		    } else {
			A[non1] = 1;
			A[en] = 2;
			sort2(A,be,en-1);
		    }
	    }
    }

public:
    void sortColors(int A[], int n) {
	sort2(A,0,n-1);
    }
};
