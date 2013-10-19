#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
  vector<vector<int> > fourSum(vector<int> &num, int target) {

    vector<vector<int> > ret;
    set<vector<int> > ret0;
    int n = num.size();
    multimap<int,pair<int,int> > ht;

    // store 2 sum
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j)
	ht.insert(make_pair(num[i]+num[j],make_pair(i,j)));

    // double loop and check if the - 2 sum exist in ht
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j)
	if(ht.count(target-num[i]-num[j])>0) {
	  pair<multimap<int,pair<int,int> >::iterator,multimap<int,pair<int,int> >::iterator> range = ht.equal_range(target-num[i]-num[j]);
	  for(multimap<int,pair<int,int> >::iterator it=range.first;it!=range.second;++it) {
	    pair<int,int> tind = it->second;
	    if(tind.first==i || tind.first==j || tind.second==i || tind.second==j)
	      continue;
	    vector<int> quad(4,0);
	    quad[0] = num[i];
	    quad[1] = num[j];
	    quad[2] = num[tind.first];
	    quad[3] = num[tind.second];
	    sort(quad.begin(),quad.end());
	    ret0.insert(quad);
	  }
	}

    // store
    for(set<vector<int> >::iterator it=ret0.begin();it!=ret0.end();++it)
      ret.push_back(*it);
    return ret;
  }
};

int main() {
  vector<int> num;
  num.push_back(1);
  num.push_back(0);
  num.push_back(-1);
  num.push_back(0);
  num.push_back(-2);
  num.push_back(2);
  //  num.push_back(2);
  //num.push_back(-1);
  //num.push_back(-4);

  Solution s;
  vector<vector<int> > ret = s.fourSum(num,0);
  for(int i=0;i<ret.size();++i) {
    for(int j=0;j<4;++j)
      cout << " " << ret[i][j];
    cout<<endl;
  }

}
