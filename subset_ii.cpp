class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
	sort(S.begin(),S.end());

	// base
	set<vector<int> > ret;
	vector<int> NIL;
	ret.insert(NIL);

        // iteration
	for(int i=0;i<S.size();++i) {
	    set<vector<int> > tmp(ret);
	    // ret outer product  with two choices of S[i]
	    for(set<vector<int> >::iterator j=ret.begin();j!=ret.end();++j) {
		vector<int> row(*j);
		row.push_back(S[i]);
		tmp.insert(row);
	    }
	    ret = tmp;
	}

	vector<vector<int> > ret2(ret.begin(),ret.end());
	return ret2;
    }
};
