#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    
    bool dfs(vector<vector<char> > &board, 
             vector<vector<int> > &progress,
	     int ci, int cj,int m,int n,
	     string &word, int nmatch) {
	if(nmatch>=word.size())
	    return true;
	if(ci+1<m && progress[ci+1][cj]==0 && board[ci+1][cj]==word[nmatch]) {
	    progress[ci+1][cj] = 1;
	    if(dfs(board,progress,ci+1,cj,m,n,word,nmatch+1))
		return true;
	    else
		progress[ci+1][cj] = 0;

	}

	if(ci-1>=0 && progress[ci-1][cj]==0 && board[ci-1][cj]==word[nmatch]) {
	    progress[ci-1][cj] = 1;
	    if(dfs(board,progress,ci-1,cj,m,n,word,nmatch+1))
		return true;
	    else
		progress[ci-1][cj] = 0;
	}
	if(cj+1<n && progress[ci][cj+1]==0 && board[ci][cj+1]==word[nmatch]) {
	    progress[ci][cj+1] = 1;
	    if(dfs(board,progress,ci,cj+1,m,n,word,nmatch+1))
		return true;
	    else
		progress[ci][cj+1] = 0;
	}
	if(cj-1>=0 && progress[ci][cj-1]==0 && board[ci][cj-1]==word[nmatch]) {
	    progress[ci][cj-1] = 1;
	    if(dfs(board,progress,ci,cj-1,m,n,word,nmatch+1))
		return true;
	    else
		progress[ci][cj-1] = 0;
	}
	progress[ci][cj] = 1;
	return false;
    } 
public:
    bool exist(vector<vector<char> > &board, string word) {
	int m = board.size();
	int n = board[0].size();

	// new progress
	vector<vector<int> > progress;
	for(int i=0;i<m;++i) {
	    vector<int> row(n,0);
	    progress.push_back(row);
	}
	
	for(int i=0;i<m;++i)
	    for(int j=0;j<n;++j)
		if(board[i][j]==word[0]) {
		    // dfs with board[i][j] as source
		    progress[i][j] = 1;
		    if(dfs(board,progress,i,j,m,n,word,1))
			return true;
		    else
			progress[i][j] = 0;
		}

	return false;        
    }
};

int main() {
    Solution s;
    vector<vector<char> > board{{'A','B','C','E'},
	                        {'S','F','C','S'},
				{'A','D','E','E'} };
    cout << s.exist(board,"ADEESECC") << endl;

}
