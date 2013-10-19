class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
	vector<int> best,oldbest;
	best.push_back(triangle[0][0]);
	oldbest = best;
	for(int i=1;i<triangle.size();++i) {
	    for(int j=0;j<i+1;++j) // at row i+1, i+1 elements
		if(j==0) // most left one
		    best[j] = oldbest[j] + triangle[i][j];
		else if(j<i) { // middle elements
		    int left = oldbest[j-1] + triangle[i][j];
		    int right = oldbest[j] + triangle[i][j];
		    best[j] = min(left,right);
		} else // most right one
		    best.push_back(oldbest[j-1] + triangle[i][j]);
	    oldbest = best;
	}
	int ret = best[0];
	for(int i=1;i<best.size();++i)
	    if(ret>best[i])
		ret = best[i];

        return ret;
    }
};
