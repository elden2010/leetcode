class Solution {
public:
    bool canJump(int A[], int n) {
	int rb = 0+A[0];
	for(int i=1; i<n && i<=rb; ++i) {
	    if(i+A[i]>rb)
		rb = i+A[i];
	}
	if(rb>=n-1)
	    return true;
	else
	    return false;
    }
};
