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
    map<string,vector<string> > ht;
    vector<string> doit(string s,unordered_set<string> &dict) {
	if(ht.count(s))
	    return ht[s];

	vector<string> ret;
	// if s is contained in dict, it is added into results; but it may be decomposed further
	if(dict.count(s))
	    ret.push_back(s);
	
	int n = s.size();
	for(int i=1;i<n;++i) {
	    string prefix = s.substr(0,i);
	    if(dict.count(prefix)==1) {
		vector<string> ret2 = doit(s.substr(i),dict);
		if(!ret2.empty()) {
		    for(string str : ret2) {
			string tmp = prefix + " " + str;
			ret.push_back(tmp);
		    }		        
//		    break;
		}
	    }
	}
	ht[s] = ret;	
	return ret;
    }
public:
    vector<string> wordBreak(string s,unordered_set<string> &dict) {
	ht.clear();
	return doit(s,dict);
    }
};

int main() {
    Solution sol;
    string s = "aaaaa";
    unordered_set<string> dict{"a"};
    vector<string> ret = sol.wordBreak(s,dict);
    for(string str : ret) 
	cout << str << endl;
}
