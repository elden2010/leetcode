#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

	vector<int> lens;
	unordered_map<char,int> ht;
	for(int i=0;i<n;++i) {
	    char c = s[i];
	    if(ht.count(c)>0) {// repeating char found
		lens.push_back(ht.size());
		// also need to remove all those keys whose values small than ht[c]
		unordered_map<char,int> ht2;
		for(auto it=ht.begin();it!=ht.end();++it)
		    if(it->second>ht[c])
			ht2.insert(*it);
		ht = ht2;
	    }
	    ht[c] = i;
	}
	// s ends so push ht.size()
	lens.push_back(ht.size());

	int maxlen = 0;	
	for(int i=0;i<lens.size();++i)
	    if(maxlen<lens[i])
		maxlen = lens[i];
	return maxlen;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("hchzvfrkmlnozjk") << endl;
}
