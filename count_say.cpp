#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
    vector<string> vs;
public:
    string countAndSay(int n) {
	string ret;

	if (vs.size()>=n && !vs[n-1].empty()) // saved
	    ret = vs[n-1];
	else {
	    if(n==1) // base case
		    ret = "1";
	    else {//recursion
		    string ret0 = countAndSay(n-1);
		    ostringstream oss;
		    for(int i=0,j;i<ret0.size();i=j) {
		        // make j the first one different
		        j=i+1;
		        while(j<ret0.size() && ret0[j]==ret0[i])
			        ++j;
		        // 		    
		        oss << (j-i) << ret0[i]; 
		    } 
		    ret = oss.str();
	    }
	
	    vs.push_back(ret);
	}

	return ret;
    }
};

int main() {
    Solution s;
//    for(int i=1;i<11;++i)
	cout << s.countAndSay(1) << endl;
	cout << s.countAndSay(2) << endl;
	cout << s.countAndSay(3) << endl;
	cout << s.countAndSay(4) << endl;
}
