/* this one can pass small test but not large test 
non-c++11
O(n^2*log(n))

1. sort first
2. save only the original elements into multimap (BST), and use BST lookup within double loop
3. used set to guarantee uniqueness

*/



#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
 
    vector<vector<int> > ret;
    set<vector<int> > ret0;
    size_t n = num.size();
    multimap<int,int> ht; // use unordered_multimap in c++11

    // sort first
    sort(num.begin(),num.end());

    // storing num elements into 
    for(size_t i=0;i<n;++i)
	ht.insert(make_pair(num[i],i));
    
    // double loop and check if the 3rd number exists
    for(size_t i=0;i<n;++i)
      for(size_t j=i+1;j<n;++j)
	if (ht.count(-num[i]-num[j])>0) {
	pair<multimap<int,int>::iterator,multimap<int,int>::iterator> range = ht.equal_range(-num[i]-num[j]);
	for(multimap<int,int>::iterator it=range.first;it!=range.second;++it) {
	  int tInd = it->second;
	  if(tInd==i || tInd==j)
	    continue;

	  vector<int> triple;
	  if (tInd>j) {
	    triple.push_back(num[i]);
	    triple.push_back(num[j]);
	    triple.push_back(num[tInd]);
	  } else if (tInd>i) {
	    triple.push_back(num[i]);
	    triple.push_back(num[tInd]);
	    triple.push_back(num[j]);
	  } else {
	    triple.push_back(num[tInd]);
	    triple.push_back(num[i]);
	    triple.push_back(num[j]);
	  }

	  ret0.insert(triple);
	}
      }

    // copy from set to vector
    for(set<vector<int> >::iterator it=ret0.begin();it!=ret0.end();++it)
      ret.push_back(*it);
 
    return ret;
  }
};



int main() {
  vector<int> num1{13,4,-6,-7,-15,-1,0,-1,0,-12,-12,9,3,-14,-2,-5,-6,7,8,2,-4,6,-5,-10,-4,-9,-14,-14,12,-13,-7,3,7,2,11,7,9,-4,13,-6,-1,-14,-12,9,9,-6,-11,10,-14,13,-2,-11,-4,8,-6,0,7,-12,1,4,12,9,14,-4,-3,11,10,-9,-8,8,0,-1,1,3,-15,-12,4,12,13,6,10,-4,10,13,12,12,-2,4,7,7,-15,-4,1,-15,8,5,3,3,11,2,-11,-12,-14,5,-1,9,0,-12,6,-1,1,1,2,-3};
  vector<int> num{12,13,-10,-15,4,5,-8,11,10,3,-11,4,-10,4,-7,9,1,8,-5,-1,-9,-4,3,-14,-11,14,0,-8,-6,-2,14,-9,-4,11,-8,-14,-7,-9,4,10,9,9,-1,7,-10,7,1,6,-8,12,12,-10,-7,0,-9,-3,-1,-1,-4,8,12,-13,6,-7,13,5,-14,13,12,6,8,-2,-8,-15,-10,-3,-1,7,10,7,-4,7,4,-4,14,3,0,-10,-13,11,5,6,13,-4,6,3,-13,8,1,6,-9,-14,-11,-10,8,-5,-6,-7,9,-11,7,12,3,-4,-7,-6,14,8,-1,8,-4,-11};
  /*  num.push_back(-1);
  num.push_back(0);
  num.push_back(1);
  num.push_back(2);
  num.push_back(-1);
  num.push_back(-4);
  */
  Solution s;
  vector<vector<int> > ret = s.threeSum(num);


  for(int i=0;i<ret.size();++i) {
    for(int j=0;j<ret[i].size();++j)
      cout << ret[i][j] << " ";
    cout << endl;
  }
}
