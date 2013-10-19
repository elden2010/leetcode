/*
This is going to work (incomplete idea) but too clumpsy
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

public:
    string dec2bin(int v) {
	string ret;
	if(v==0)
	    ret = "0";
	else {
	    while(v>0) {
		int lastBit = v & 1;
		if(lastBit)
		    ret += "1";
		else
		    ret += "0";
		v = v >> 1;
	    }
	    reverse(ret.begin(),ret.end());
	}
	return ret;
    }

    int bin2dec(string str) {
	reverse(str.begin(),str.end());
	int ret = 0;
	for(int i=0;i<str.size();++i) {
	    int tmp = 1 << i;
	    if(str[i]=='1')
		ret += tmp;
	}
	return ret;
    }

    string divideBin(string d1,string d2) {
	string ret;
	int len1 = d1.size();
	int len2 = d2.size();
	for(int i=len2-1;i<=len1-1;++i) {
	    
	}
	return ret;
    }

    int divide2(int dividend, int divisor) {
	string d1 = dec2bin(dividend);
	string d2 = dec2bin(divisor);
	string ret0 = divideBin(d1,d2);
	int ret = bin2dec(ret0);
	return ret;
    }

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

	if(dividend<divisor)
	    ret = 0;
	else if(dividend==divisor)
	    ret = 1;
	else
	    ret = divide2(dividend,divisor);

	if(positive)
	    return ret;
	else
	    return -ret;
    }
};

int main() {
    Solution s;
    for(int i=0;i<20;++i) {
	string str = s.dec2bin(i);
	cout << str << endl;
	int ii = s.bin2dec(str);
	cout << ii << endl;
    }

}
