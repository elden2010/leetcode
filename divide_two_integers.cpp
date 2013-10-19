class Solution {
public:
    int divide(int dividend, int divisor) {
	int ret = 0;
	bool positive = true;

	if(dividend==0)
	    return ret;
	else if(dividend>0 && divisor<0) {
	    divisor = -divisor;
	    positive = false;
	} else if(dividend<0 && divisor>0) {
	    dividend = -dividend;
	    positive = false;
	} else if(dividend<0 && divisor<0) {
	    divisor = -divisor;
	    dividend = -dividend;
	} 

	if(divisor==1)
	    ret = dividend;
	else
	    while(dividend > divisor) {
		dividend -= divisor;
		ret ++;
	    }

	if(positive)
	    return ret;
	else
	    return -ret;
    }
};
