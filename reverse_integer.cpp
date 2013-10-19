class Solution {
public:
    int reverse(int x) {
	vector<int> xx;

	bool flag=false;
	if(x<0) {
	    flag=true;
	    x=-x;
	}
	
	int i=1;
	do {
	    int digit = x / i % 10;
	    xx.push_back(digit);
	    i *= 10;
	} while(x >=i);

	for(i=0;i<xx.size();++i)
	    if(xx[i]!=0)
		break;

	int ret = 0;
	int multi = 1;
	for(int j=xx.size()-1;j>=i;--j) {
	    ret += xx[j]*multi;
	    multi *= 10;
	}

	if(flag)
	    ret = -ret;

        return ret;
    }
};
