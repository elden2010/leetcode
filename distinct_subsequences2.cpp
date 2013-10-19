/*
both v1 and v2 have the memory problem for the large test
coz:
I used double loop to multiply existing path with current choices
even if I just save one last node for each path, that multiplication is approximately exponential for long T
I ought to use DP as others do
*/

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

	vector<int> path; // just save the last node of each path
	for(int i=0;i<n;++i) {
            // find places in S that are T[i] 	    
	    vector<int> node;
	    for(int j=0;j<m;++j)
		if(S[j]==T[i])
		    node.push_back(j);

            //  
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
