#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
	if(x==0)
	    return 0;

/*	// find the smallest 2^(2*p)<=x<2^(2*p+2)
	int p=0;
        for(;x>(1<<(2*p));++p) {
	    unsigned long long int tmp = 1<<2*p;
	    cout << "p=" << p <<",tmp="<< tmp << endl;
	    cin.get();
	}

	int ub = 1<<p;
	int lb = 1<<(p-1);
*/

	unsigned int xx =x;
	unsigned int ub = 1<<16;
	unsigned int lb = 1;

	while(ub-lb>1) {
	    unsigned int mid = (ub+lb)/2;
	    if(mid*mid>xx)
		ub = mid;
	    else
		lb = mid;
	}

	if(ub*ub==xx)
	    return ub;
	else
	    return lb;
    }
};

int main() {
    Solution s;
    cout << s.sqrt(2147395599) << endl;
}
