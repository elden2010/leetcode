class Solution {
public:
    bool isPalindrome(string s) {
    string str;
	for(int i=0;i<s.size();++i)
	    if(isalnum(s[i]))
		str+=tolower(s[i]);

	bool ret = true;
	for(int i=0,j=str.size()-1;i<j;++i,--j)
	    if(str[i]!=str[j])
		ret = false;

	return ret;	               
    }
};
