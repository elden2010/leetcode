#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int numDistinct(string S, string T) {
	int m=S.size();
	int n=T.size();
	if(m<n)
	    return 0;

	unordered_set<char> Tchar(T.begin(),T.end());
	unordered_map<char,vector<int> > pos;
	for(int i=0;i<m;++i)
	    if(Tchar.count(S[i])>0)
		pos[S[i]].push_back(i);

	vector<int> path; // just save the last node of each path
	for(int i=0;i<n;++i) {
	    vector<int> node = pos[T[i]];
	    if(path.empty())
		// each of node as start of a new path
		for(int j=0;j<node.size();++j)
		    path.push_back(node[j]);
	    else {
		vector<int> newpath;
		// check if any node can extend any existing path
		for(int k=0;k<path.size();++k)
		    for(int j=0;j<node.size();++j)
			if(path[k] < node[j])
			    newpath.push_back(node[j]);
		path = newpath;
	    }
	}
	
	return path.size();
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("eee","eee") << endl;
}
