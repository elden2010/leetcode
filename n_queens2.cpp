/*
backtracking with recursion
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
    vector<vector<string> > locs;

    void addloc(const vector<vector<int> > &ind) {
	vector<string> row;
	for(int i=0;i<ind.size();++i) {
	    string str;
	    for(int j=0;j<ind[i].size();++j)
		if(ind[i][j])
		    str.push_back('Q');
		else
		    str.push_back('.');
	    row.push_back(str);
	}
	locs.push_back(row);
    }

    // update ind with cur fixed
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
    
    // check if we fix cur, could we still get valid solution
    bool isValid(vector<vector<int> > &ind,pair<int,int> cur) {	
	int n = ind.size();
	proceed(ind,cur);
//	print(ind);

	if(cur.first==n-1) {
	    addloc(ind);
	    return true;
	}

	// first make sure no all-0 rows exist
        // just need check rows below cur
	for(int i=cur.first+1;i<n;++i) {
	    bool allzero = true;
	    for(int j=0;j<n;++j)
		if(ind[i][j]==1) {
		    allzero = false;
		    break;
		}
	    if(allzero)
		return false;
	}
	// check each candidate for next step
	bool ret = false;
	for(int j=0;j<n;++j)
	    if(ind[cur.first+1][j]==1) { //possible candidate
		vector<vector<int> > ind2(ind);
		pair<int,int> next = make_pair(cur.first+1,j);
		bool ret2 = isValid(ind2,next);
		if(ret2 ) {
		    ret = ret || ret2;
		}		    
	    }

	return ret;
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
	locs.clear();

	vector<int> row(n,1);
	vector<vector<int> > ind(n,row);

	for(int j=0;j<n;++j) {
	    vector<vector<int> > ind2(ind);
	    pair<int,int> next = make_pair(0,j);
	    isValid(ind2,next);
	}

	return locs;
    }
};

int main() {
    Solution s;
    vector<vector<string> > ret = s.solveNQueens(5);

    for(int z=0;z<ret.size();++z) {
	for(int i=0;i<ret[z].size();++i)
	    cout << ret[z][i] << endl;
	cout << endl;
    }

}
