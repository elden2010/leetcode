class Solution {
public:
    int divide(int dividend, int divisor) {
	bool neg = false;

	if(dividend==0)
            return 0;
	else if(dividend>0 && divisor<0) {
	    neg = true;
	    divisor = -divisor;
	} else if(dividend<0 && divisor>0) {
	    neg = true;
	    dividend = -dividend;
	} else if(dividend<0 && divisor<0) {
	    dividend = -dividend;
	    divisor = -divisor;
	}
        long long ret = exp(log(dividend)-log(divisor));
	if(neg)
	    ret = -ret;

	return ret;
    }
};
