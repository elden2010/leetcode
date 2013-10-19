#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
	if(nRows==1)
	    return s;

	vector<vector<char> > vvc;
	for(int i=0;i<nRows;++i) {
	    vector<char> vc;
	    vvc.push_back(vc);
	}
	
	for(int i=0;i<s.size();++i) {
	    int z = i % (2*nRows-2);
	    int ii;
	    if(z<=nRows-1) {// going down
		ii = z;
	    } else {// going up
		ii = 2*nRows-2-z;
	    }
	    vvc[ii].push_back(s[i]);
        }

	string ret;
	for(int i=0;i<nRows;++i)
	    for(int j=0;j<vvc[i].size();++j)
		ret.push_back(vvc[i][j]);

	return ret;

    }
};

int main() {
    Solution s;
    cout << s.convert("PAYPALISHIRING",3) << endl;

}
