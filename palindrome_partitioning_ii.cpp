#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<vector<vector<string>>> dp;

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

	vector<vector<string>> ret0;

	// if empty 
	if(s.empty())
	    return ret0;
	dp.push_back(ret0); // base for bottom up dp
	
	// if at least one char: bottom up dp
	int n = s.size();
	unordered_map<char,vector<int>> charpos;
	for(int i=0;i<n;++i) { // size for current string in consideration
	    vector<vector<string>> reti; // ret1..retn
	    charpos[s[i]].push_back(i);	    
	    vector<int> pos = charpos[s[i]];
	    for(int j=0;j<pos.size();++j) {
		string candid = s.substr(pos[j],i-pos[j]+1);
		if(validPalindrome(candid)) {
		    vector<vector<string>> old = dp[pos[j]];
		    if(old.empty()) {
			vector<string> tmp(1,candid);
			old.push_back(tmp);
			reti.push_back(old[0]);
		    } else 
			for(int k=0;k<old.size();++k) {
			    old[k].push_back(candid);
			    reti.push_back(old[k]);
			}
		}
	    }
	    dp.push_back(reti);
	}
	
        vector<vector<string>> ret = dp[n];
	int minsz = n;
	for(int i=0;i<ret.size();++i)
	    if(minsz>ret[i].size())
		minsz = ret[i].size();
	return minsz-1;
    }
};

int main() {
    Solution s;
    cout << s.validPalindrome("elden") << endl;

    vector<vector<string>> ret = s.partition("abccbaddda");
    for(int i=0;i<ret.size();++i) {
	cout << "(";
	for(int j=0;j<ret[i].size();++j)
	    if(j==0)
		cout << ret[i][j];
	    else
		cout << "," << ret[i][j];
	cout << "),";
    }
    cout << endl;
}
