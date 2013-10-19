class Solution {

    void reverse(vector<int> &num,int be,int en) {
	for(int i=be,j=en;i<j;i++,j--) {
	    int tmp=num[i];
	    num[i]=num[j];
	    num[j]=tmp;
	}
    }

    void nextPermutation(vector<int> &num) {
	int n=num.size();

	// find the last element smaller than its right neightbor
	int left = -1;
	for(int i=0;i<n-1;++i)
	    if(num[i]<num[i+1])
		left = i;

	// if found none, reverse the entire array
	if(left==-1)
	    reverse(num,0,n-1);
	else {
	    // find the last element in the right bigger than num[left] 
	    int right;
	    for(int i=left+1;i<n;++i)
		if(num[i]>num[left])
		    right = i;

	    // swap left and right
	    int tmp = num[left];
	    num[left] = num[right];
	    num[right] = tmp;

	    // reverse those between left+1 and n-1
	    if(left+1<n-1)
		reverse(num,left+1,n-1);
	}
    }

    char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};

public:
    string getPermutation(int n, int k) {
	vector<int> ret0(n,0);
	for(int i=0;i<n;++i)
	    ret0[i] = i+1;

	while(k>1) {
	    nextPermutation(ret0);
	    k--;
	}
	    
	string ret;
	for(int i=0;i<n;++i)
	    ret.push_back(digits[ret0[i]]);

	return ret;
    }
};
