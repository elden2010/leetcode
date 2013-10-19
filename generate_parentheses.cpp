#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
	vector<string> ret;
	vector<int> dif; // save for each string, the current dif of ( and )

	for(int j=0;j<2*n;++j)
	    if(j==0) {
		string s("(");
		ret.push_back(s);
		dif.push_back(1);
	    } else {
		int sz = ret.size();
		// check existing ret
		for(int i=0;i<sz;++i) {
		    if(dif[i]==0) { // paired ()
			ret[i].push_back('(');
			++dif[i];
		    } else {//
			// nleft + neight = j
                        // nleft - neight = dif[i]
			int nleft = (j+dif[i])/2;
			if(nleft==n) { // used all n (
			    ret[i].push_back(')');
			    --dif[i];
			} else {
			    // two choices: either ( or )
			    // so just replicate ret[i] and append at end
			    ret[i].push_back('(');
			    ++dif[i];
			    
			    ret.push_back(ret[i]); // replicate ret[i]
			    int last = ret.size();
			    ret[last-1][j] = ')';    // modify last element
			    dif.push_back(dif[i]-1);
			    --dif[last-1];
			    
			}
		    }
		    
		} // end checking last batch of ret
	    } // end checking last j
	return ret;
    }
};

int main() {
    Solution s;
    vector<string> vs = s.generateParenthesis(3);
    for(int i=0;i<vs.size();++i)
	cout << vs[i] << endl;

}
