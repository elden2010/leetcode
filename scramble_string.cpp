class Solution {
public:
    bool isScramble(string s1, string s2) {
	// s1 s2 are the same length
	int n=s1.size();

	string s3(s1),s4(s2);
	sort(s3.begin(),s3.end());
	sort(s4.begin(),s4.end());
	if(s3!=s4)
	    return false;

        return true;
    }
};
