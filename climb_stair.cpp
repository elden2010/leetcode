//#include <iostream>

//using namespace std;

int nchoosek(int n, int k) {
  if(k==0 || n==k)
    return 1;
  if(2*k>n)
    k = n-k;

  double retf = 1;
  for(int i=0;i<k;++i) {
    retf *= n-i;
    retf /= i+1;
  }

  int ret = retf;
  return ret;
}

class Solution {
public:
  int climbStairs(int n) {
    int ret = 0;

    // i*2+j*1 = n
    for(int i=0;i*2<=n;++i) {
      int j = n-2*i;
      // for current pair of i,j
      // there are j+i places to hold j 1's and i 2's
      ret += nchoosek(i+j,i);
    }
	
    return ret;
  }
};

/*
int main() {
  Solution s;
  std::cout << s.climbStairs(7) << std::endl; 
}
*/
