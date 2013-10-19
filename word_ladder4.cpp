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
	    // de-queue
	    string cur = Q.front();
	    Q.pop();

            // check if found
	    if(cur==end) {
		ret = height[cur];
		break;
	    }
	
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
    string s1,s2,s3;
    cin >> s1 >> s2;
    while(cin >> s3)
	dict.insert(s3);

    cout << s.ladderLength(s1,s2,dict) << endl;

}
