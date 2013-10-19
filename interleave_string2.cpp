/*
this one just use recursion to do it, but still too slow to pass large test
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // helper function doing real work
    bool isItlv(string &s1,int z1,string &s2,int z2,string &s3,int z3) {
	// base cases
	if(z1>=s1.size())
	    return s2.substr(z2)==s3.substr(z3);
	if(z2>=s2.size())
	    return s1.substr(z1)==s3.substr(z3);

	// recursive
	bool ret;
	if(s3[z3]==s1[z1] && s3[z3]!=s2[z2])
	    ret = isItlv(s1,z1+1,s2,z2,s3,z3+1);
	else if(s3[z3]!=s1[z1] && s3[z3]==s2[z2])
	    ret = isItlv(s1,z1,s2,z2+1,s3,z3+1);
	else if(s3[z3]==s1[z1] && s3[z3]==s2[z2])
	    ret = isItlv(s1,z1+1,s2,z2,s3,z3+1) || isItlv(s1,z1,s2,z2+1,s3,z3+1);
	else
	    ret = false;

	return ret;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
	return isItlv(s1,0,s2,0,s3,0);
    }
};

int main() {
    Solution s;
    cout << s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") << endl;
}
