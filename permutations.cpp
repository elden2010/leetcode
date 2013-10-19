class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int> > ret;
	if(num.empty())
	    return ret;
	if(num.size()==1) {
	    ret.push_back(num)
	    return ret;
	}
	// recursion
	vector<int> num0(num.begin(),num.end()-1);
	vector<vector<int> > ret0 = permute(num0);

	//
	int n = num.size();
	int last = num[n-1];
	for(int i=0;i<ret0.size();++i)
	    for(int j=0;j<n;++j) {
		vector<int> row = ret0[i];
		row.insert(row.begin()+j,last);
		ret.push_back(row);
	    }
	    
	return ret;

    }

};
