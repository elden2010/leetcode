/*key is to use long long to avoid things such as -2147483648, 2147483647 */
/*shift divisor to left (multiply by 2) enough to subtract*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
	long long ret = 0;
	long long div1 = dividend;
	long long div2 = divisor;

	bool neg = false;
	if((div1>0 && div2<0) || (div1<0 && div2>0))
	   neg = true;

	if(div1<0)
	    div1 = abs(div1);
	if(div2<0)
	    div2 = abs(div2);

	while(div1>=div2) {
	    // find the best t so that (divisor<<t) <= dividend and (divisor<<(t+1)) > dividend
	    unsigned int t = 0;
	    unsigned long long tdiv;
	    do {
		++t;
		tdiv = div2 << t;
	    } while(tdiv<=div1);
	    --t;
	    tdiv = div2 << t;

	    //cout << tdiv<< endl;

	    div1 -= tdiv;
	    ret += 1 << t;
	}

	if(neg)
	    ret = -ret;
	return ret;
        
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648,1) << endl;
}
