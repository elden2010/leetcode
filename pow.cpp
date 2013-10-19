class Solution {
public:
    double pow(double x, int n) {
	if(n==0)
	    return 1;

	if(x==0)
	    return 0;

	bool neg2 = false;
	if(n<0) {
	    n = -n;
	    neg2 = true;
	}

	bool neg = false;
	if(x<0) {
	    x = -x;
	    if(n%2==1)
		neg = true;
	}  

	double ret = exp(n*log(x));
	if(neg)
	    ret = -ret;
	if(neg2)
	    ret = 1/ret;

	return ret;
        
    }
};
