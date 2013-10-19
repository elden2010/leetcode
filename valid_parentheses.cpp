#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
	int n = s.size();
	if(n%2==1 || s[0]==')' || s[0]==']' || s[0]=='}' || s[n-1]=='(' || s[n-1]=='[' || s[n-1]=='{' )
	    return false;
	if(n==0)
	    return true;

	char target;
	if(s[0]=='(')
	    target = ')';
	else if(s[0]=='[')
	    target = ']';
	else
	    target = '}';

	vector<int> foundat;
	int i=1;
	for(;i<n;++i)
	    if(s[i]==target)
		foundat.push_back(i);

	if(foundat.empty())
	    return false;

	bool ret = false;
	for(int i=0;i<foundat.size();++i) {
	    int j=foundat[i];
	    string s1 = s.substr(1,j-1);
	    string s2 = s.substr(j+1);
	    if(isValid(s1) && isValid(s2)) {
		ret = true;
		break;
	    }
	}
	    
	return ret;
    }
};

int main() {
    Solution s;
    cout << s.isValid("[()[[]()]]") << endl;
}
