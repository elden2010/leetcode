/*
kind of dp to pass the large test
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> dp;
    int doit(string &s,int be,int en) {
       
	if(be==en)
	    return 0;

	if(dp[be]!=-1)
	    return dp[be];

	if(s[be]=='0') {
	    dp[be] = 0;
	    return 0;
	}
	
	int n=en-be;
	if(n==1) {
	    dp[be] = 1;
	    return 1;
	}

	if(n==2)
	    if(s[be+1]=='0')
		if(s[be]=='1' || s[be]=='2') {
		    dp[be] = 1;
		    return 1;  // 10,20
		} else {
		    dp[be] = 0;
		    return 0;  // 30,40,..90
		}
	    else
		if( (s[be]=='1') || 
		    (s[be]=='2' && s[be+1]!='7' && s[be+1]!='8' && s[be+1]!='9') ) {
		    dp[be] = 2;
		    return 2;
		} else {
		    dp[be] = 1;
		    return 1;
		}

	int ret = 0;
	
	// just break the first and the rest
	ret += doit(s,be+1,en);
	

	// break the first,second and the rest, if starting with 11-19,21-26
	if( (s[be]=='1') || 
            (s[be]=='2' && s[be+1]!='7' && s[be+1]!='8' && s[be+1]!='9') )
	    ret += doit(s,be+2,en); // 10-26

	dp[be] = ret;
     
	return ret;
    }
public:
    int numDecodings(string s) {
	dp.clear();
	dp.resize(s.size(),-1);
	return doit(s,0,s.size());
    }
};

int main() {
    Solution s;

    cout << s.numDecodings("12") <<endl;
    cout << s.numDecodings("110") <<endl;
}
