class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
	sort(S.begin(),S.end());

	// base
	vector<vector<int> > ret;
	vector<int> NIL;
	ret.push_back(NIL);

        // iteration
	for(int i=0;i<S.size();++i) {
	    // ret outer product  with two choices of S[i]
	    int sz = ret.size();
	    for(int j=0;j<sz;++j) {
		vector<int> row(ret[j]);
		row.push_back(S[i]);
		ret.push_back(row);
	    }
	}

	return ret;
    }
};
