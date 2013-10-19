#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
	if(x<0)
	    return false;
	if(x<10)
	    return true;

	int x2=x; 
	int ndigit = 0;
	while(x2>0) {
	    ndigit++;
	    x2 = x2 /10;
	}
//	cout << "ndigit=" << ndigit << endl;

	int mid = (ndigit+1)/2; // counting from 1 actually
	int midvalue = 0;

	unsigned int ret = 0;
	int cc = 0;
	while(x>0) {
	    cc++;
	    if(cc==1)
		ret = x%10;
	    else {
		int digit = x%10;
		if(ndigit%2 && cc==mid)
		    midvalue = digit;
		ret = ret ^ digit;
	    }
	    x = x /10;
	}
	cout << "ret" << ret << endl;
	cout << "midvalue" << midvalue << endl;
	
	ret = ret ^ midvalue;
	if(ret==0)
	    return true;
	else
	    return false;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(5) << endl;
}
