/* non-c++11
this one can pass small test but not large test 
because I am using map (BST) so the complexity became O(n^2*log(n))
in this version:
1. saving 2sum: double loop with BST insertion
2. for the 3rd summant: single loop with BST lookup
3. used explicit duplicate removal
*/



#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
 
    vector<vector<int> > ret;
    size_t n = num.size();
    multimap<int,pair<int,int> > ht;

    // storing 2 sum 
    for(size_t i=0;i<n;++i)
      for(size_t j=i+1;j<n;++j)
	ht.insert(make_pair(num[i]+num[j],make_pair(i,j)));
    
    // 3 sum
    for(size_t i=0;i<n;++i)
      if (ht.count(-num[i])>0) {
	pair<multimap<int,pair<int,int> >::iterator,multimap<int,pair<int,int> >::iterator> range = ht.equal_range(-num[i]);
	for(multimap<int,pair<int,int> >::iterator it=range.first;it!=range.second;++it) {
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
    vector<vector<int> >::iterator it2 = unique(ret.begin(),ret.end());
    ret.resize(it2-ret.begin());
 
    return ret;
  }
};

int main() {
  vector<int> num;
  num.push_back(-1);
  num.push_back(0);
  num.push_back(1);
  num.push_back(2);
  num.push_back(-1);
  num.push_back(-4);

  Solution s;
  vector<vector<int> > ret = s.threeSum(num);


  for(int i=0;i<ret.size();++i) {
    for(int j=0;j<ret[i].size();++j)
      cout << ret[i][j] << " ";
    cout << endl;
  }
}
