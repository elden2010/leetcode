/* this one is to pass big test as well with O(n^2) complexity
1. no need to use set to guarantee uniqueness
2. be careful when ++i, ++j, --k, make sure not going out of bounds
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
 
    vector<vector<int> > ret;
    size_t n = num.size();
    sort(num.begin(),num.end());
    
    size_t i,j,k;
    i=0;
    while(i<n) {
      j = i+1;
      k = n-1;
      while(j<k) {
	int sum = num[i]+num[j]+num[k];
	if(sum==0) {
	  vector<int> triple;
	  triple.push_back(num[i]);
	  triple.push_back(num[j]);
	  triple.push_back(num[k]);
	  ret.push_back(triple);
	  // increase j until different
	  int old = num[j];
	  while(j<n-1 && num[j+1]==old)
	    ++j;
	  if(j<n-1)
	    ++j;
	  // decrease k until different
	  old = num[k];
	  while(k>0 && num[k-1]==old)
	    --k;
	  if(k>0)
	    --k;
	} else if(sum>0) { // decrease k until different
	  int old = num[k];
	  while(k>0 && num[k-1]==old)
	    --k;
	  if(k>0)
	    --k;
	} else { // increase j until differnt
	  int old = num[j];
	  while(j<n-1 && num[j+1]==old)
	    ++j;
	  if(j<n-1)
	    ++j;
	}
      }
      // increase i until different
      int old = num[i];
      while(i<n-1 && num[i+1]==old)
	++i;
      ++i;
    }
    
    return ret;
  }
};

int main() {
  vector<int> num;
  num.push_back(0);
  num.push_back(0);
  num.push_back(0);
  //  num.push_back(2);
  //num.push_back(-1);
  //num.push_back(-4);

  Solution s;
  vector<vector<int> > ret = s.threeSum(num);


  for(int i=0;i<ret.size();++i) {
    for(int j=0;j<ret[i].size();++j)
      cout << ret[i][j] << " ";
    cout << endl;
  }
}
