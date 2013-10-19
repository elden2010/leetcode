#include <iostream>
#include <vector>

using namespace std;

class Solution {

    vector<long> pows;

    unsigned long divide2(unsigned long dividend, unsigned long divisor) {
//	cout << dividend << endl;
//	cout << divisor << endl;

	unsigned long ret = 0;
	unsigned long residue = dividend;
	while(residue>=divisor) {
	    unsigned long exp = 0;
	    unsigned long d2 = divisor;
	    while(residue>=d2) {
		d2 = d2 << 1;
		exp++;
//		cout << "d2="<< d2  << ",residue="<< residue  << ",exp="<< exp << endl;
//		cin.get();
	    }
	    residue -= divisor << (exp-1);
	    ret += pows[exp-1];
	}
	return ret;
    }
    
public:
    Solution() {
	pows.resize(32);
	for(int i=0;i<=32;++i)
	    pows[i] = 1L << i;
    }

    int divide(int dividend, int divisor) {
	int ret = 0;
	bool positive = true;
	
	long d1=dividend, d2=divisor;
	
	if(dividend==0)
	    return ret;
	else if(d1>0 && d2<0) {
	    d1 = d1;
	    d2 = -d2;
	    positive = false;
	} else if(d1<0 && d2>0) {
	    d1 = -d1;
	    d2 = d2;
	    positive = false;
	} else if(d1<0 && d2<0) {
	    d1 = -d1;
	    d2 = -d2;
	} 

//	cout << "d1="<< d1  << ",d2="<< d2 << endl;	
	ret = divide2(d1,d2);
	
	if(positive)
	    return ret;
	else
	    return -ret;
    }
};

int main() {
    Solution s;
    cout << s.divide(-2147483648,1) << endl;
}
