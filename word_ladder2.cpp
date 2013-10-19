/*
BFS, can only pass small test, as I used pair wise distance calculation to build adjacency list
*/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
    static vector<char> letters;

    size_t ndif(const string &s1,const string &s2) {
	// assuming s1, s2 have equal size
	size_t ret = 0;	
	for(size_t i=0;i<s1.size();++i)
	    if(s1[i]!=s2[i])
		++ret;
	return ret;
    }
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
	// assuming start and end have equal length
	vector<int> rets;
	size_t n = start.size();
	if(ndif(start,end)==1)
	    return 2;

	int ret=0;

        // get vertex list
	vector<string> V;
	V.push_back(start);
	for(unordered_set<string>::iterator it=dict.begin();
	    it!=dict.end();
	    ++it)
	    V.push_back(*it);
	V.push_back(end);
	int vs = V.size();

	// construct graph as adjacency list
	vector<vector<int> > vvi;
	vector<int> vi;
	for(int i=0;i<vs;++i)
	    vvi.push_back(vi);
	for(int i=0;i<vs;++i)
	    for(int j=i+1;j<vs;++j)
		if(ndif(V[i],V[j])==1) {
		    vvi[i].push_back(j);
		    vvi[j].push_back(i);
		}

	// BFS from start node 0, to search for node vs-1
        vector<int> height(vs,0); // height of BFS tree
	vector<int> color(vs,-1);// color to indicate progress, -1: not discovered yet, 0:discovered, 1:finished
	color[0] = 0;
	height[0] = 1;
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()) {
	    int cur = Q.front();
	    Q.pop();

	    if(cur==vs-1) {
		ret = height[cur];
		break;
	    }
		
	    vector<int> neighbors = vvi[cur];
	    for(vector<int>::iterator it=neighbors.begin();
		it!=neighbors.end();
		++it)
		if(color[*it]==-1) {
		    color[*it]=0;
		    height[*it]=height[cur]+1;
		    Q.push(*it);
		}
	    color[cur] = 1;		    
	}
	
	return ret;
    }
};

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
