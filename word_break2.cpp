/*
adding memorization
to process pathological data fast enough 
such as:
s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
dict = {"a","aa"}
*/
#include <map>
#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
    map<string,bool> ht;
    bool doit(string s,unordered_set<string> &dict) {
	if(ht.count(s))
	    return ht[s];

	if(dict.count(s)) {
	    ht[s] = true;
	    return true;
	}
	
	bool ret = false;
	int n = s.size();
	for(int i=1;i<n;++i)
	    if(dict.count(s.substr(0,i))==1 && doit(s.substr(i),dict)) {
		ret = true;
		break;
	    }

	ht[s] = ret;	
	return ret;
    }
public:
    bool wordBreak(string s,unordered_set<string> &dict) {
	ht.clear();

	return doit(s,dict);



			
    }
};

int main() {
    Solution sol;
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    unordered_set<string> dict{"a"};
    cout << sol.wordBreak(s,dict) << endl;
}
