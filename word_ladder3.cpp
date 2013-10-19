/*
BFS, with optimized graph construction
still cannot pass large test, coz it finds neighbors for all vertex
while in word_ladder4.cpp, it only finds when necessary
*/

#include <vector>
#include <unordered_set>
#include <unordered_map>
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
	size_t n = start.size();
	if(ndif(start,end)==1)
	    return 2;

	int ret=0;

        // get vertex list as unordered_set
	dict.insert(start);
	dict.insert(end);
	unordered_set<string> &V=dict;	
	int v = V.size();

	// construct adjacency list as unordered_map
	unordered_map<string,unordered_set<string> > adj;
	for(unordered_set<string>::iterator it=V.begin();it!=V.end();++it) {
	    unordered_set<string> neighbors;
	    for(int j=0;j<(*it).size();++j)
		for(int k=0;k<26;++k) {
		    string str = *it;
		    str[j] = letters[k];
		    if(str!=*it && V.count(str)>0)
			neighbors.insert(str);
		}
	    adj[*it] = neighbors;		    
	}
	    

	// BFS from start, to search for end
        unordered_map<string,int> height; // height of BFS tree
	unordered_map<string,int> color;// color to indicate progress, -1: not discovered yet, 0:discovered, 1:finished
	for(unordered_set<string>::iterator it=V.begin();it!=V.end();++it)
	    color[*it] = -1;

	color[start] = 0;
	height[start] = 1;
	queue<string> Q;
	Q.push(start);
	while(!Q.empty()) {
	    string cur = Q.front();
	    Q.pop();

	    if(cur==end) {
		ret = height[cur];
		break;
	    }
		
	    unordered_set<string> neighbors = adj[cur];
	    for(unordered_set<string>::iterator it=neighbors.begin();it!=neighbors.end();++it)
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
