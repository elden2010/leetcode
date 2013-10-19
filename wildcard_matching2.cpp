/*
cannot pass large scale test either, Time Limit Exceeded
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
	string s1(s),s2(p);

	// check if chars before first * match
	int star1=-1;
	for(int i=0;i<s2.size();++i) {	  
	    if(s2[i]!='*') {
		if(i>=s1.size()) // s1 too short to match chars before first *
		    return false;
		if(s2[i]!='?' && s2[i]!=s1[i]) {
		    return false; // char not matching
		}
	    } else { // chars before first * match
		star1 = i;
		break;
	    }
	}
	if(star1==-1) // no *, all chars in s2 match s1
	    if(s1.size()==s2.size())
		return true;
	    else
		return false;

//	cout << "before front non-* matching, s1=" << s1 << endl;
//	cout << "before front non-* matching, s2=" << s2 << endl;
	s1 = s1.substr(star1);
	s2 = s2.substr(star1);
//	cout << "after front non-* matching, s1=" << s1 << endl;
//	cout << "after front non-* matching, s2=" << s2 << endl;	

	// check if chars after * in tail matches
	int star2=-1;
	for(int i=0;i<s2.size();++i) {
	    int ind2 = s2.size()-1-i; // index from back
	    if(s2[ind2]!='*') {
		if(i>=s1.size()) // s1 too short to match chars after last *
		    return false;
		int ind1 = s1.size()-1-i;
		if(s2[ind2]!='?' && s2[ind2]!=s1[ind1]) {
		    return false;
		}
	    } else {
		star2 = ind2;
		break;
	    }
	}

//	cout << "before back non-* matching, s1=" << s1 << endl;
//	cout << "before back non-* matching, s2=" << s2 << endl;
	s1 = s1.substr(0,s1.size()-(s2.size()-star2)+1);
	s2 = s2.substr(0,star2+1);
//	cout << "after back non-* matching, s1=" << s1 << endl;
//	cout << "after back non-* matching, s2=" << s2 << endl;

	vector<string> vs; // breaking p into sub-patterns without *
	int be = 0; // inside s2
	for(int i=0;i<=s2.size();++i)
	    if(i==s2.size() || s2[i]=='*') {
		string tmp = s2.substr(be,i-be);
		if(!tmp.empty())
		    vs.push_back(tmp);
		be = i+1;
	    }

	if(vs.empty())
	    return true;

//	for(int i=0;i<vs.size();++i)
//	    cout << vs[i] << endl;

	//store matching locations for each sub-pattern
	vector<vector<int> > locs;
	for(int z=0;z<vs.size();++z) {
	    string pat = vs[z];
	    vector<int> loc;
	    // matching pat to s1
	    for(int i=0;i<s1.size();++i) {
		bool matched = true;
		for(int j=0;j<pat.size();++j) {
		    if(pat[j]=='?' && i+j>=s1.size()) {
			matched = false;
			break;
		    }
		    if(pat[j]!='?' && pat[j]!=s1[i+j]) {
			matched = false;
			break;
		    }
		}
		if(matched)
		    loc.push_back(i);
	    }
	    if(loc.empty()) // no matching for pat
		return false;
	    locs.push_back(loc);

	}
	
	//locs
	cout << "locs:" << endl;
	for(int i=0;i<locs.size();++i) {
	    for(int j=0;j<locs[i].size();++j)
		cout << locs[i][j] << " ";
	    cout << endl;
	}

	// iteration through all Z sub-patterns' nz combo of positions
	int Z = vs.size();
	int cc = 0;
	vector<int> lb(Z,0);
	vector<int> ub(Z,0);
	for(int z=0;z<Z;++z)
	    ub[z] = locs[z].size();
	vector<int> ind(Z,0);
	bool nostop = true;
	while(nostop) {
            // increase ind by 1
	    int carry = 1;
	    for(int z=Z-1;z>=0;--z) {
		int tmp = ind[z]+carry;
		if(tmp==ub[z])
		    ind[z] = lb[z];
		else {
		    ind[z] = tmp;
		    carry = 0;// actually we do not care
		    break;
		}
	    }
	    for(int z=0;z<Z;++z)
		cout << ind[z] << " ";
	    cout << endl;
	    
            // check if stop
	    nostop = false;
	    for(int z=0;z<Z;++z)
		if(ind[z]!=ub[z]-1) {
		    nostop = true;
		    break;
		}


	    // check ind
	    bool matched = true;
	    for(int z=0;z<Z-1;++z)
		if(locs[z][ind[z]]+vs[z].size()>locs[z+1][ind[z+1]]) {
		    matched = false;
		    break;
		}
	    if(matched) {
/*		cout << "found this ind is valid matching:" << endl;
		for(int z=0;z<Z;++z)
		    cout << ind[z] << " ";
		cout << endl;
*/		
		return true;
	    }
	    cc++;
	}
	
	return false;
    }
};

int main() {
    Solution s;
    //cout << s.isMatch("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb","*b*b*b*b*b*b*b") << endl;
    cout << s.isMatch("mississippi","m*i*si*si*pi") << endl;

}
