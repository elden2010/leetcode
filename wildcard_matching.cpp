/*cannot pass large test, due to exponential growth of combinations*/
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
	    locs.push_back(loc);

	}
	
	//locs
	cout << "locs:" << endl;
	for(int i=0;i<locs.size();++i) {
	    for(int j=0;j<locs[i].size();++j)
		cout << locs[i][j] << " ";
	    cout << endl;
	}

	// make combinations of locs
	vector<vector<int> > all;
	int n = 1;
	for(int z=0;z<locs.size();++z)
	    if(z==0)
		for(int j=0;j<locs[z].size();++j) {
		    vector<int> row(1,locs[z][j]);		    
		    all.push_back(row);
		}
	    else {
		vector<vector<int> > all2;
		vector<int> zloc = locs[z];
		for(int i=0;i<all.size();++i)
		    for(int j=0;j<zloc.size();++j) {
			int last = all[i].size()-1;
			bool tmp2 = all[i][last]+vs[z-1].size()<=zloc[j];
			if(!all[i].empty() && tmp2) {
			    vector<int> row = all[i];
			    row.push_back(zloc[j]);
			    all2.push_back(row);
			}
		    }
		all = all2;			    
	    }

	//locs
	cout << "all:" << endl;
	for(int i=0;i<all.size();++i) {
	    for(int j=0;j<all[i].size();++j)
		cout << all[i][j] << " ";
	    cout << endl;
	}	

	bool ret = !all.empty();

	return ret;
    }
};

int main() {
    Solution s;
    cout << s.isMatch("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb","*b*b*b*b*b*b*b") << endl;

}
