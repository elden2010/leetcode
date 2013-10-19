/*
c++11 only: used unordered_multimap
 */
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
 
    vector<vector<int> > ret;
    size_t n = num.size();
    unordered_multimap<int,pair<int,int> > ht;

    // storing 2 sum 
    for(size_t i=0;i<n;++i)
      for(size_t j=i+1;j<n;++j)
	ht.insert(make_pair(num[i]+num[j],make_pair(i,j)));
    
    // 3 sum
    for(size_t i=0;i<n;++i)
      if (ht.count(-num[i])>0) {
	auto range = ht.equal_range(-num[i]);
	for(auto it=range.first;it!=range.second;++it) {
	  pair<int,int> tInd = it->second;
	  if(tInd.first==i || tInd.second==i)
	    continue;

	  vector<int> triple;
	  triple.push_back(num[tInd.first]);
	  triple.push_back(num[tInd.second]);
	  triple.push_back(num[i]);
	  sort(triple.begin(),triple.end());

	  ret.push_back(triple);
	}
      }

    // remove duplicates
    sort(ret.begin(),ret.end());
    auto it2 = unique(ret.begin(),ret.end());
    ret.resize(it2-ret.begin());
 
    return ret;
  }
};

int main() {
  vector<int> num{-1,0,1,2,-1,-4};
  Solution s;
  vector<vector<int> > ret = s.threeSum(num);


  for(int i=0;i<ret.size();++i) {
    for(int j=0;j<ret[i].size();++j)
      cout << ret[i][j] << " ";
    cout << endl;
  }
}
