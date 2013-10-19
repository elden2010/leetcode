class Solution {
    void transpose(vector<vector<int> > &matrix) {
	for(int i=0;i<matrix.size();++i)
	    for(int j=i+1;j<matrix[0].size();++j) {
		int tmp = matrix[i][j];
		matrix[i][j] = matrix[j][i];
		matrix[j][i] = tmp;
	    }
    }

    void flipud(vector<vector<int> > &matrix) {
	int m = matrix.size();
	for(int i=0;i<m/2;++i)
	    for(int j=0;j<matrix[0].size();++j) {
		int tmp = matrix[i][j];
		matrix[i][j] = matrix[m-1-i][j];
		matrix[m-1-i][j] = tmp;
	    }
    }

public:
    void rotate(vector<vector<int> > &matrix) {
	flipud(matrix);
	transpose(matrix);
    }
};
