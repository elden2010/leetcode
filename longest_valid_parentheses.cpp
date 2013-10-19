#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
	int n=s.size();
	vector<int> dp(n,0);

	for(int i=1;i<n;++i) {
	    if(s[i]=='(') // last element is (, no effect
		dp[i] = dp[i-1];
	    else { // last element is )
		//get the longest valid parenthese ending at i
		int sum = 0;
		int first0ind = -1;
		for(int j=i;j>=0;j--) {
		    if(s[j]==')')
			sum += -1;
		    else
			sum += 1;
		    if(sum>0)
			break;
		    else if(sum==0)
			first0ind = j;
		}
		// 
		if(first0ind==-1)
		    dp[i] = dp[i-1];
		else {
		    int newlongest = i-first0ind+1;
		    dp[i] = max(dp[i-1],newlongest);
		}
	    } 
	}

        return dp[n-1];
    }
};

int main() {
    Solution s;    
    cout << s.longestValidParentheses("(()))())(") << endl;
}
