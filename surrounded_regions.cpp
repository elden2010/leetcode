#include <vector>
#include <iostream>
#include <queue>
#include <stack>// here we can use either stack/queue

using namespace std;

class Solution {
    void checkNeighbor(int r,int c,int m,int n,const vector<vector<char> > &board,
		       vector<vector<int> > &visited, vector<pair<int,int> > &region,
		       bool &touchedBoundary, stack<pair<int,int> > &Q ) { // here we can use either stack/queue
	if(r>=0 && r<m && c>=0 && c<n && board[r][c]=='O' && visited[r][c]==-1) {
	    if(r==0 || r==m-1 || c==0 || c==n-1)
		touchedBoundary = true;
	    region.push_back(make_pair(r,c));
	    visited[r][c] = 0;
	    Q.push(make_pair(r,c));
	}
	return;
    }
public:
    void solve(vector<vector<char> > &board) {
	if(board.empty())
	    return;

	int m = board.size();
	int n = board[0].size();
    
	//
	vector<int> row(n,-1);
	vector<vector<int> > visited(m,row);

        for(int i=0;i<m;++i)
	    for(int j=0;j<n;++j)
		if(board[i][j]=='O' && visited[i][j]==-1) {
		    // found new 0, starting a region
		    vector<pair<int,int> > region;
		    region.push_back(make_pair(i,j));
		    bool touchedBoundary = false;
		    if(i==0 || i==m-1 || j==0 || j==n-1)
			touchedBoundary = true;

		    // BFS/DFS traversal with (i,j) as root
		    visited[i][j] = 0;
//		    queue<pair<int,int> > Q;
		    stack<pair<int,int> > Q;// here we can use either stack/queue
		    Q.push(make_pair(i,j));
		    
		    while(!Q.empty()) {
//			pair<int,int> P = Q.front();
			pair<int,int> P = Q.top();// here we can use either stack/queue
			Q.pop();
			
			// check the 4 possible neighbors
			checkNeighbor(P.first-1,P.second,m,n,board,visited,region,touchedBoundary,Q);
			checkNeighbor(P.first+1,P.second,m,n,board,visited,region,touchedBoundary,Q);
			checkNeighbor(P.first,P.second-1,m,n,board,visited,region,touchedBoundary,Q);
			checkNeighbor(P.first,P.second+1,m,n,board,visited,region,touchedBoundary,Q);

			visited[P.first][P.second] = 1;
		    }

		    // flip '0' to 'X' if the region does not touch boundary
		    if(!touchedBoundary)
			for(size_t z=0;z<region.size();++z)
			    board[region[z].first][region[z].second] = 'X';
		}
		    
    }
};

int main() {
/*    int n=5;
    vector<char> row(n,'X');
    vector<vector<char> > board(n,row);
    board[1][1] = '0';
    board[1][2] = '0';
    board[1][3] = '0';
    board[2][2] = '0';
    board[2][3] = '0';
    board[3][3] = '0';
    board[4][1] = '0';
*/
/*    int n=4;
    vector<char> row(n,'X');
    vector<vector<char> > board(n,row);
    board[0][1] = '0';
    board[1][0] = '0';
    board[1][2] = '0';
    board[2][1] = '0';
    board[2][3] = '0';
    board[3][0] = '0';
    board[3][2] = '0';
*/

    


    Solution s;
    string line;
    vector<vector<char> > board;
    while(getline(cin,line)) {
	board.clear();

	vector<int> inds;
	for(int i=0;i<line.size();++i)
	    if(line[i]=='"')
		inds.push_back(i);
	for(int i=0;i<inds.size();i=i+2) {
	    vector<char> row;
	    for(int j=inds[i]+1;j<inds[i+1];++j)
		row.push_back(line[j]);
	    board.push_back(row);
	}
	
	if(board.empty())
	    cout << "empty" << endl;
	else
	    cout << board.size() << " " << board[0].size()  << endl;
	

	cout << "before calling solve:" << endl;
	for(int i=0;i<board.size();++i) {
	    for(int j=0;j<board[0].size();++j)
		cout << board[i][j];
	    cout << endl;
	}

	s.solve(board);

	cout << "after calling solve:" << endl;
	for(int i=0;i<board.size();++i) {
	    for(int j=0;j<board[0].size();++j)
		cout << board[i][j];
	    cout << endl;
	}

	cout << endl;
	
    }
}
