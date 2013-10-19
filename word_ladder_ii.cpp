/*
this passed the large test (with large dict)
instead of search all vertex for neighbors, just use 26*str.size()
BFS, with optimized graph construction, with large test example to read from word_ladder_in
*/

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

vector<vector<string> > findpath(unordered_map<string,vector<string> > &parent,string S,string D) {
    vector<vector<string> > ret;
    // base case
    if(S==D) {
	vector<string> row;
	row.push_back(S);
	ret.push_back(row);
	return ret;
    }

    // recursion
    vector<string> par = parent[D];
    for(size_t i=0;i<par.size();++i) {
	vector<vector<string> > reti = findpath(parent,S,par[i]);
	for(size_t j=0;j<reti.size();++j) {
	    reti[j].push_back(D);
	    ret.push_back(reti[j]);
	}
    }

    return ret;	
}

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
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
	vector<vector<string> > ret;

	// assuming start and end have equal length
	if(ndif(start,end)==1) {
	    vector<string> path;
	    path.push_back(start);
	    path.push_back(end);
	    ret.push_back(path);
	    return ret;
	}

        // get vertex list as unordered_set
	dict.insert(start);
	dict.insert(end);
	unordered_set<string> &V=dict;	
	int v = V.size();
	    

	// BFS from start, to search for end
        unordered_map<string,int> height; // height of BFS tree
	unordered_map<string,int> color;// color to indicate progress, -1: not discovered yet, 0:discovered, 1:finished
	unordered_map<string,vector<string> > parent;  
	for(unordered_set<string>::iterator it=V.begin();it!=V.end();++it)
	    color[*it] = -1;

	color[start] = 0;
	height[start] = 1;
	queue<string> Q;
	Q.push(start);
	while(!Q.empty()) {
	    // de-queue
	    string cur = Q.front();
	    Q.pop();

            // check if found
	    if(cur==end) {
/*		ret = height[cur];
		break;
*/	    }
	
	    // construct the neightbors
	    unordered_set<string> neighbors;
	    for(int j=0;j<cur.size();++j)
		for(int k=0;k<26;++k) {
		    string str = cur;
		    str[j] = letters[k];
		    if(str!=cur && V.count(str)>0)
			neighbors.insert(str);
		}

	    // work on neighbors
	    for(unordered_set<string>::iterator it=neighbors.begin();it!=neighbors.end();++it)
		if(color[*it]==-1) {
		    color[*it]=0;
		    height[*it]=height[cur]+1;
		    parent[*it].push_back(cur);
		    Q.push(*it);
		} else if(color[*it]==0) {
		    if(height[*it]==height[cur]+1)
			parent[*it].push_back(cur);
		}
	    color[cur] = 1;		    
	}

	
	ret = findpath(parent,start,end);
	return ret;
    }
};

vector<char> Solution::letters  = {'a','b','c','d','e','f','g',
                                   'h','i','j','k','l','m','n',
                                   'o','p','q','r','s','t',
				   'u','v','w','x','y','z'};

int main() {

    /*   Solution s;
    unordered_set<string> dict;
    dict.insert(string("hot"));
    dict.insert(string("cog"));
    dict.insert(string("dog"));
    dict.insert(string("tot"));
    dict.insert(string("hog"));
    dict.insert(string("hop"));
    dict.insert(string("pot"));
    dict.insert(string("dot"));
    vector<vector<string> > ret = s.findLadders("hot","dog",dict);
    */

/*    Solution s;
    unordered_set<string> dict;
    string s1,s2,s3;
    cin >> s1 >> s2;
    while(cin >> s3)
	dict.insert(s3);
    vector<vector<string> > ret = s.findLadders(s1,s2,dict);
*/

    Solution s;
    unordered_set<string> dict;
    dict.insert(string("hot"));
    dict.insert(string("dot"));
    dict.insert(string("dog"));
    dict.insert(string("lot"));
    dict.insert(string("log"));
    vector<vector<string> > ret = s.findLadders("hit","cog",dict);
    

    for(size_t i=0;i<ret.size();++i) {
	for(size_t j=0;j<ret[i].size();++j)
	    cout << ret[i][j] << " ";
	cout << endl;
    }
    

}
