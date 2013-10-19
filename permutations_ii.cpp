class Solution {
    set<vector<int> > doit(vector<int> &num) {
	set<vector<int> > ret;
	if(num.empty())
	    return ret;
	if(num.size()==1) {
	    ret.insert(num);
	    return ret;
	}
	// recursion
	vector<int> num0(num.begin(),num.end()-1);
	set<vector<int> > ret0 = doit(num0);

	//
	int n = num.size();
	int last = num[n-1];
	for(auto it=ret0.begin();it!=ret0.end();++it)
	    for(int j=0;j<n;++j) {
		vector<int> row = *it;
		row.insert(row.begin()+j,last);
		ret.insert(row);
	    }
	    
	return ret;
    }
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
	set<vector<int> > ret0 = doit(num);

	vector<vector<int> > ret;
	for(auto it=ret0.begin();it!=ret0.end();++it)
	    ret.push_back(*it);

	return ret;

    }

};
