#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    // SigCount stores the unique signature (sorted version of each str) and its frequency in the strs
    // ret stores all strings with a signature count bigger than 1
    // sig stores all signature
    map<string,int> SigCount;
    vector<string> sig,ret;

    // loop through strs to build SigCount
    for(vector<string>::iterator it=strs.begin();
	it!=strs.end();
	++it) {
      string s = *it;
      sort(s.begin(),s.end());
      sig.push_back(s);
      ++ SigCount[s];
    }

    // another loop to copy those with count bigger than 1
    for(int i=0;i<sig.size();++i) {
      string s = sig[i];
      if(SigCount[s]>1)
	ret.push_back(strs[i]);
    } 

    return ret;
  }
};
