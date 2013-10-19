#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ret;
	if(n==0)
	    return ret;

	for(int i=0;i<n;++i) {
	    vector<int> row(n,0);
	    ret.push_back(row);
	}

	int cc = 0;
	int i=0,j=0;
	char dir='e';
	while(cc<n*n) {
	    ret[i][j] = cc+1;
	    switch(dir) {
	    case 'e':
		if(j+1<n && ret[i][j+1]==0)
		    ++j;
		else {
		    ++i;
		    dir = 's';
		}
		break;
	    case 's':
		if(i+1<n && ret[i+1][j]==0)
		    ++i;
		else {
		    --j;
		    dir='w';
		}
		break;
	    case 'w':
		if(j-1>=0 && ret[i][j-1]==0)
		    --j;
		else {
		    --i;
		    dir='n';
		}
		break;
	    case 'n':
		if(i-1>=0 && ret[i-1][j]==0)
		    --i;
		else {
		    ++j;
		    dir='e';
		}
		break;
	    }
	    ++cc;
	}

	return ret;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ret = s.generateMatrix(4);

    for(int i=0;i<ret.size();++i) {
	for(int j=0;j<ret[0].size();++j)
	    cout << ret[i][j] << ",";
	cout << endl;
    }
}
