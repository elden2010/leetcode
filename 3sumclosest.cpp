#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {

    vector<int> values;
    int n = num.size();
    bool noequal = true;

    sort(num.begin(),num.end());

    int i=0,j,k;
    while(i<=n-3 && noequal) {
      j = i+1;
      k = n-1;
      while(j<k) {
	int tmp = num[i]+num[j]+num[k];
	values.push_back(tmp);
	if(tmp==target) {	  
	  noequal=false;
	  break;
	} else if(tmp>target) {
	  k--;
	} else {
	  j++;
	}	  
      }
      ++i;
    }
 
    int minv = abs(target-values[0]);
    int ind = 0;
    for(int z=1;z<values.size();++z) {
      int tmp = abs(target-values[z]); 
      if(tmp<minv) {
	minv = tmp;
	ind = z;
      }
    }
    
    return values[ind];
  }
};

int main() {
  vector<int> num;
  num.push_back(-1);
  num.push_back(2);
  num.push_back(1);
  num.push_back(-4);

  //  num.push_back(2);
  //num.push_back(-1);
  //num.push_back(-4);

  Solution s;
  int ret = s.threeSumClosest(num,1);

  cout << ret << endl;

}
