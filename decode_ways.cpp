/*
cannot pass large test
*/
#include <string>
#include <iostream>

using namespace std;

class Solution {
    int doit(string &s,int be,int en) {
	if(be==en)
	    return 0;

	if(s[be]=='0')
	    return 0;
	
	int n=en-be;
	if(n==1)
	    return 1;
	if(n==2)
	    if(s[be+1]=='0')
		if(s[be]=='1' || s[be]=='2')
		    return 1;  // 10,20
		else
		    return 0;  // 30,40,..90
	    else
		if( (s[be]=='1') || 
		    (s[be]=='2' && s[be+1]!='7' && s[be+1]!='8' && s[be+1]!='9') )
		    return 2;
		else
		    return 1;

	int ret = 0;
	
	// just break the first and the rest
	ret += doit(s,be+1,en);
	

	// break the first,second and the rest, if starting with 11-19,21-26
	if( (s[be]=='1') || 
            (s[be]=='2' && s[be+1]!='7' && s[be+1]!='8' && s[be+1]!='9') )
	    ret += doit(s,be+2,en); // 10-26
     
	return ret;
    }
public:
    int numDecodings(string s) {
	return doit(s,0,s.size());
    }
};

int main() {
    Solution s;
    cout << s.numDecodings("7543229674715396218368325364163294258826933764994151395727178546319844199963267855648577635487721483") <<endl;
}
