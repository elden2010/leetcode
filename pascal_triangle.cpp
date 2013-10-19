class Solution {
public:
    vector<vector<int> > generate(int numRows) {
	vector<vector<int> > ret;
	for(int i=0;i<numRows;++i) {
	    vector<int> row(i+1,1);
	    if(i==0)
		row[i] = 1;
	    else
		for(int j=1;j<i;++j)
		    row[j] = ret[i-1][j-1]+ret[i-1][j];
	    ret.push_back(row);
        }
	return ret;
    }
};
