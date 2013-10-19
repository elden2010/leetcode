/*
DFS incomplete, since I cannot figure out how to do DFS for backtracking
*/
#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

void print(const vector<vector<int> > & ind) {
    for(int i=0;i<ind.size();++i) {
	for(int j=0;j<ind[i].size();++j)
	    cout << ind[i][j];
	cout << endl;
    }
    cout << endl;
}
 
class Solution {
    void proceed(vector<vector<int> > &ind,pair<int,int> cur) {
	int n = ind.size();
	// just need to update the 4 lines to 0, meaning no choice
	// same row
	for(int j=0;j<n;++j)
	    ind[cur.first][j] = 0;
	// same column
	for(int i=0;i<n;++i)
	    ind[i][cur.second] = 0;
	// 45 degree line, below cur.first row
	for(int i=cur.first+1;i<n;++i) {
	    int col = cur.second-(i-cur.first);
	    if(col>=0)
		ind[i][col] = 0;
	}
	// 135 degree line, below cur.first row
	for(int i=cur.first+1;i<n;++i) {
	    int col =cur.second+(i-cur.first);
	    if(col<n)
		ind[i][col] = 0;
	}
        // itself
	ind[cur.first][cur.second] = 1;
    }
public:
    vector<vector<string> > solveNQueens(int n) {
	// DFS

	stack<pair<int,int> > st;
	for(int i=0;i<n;++i)
	    st.push(make_pair(0,i));
	
	// sols saves all possible solution layout
	// each row is a n-element choice
	vector<vector<int> > sols;
	// sol saves a single row for sols
	vector<int> sol;
	// indicator matrix to show available choices
	// initialize to all ones
	vector<int> tmp(n,1);
	vector<vector<int> > ind0(n,tmp), ind;

	while(!st.empty()) {
	    pair<int,int> cur = st.top();
	    st.pop();

	    // work on cur
	    if(cur.first==0) {//start a new tree
		sol.clear();
		ind = ind0;
	    }

	    // backup ind
//	    vector<vector<int> > oldind = ind; 



	    // save choice and update its influence
	    sol.push_back(cur.second); // just save column choice
	    proceed(ind,cur);
	    print(ind);

	    // find neighbors of cur
	    bool noneighbor = true;
	    for(int j=0;j<n;++j)
		if(ind[cur.first+1][j]==1) {
		    noneighbor = false;
		    break;
		}
	    if(noneighbor) {//restore old status
		sol.pop_back();
		ind = oldind;
		continue;
	    }

	    // if this tree ends
	    if(cur.first==n-1) {
		sols.push_back(sol);
		continue;
	    }
	    // valid neighbors
	    for(int j=0;j<n;++j)
		if(ind[cur.first+1][j]==1)
	       	    st.push(make_pair(cur.first+1,j));
	}

	return sols;
    }
};

int main() {
    Solution s;
    vector<vector<string> > ret = s.solveNQueens(6);

    for(int z=0;z<ret.size();++z) {
	for(int i=0;i<ret[z].size();++i)
	    cout << ret[z][i] << endl;
	cout << endl;
    }

}
