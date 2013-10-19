/*
gonna be a graph problem, which I have no idea yet
I cannot simply use recursion as it meets circles which crash the recursion
*/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

class Solution {
    static vector<char> letters;
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
	// assuming start and end have equal length
	vector<int> rets;
	int n = start.size();
	int ndif = 0;
	for(int i=0;i<n;++i)
	    if(start[i]!=end[i])
		++ndif;
	if(ndif==1)
	    return 2;

	// 
	for(int i=0;i<n;++i)
	    for(int j=0;j<26;++j) {
		string intermediate(start);
		intermediate[i] = letters[j];
		if(intermediate!=start && dict.count(intermediate)>0) {
		    int tRet = ladderLength(intermediate,end,dict);
		    if(tRet!=0)
			rets.push_back(1+tRet);
		}
	    }

	int ret=0;
	for(int i=0;i<rets.size();++i)
	    if(ret==0)
		ret = rets[i];
	    else
		if(ret>rets[i])
		    ret=rets[i];
	
	return ret;
    }
};

vector<char> Solution::letters  = {'a','b','c','d','e','f','g',
                                   'h','i','j','k','l','m','n',
                                   'o','p','q','r','s','t',
				   'u','v','w','x','y','z'};


int main() {
    Solution s;
    unordered_set<string> dict;
    dict.insert(string("hot"));
    dict.insert(string("cog"));
    dict.insert(string("dog"));
    dict.insert(string("tot"));
    dict.insert(string("hog"));
    dict.insert(string("hop"));
    dict.insert(string("pot"));
    dict.insert(string("dot"));

    cout << s.ladderLength(string("hot"),string("dog"),dict) << endl;

}
