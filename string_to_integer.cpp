/*
1. what to do if invalid input? 
a. if overflow, get the maximum in the side
b. if invalid, stop at valid edge
c. trim blanks at both ends
d. + is valid
f. otherwise, invalid string got 0

2. int [-2^32,2^32-1]
*/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
	long long ret = 0; // at first I thought long is OK, but it is only OK for certain compilers such as mine
	string s1(str);

	// 1. trim blanks at ends
	int first;
	for(first=0;first<s1.size();++first)
	    if(s1[first]!=0x20)
		break;
	int last;
	for(last=s1.size()-1;last>=0;--last)
	    if(s1[last]!=0x20)
		break;
	string s2 = s1.substr(first,last-first+1);
//	cout << s2 << endl;

	// 2. got sign if any
	bool negative = false;
	string s3;
	if(s2[0]=='+')
	    s3 = s2.substr(1,s2.size()-1);
	else if(s2[0]=='-') {
	    s3 = s2.substr(1,s2.size()-1);
	    negative = true;
	} else
	    s3 = s2;

	// 4. all chars are now numeric, at least for the valid parts
	for(int i=0;i<s3.size();++i)
	    if(isdigit(s3[i]))
		ret = 10*ret + s3[i] - 0x30;
	    else
		break;

	// 5.
	int ret2;
	int intmax = numeric_limits<int>::max();
	int intmin = numeric_limits<int>::min();
	if(!negative)
	    if(ret>intmax)
		ret2 = intmax;
	    else
		ret2 = ret;
	else
	    if(-ret<intmin)
		ret2 = intmin;
	    else
		ret2 = -ret;

	return ret2;
    }
};

int main() {
    Solution s;
    cout << s.atoi("2147483648") << endl;
    cout << s.atoi("       -10441643317j") << endl;
}
