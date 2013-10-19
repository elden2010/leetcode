class Solution {
public:
    int trap(int A[], int n) {
	vector<int> left(n,0),right(n,0);

	int max=0;
	for(int i=0;i<n;++i) {
	    left[i] = max;
	    if(max<A[i])
		max=A[i];
	}

	max = 0;
	for(int i=n-1;i>=0;--i) {
	    right[i] = max;
	    if(max<A[i])
		max=A[i];
	}

	vector<int> filled(n,0),dif(n,0);
	int ret = 0;
	for(int i=0;i<n;++i) {
	    filled[i] = min(left[i],right[i]);
	    dif[i] = filled[i]-A[i];
	    if(dif[i]>0)
		ret += dif[i];
	}

	return ret;
    }
};
