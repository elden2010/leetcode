#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
    bool valid(string str) {
	if(str.size()>1 && str[0]=='0')
	    return false;
	istringstream iss(str);
	int num;
	iss >> num;
	if(num>=0 && num<=255)
	    return true;
	else
	    return false;
    }

    vector<string> work(const string &s,int be,int nip) {
	int n=s.size();
	vector<string> ret;
	// too short or too long as nip pieces of IP
	if(n-be<nip || n-be>nip*3)
	    return ret;
	// base case
	if(nip==1) {
	    string str = s.substr(be);
	    if(valid(str))
		ret.push_back(str);
	    return ret;
	}

	// 1st piece of IP is single digit
	for(int i=1;i<=3;++i) {	    
	    vector<string> ret123 = work(s,be+i,nip-1);
	    for(int j=0;j<ret123.size();++j) {
		string str = s.substr(be,i);
		if(valid(str)) {
		    str += "." + ret123[j];
		    ret.push_back(str);
		}
	    }
	}
	
	return ret;
    }
public:
    vector<string> restoreIpAddresses(string s) {
	return work(s,0,4);
    }
};

int main() {
    Solution s;
    vector<string> ret = s.restoreIpAddresses("25525511135");
    for(int i=0;i<ret.size();++i)
	cout << ret[i] << endl;
}
