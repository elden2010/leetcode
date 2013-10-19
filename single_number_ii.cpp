#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>

using namespace std;

class Solution {
    static const int nbit = sizeof(int)*8;

public:

// too bad leetcode does not support bitset usage
/*
    vector<int> dec2bin(int dec) {
	// set as string
	bitset<nbit> bs(dec);
	ostringstream oss;
	oss << bs;
	string str = oss.str();
	// convert from string to int
	vector<int> ret(nbit,0); // LSB first
	for(int i=0;i<nbit;++i)
	    if(str[i]=='1')
		ret[nbit-1-i] = 1;
	return ret;
    }
*/
 
    // too bad the following function works for non-negative input only
/*    vector<int> dec2binv(unsigned int dec) {
	vector<int> ret(nbit,0);
	if(dec==0)
	    return ret;
	int cc = 0;
	while(dec>0) {
	    ret[cc++]  = dec & 1;
	    dec = dec >> 1;
	}
	return ret;
    }
*/

    // this works ok for both +/- ints
    vector<int> dec2bin(int dec) {
	vector<int> ret(nbit,0);
	if(dec==0)
	    return ret;
	int cc = 0;
	while(cc<nbit) {
	    int tmp = (dec & (1<<cc))!=0;
	    ret[cc]  = tmp;
	    cc++;
	}
	return ret;
    }

public:
    int singleNumber(int A[], int n) {
	// sum for each bit
	vector<int> sumBit(nbit,0);
	for(int i=0;i<n;++i) {
	    vector<int> tmp = dec2bin(A[i]);
	    for(int j=0;j<nbit;++j)
		sumBit[j] += tmp[j];
	}

	// sum % 3
	for(int j=0;j<nbit;++j)
	    sumBit[j] = sumBit[j] % 3;

	// binary to decimal
	int ret = 0;
	for(int j=0;j<nbit;++j)
	    if(sumBit[j])
		ret += 1 << j;
	return ret;
    }
};

int main() {
    Solution s;

    // just to test dec2bin 
    vector<int> ret = s.dec2bin(-2);
    for(vector<int>::reverse_iterator it=ret.rbegin();it!=ret.rend();++it)
	cout << *it;
    cout << endl;

    // test
    int A[] = {2,2,3,2,3,3,4,4,4,123456789,6,6,6,-4,-4,-4};
    cout << s.singleNumber(A,16) << endl;
}
