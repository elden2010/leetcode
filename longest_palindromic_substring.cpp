/*
omg: 3 hours of work on 4/2/2013
the main challenge is to find all bugs for all test cases
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
	string ret = "";
	if(s.empty())
	    return ret;

        // make vc as non-repeating version of s
        // save counts in vi
	vector<char> vc;
	vector<int> vi;
	vc.push_back(s[0]);
	vi.push_back(1);
	for(int i=1;i<s.size();++i)
	    if(s[i]==vc.back())
		++ vi.back();
	    else {
		vc.push_back(s[i]);
		vi.push_back(1);
	    }
	
	//
	cout << "vc = ";
	for(int i=0;i<vc.size();++i)
	    cout << vc[i] << " ";
	cout << endl;
	cout << "vi = ";
	for(int i=0;i<vi.size();++i)
	    cout << vi[i] << " ";
	cout << endl;
    
	// store candidate index, can only have odd symmetry, since we merged same consecutive chars 
	vector<int> ind; 
	if(vc.size()==1)
	    ind.push_back(0);
	else if(vc.size()==2)
	    if(vi[0]>vi[1])
		ind.push_back(0);
	    else
		ind.push_back(1);
	else {
	    // largest a pattern
	    int maxvi = 0;
	    int maxviind = -1;
	    for(int i=0;i<vi.size();++i)
		if(maxvi<vi[i]) {
		    maxvi = vi[i];
		    maxviind = i;
		}
	    ind.push_back(maxviind);
	    // aba pattern
	    for(int i=1;i<vc.size()-1;++i)
		if(vc[i+1]==vc[i-1])
		    ind.push_back(i);
	}
	//
	cout << "ind = ";
	for(int i=0;i<ind.size();++i)
	    cout << ind[i] << " ";
	cout << endl;

	    int n = ind.size();
//	    cout << "n=" << n << endl;
	    int maxlen = 0;// length of max palindrome substring at position ind[i]
	    int maxlenind = -1; // which vc
	    int maxlenwidth = -1; // how much to extend in vc from maxlenind
	    int maxlenextra = 0; // how much to extend for vc[maxlenind-width-1] and vc[maxlenind+width+1]

	    for(int i=0;i<n;++i) {
		int ind4vcvi = ind[i];
		int cc = vi[ind4vcvi];
		int width = 0;
		bool toexpand,tmp1,tmp2,tmp3;
		do {
		    width++;
		    int lb = ind4vcvi-width;
		    int ub = ind4vcvi+width;
		    tmp1 = lb>=0 && ub<vi.size();
		    tmp2 = vc[lb]==vc[ub];
		    tmp3 = vi[lb]==vi[ub];
		    toexpand = tmp1 && tmp2 && tmp3;
		} while(toexpand);
		width--;
		cout << "tmp1=" << tmp1 << ",tmp2=" << tmp2  << ",tmp3=" << tmp3 << endl;

		// update cc
		for(int ii=1;ii<=width;++ii) // ignore the central one, since it is the initialization value
		    cc += 2*vi[ind4vcvi-ii];

		// special case when vc[width+1] match but vi[width+1] did not match, such as "aaabbbccbbba", vc=[a,b,c,b,a],vi=[3,3,2,3,1], cc = 2+2*3+2*1
		if(tmp1 && tmp2 && !tmp3)
		    cc += 2*min(vi[ind4vcvi-width-1],vi[ind4vcvi+width+1]);

		cout << "i=" << i << ",cc=" << cc << endl;

		if(maxlen<cc) {
		    maxlen = cc;
		    maxlenind = ind4vcvi;
		    maxlenwidth = width;
		    if(tmp1 && tmp2 && !tmp3)
			maxlenextra = min(vi[ind4vcvi-width-1],vi[ind4vcvi+width+1]);
		    else
			maxlenextra = 0;
		}
	    }

	    //
	    cout << maxlenind << endl;
	    cout << maxlenwidth << endl;
	    cout << maxlenextra << endl;

	    // build ret from maxlenind and maxlen
	    for(int j=0;j<maxlenextra;++j)
		ret.push_back(vc[maxlenind-maxlenwidth-1]);
	    for(int i=-maxlenwidth;i<0;++i)
		for(int j=0;j<vi[maxlenind+i];++j)
		    ret.push_back(vc[maxlenind+i]);
	    for(int j=0;j<vi[maxlenind];++j)
		ret.push_back(vc[maxlenind]);
	    for(int i=1;i<=maxlenwidth;++i)
		for(int j=0;j<vi[maxlenind+i];++j)
		    ret.push_back(vc[maxlenind+i]);
	    for(int i=0;i<maxlenextra;++i)
		ret.push_back(vc[maxlenind+maxlenwidth+1]);
       

//	cout << "ret=" << ret << "*"<<endl;
	return ret;
    }
};

int main() {
    Solution s;
    cout << s.longestPalindrome("lqlvciwekzxapmjxyddlaoqhfhwphamsyfwjinkfvciucjhdgwodvmnpkibumexvlsxxumvrznuuyqfavmgwfnsvfbrvqhlvhpxaqehsiwxzlvvtxsnmlilbnmvnxyxitxwoahjricdjdncvartepfpdfndxqoozkfpdmlpvshzzffsspdjzlhmamqooooor") << "*"<< endl;
    /*  cout << s.longestPalindrome("bb") << endl;
   cout << s.longestPalindrome("ccc") << endl;
   cout << s.longestPalindrome("abb") << endl;
   cout << s.longestPalindrome("ccd") << endl;
   cout << s.longestPalindrome("aba") << endl;
   cout << s.longestPalindrome("aaaa") << endl;
   cout << s.longestPalindrome("adam") << endl;
   cout << s.longestPalindrome("caba") << endl;
    */
}
