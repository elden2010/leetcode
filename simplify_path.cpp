#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
	string s1;
	// remove repeating /
	bool firstslash = true;
	for(int i=0;i<path.size();++i)
	    if(path[i]=='/')
		if(firstslash) {
		    firstslash = false;
		    s1.push_back('/');
		} else
		    continue;
	    else {
		firstslash = true;
		s1.push_back(path[i]);
	    }	    
	    
	// remove ending /
	string s2;
	if(s1.back()=='/')
	    s2 = s1.substr(0,s1.size()-1);
	else
	    s2 = s1;

	// determine each / block
	vector<int> inds;
	for(int i=0;i<s2.size();++i)
	    if(s2[i]=='/')
		inds.push_back(i);

	// save each block
	vector<string> blocks; 
	for(int i=0;i<inds.size();++i)
	    if(i!=inds.size()-1)
		blocks.push_back(s2.substr(inds[i]+1,inds[i+1]-inds[i]-1));
	    else
		blocks.push_back(s2.substr(inds[i]+1));

        // act on each block: remove .; remove .. and the one before it
	vector<string> blocks2;
	for(int i=0;i<blocks.size();++i)
	    if(blocks[i]==".")
		continue;
	    else if(blocks[i] == "..")
		if(!blocks2.empty())
		    blocks2.pop_back();
		else
		    continue;
	    else
		blocks2.push_back(blocks[i]);

	string ret;
	for(int i=0;i<blocks2.size();++i)
	    ret += "/" + blocks2[i];
	if(ret.empty())
	    ret = "/";

	return ret;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("/home//foo") << endl;

}
