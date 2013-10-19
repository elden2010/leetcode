/* v1 cannot pass large test, so I got this v2 much simplier
but it cannot pass large test either
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<int> dp;

public:
    bool validPalindrome(string s) {
	int n=s.size();
	if(n<=1)
	    return true;
	for(int i=0,j=n-1;i<j;++i,--j)
	    if(s[i]!=s[j])
		return false;
	return true;
    }

    int minCut(string s) {
	// clear for each new input string s
	dp.clear();

	// if empty 
	if(s.empty())
	    return 0;
	dp.push_back(0); // base for bottom up dp
	
	// if at least one char: bottom up dp
	int n = s.size();
	unordered_map<char,vector<int>> charpos;
	for(int i=0;i<n;++i) { // size for current string in consideration
	    int reti = n;
	    charpos[s[i]].push_back(i);	    
	    vector<int> pos = charpos[s[i]];
	    for(int j=0;j<pos.size();++j) {
		string candid = s.substr(pos[j],i-pos[j]+1);
		if(validPalindrome(candid)) {
		    int old = dp[pos[j]];
		    if(reti>old+1)
			reti = old+1;
		}
	    }
	    dp.push_back(reti);
	}
	
	return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("elden") << endl;

    cout << s.minCut("abccbaddda") << endl;;

}
