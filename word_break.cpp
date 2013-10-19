/*
this version cannot process pathological data fast enough 
such as:
s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
dict = {"a","aa"}
*/
class Solution {
public:
    bool wordBreak(string s,unordered_set<string> &dict) {
	if(dict.count(s))
	    return true;

	int n = s.size();
	for(int i=1;i<n;++i)
	    if(dict.count(s.substr(0,i))==1 && wordBreak(s.substr(i),dict))
		return true;

	return false;		
    }
};
