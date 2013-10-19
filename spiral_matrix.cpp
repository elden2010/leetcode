#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
	vector<int> ret;
	if(matrix.empty())
	    return ret;

	int m = matrix.size();
	int n = matrix[0].size();

	vector<int> row(n,0);
	vector<vector<int> > progress(m,row);

	int cc = 0;
	int i=0,j=0;
	char dir='e';
	while(cc<m*n) {
	    progress[i][j]=1;
	    ret.push_back(matrix[i][j]);
	    switch(dir) {
	    case 'e':
		if(j+1<n && progress[i][j+1]==0)
		    ++j;
		else {
		    ++i;
		    dir = 's';
		}
		break;
	    case 's':
		if(i+1<m && progress[i+1][j]==0)
		    ++i;
		else {
		    --j;
		    dir='w';
		}
		break;
	    case 'w':
		if(j-1>=0 && progress[i][j-1]==0)
		    --j;
		else {
		    --i;
		    dir='n';
		}
		break;
	    case 'n':
		if(i-1>=0 && progress[i-1][j]==0)
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
    vector<vector<int>> mat{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<int> ret = s.spiralOrder(mat);

    for(int i=0;i<ret.size();++i)
	cout << ret[i] << ",";
    cout << endl;
}
