/*
this one cannot pass large test, as it is essentially O(n^2) complexity
*/


#include <vector>
#include <iostream>

using namespace std;

class Solution {
    // given a integer array, find the maximum sub array sum
    int maxProfit1(vector<int> &changes,int a,int b) {

	// max sub array sum by dynamic programming
	
        // initialization
	int best = 0; // cannot be nagative
	int be=-1, en = -1;
	int bestEndAtI = changes[a];
	int be2=a,en2=a;
	if(bestEndAtI>best) {
	    best = bestEndAtI;
	    be = en = a;
	}

	// loop
	for(int i=a+1;i<=b;++i) {
	    // update bestEndAtI;
	    if(bestEndAtI>0) {
		bestEndAtI += changes[i];
		en2 = i;
	    }  else {
		bestEndAtI = changes[i];
		be2 = en2 = i;
	    }
	    // update best
	    if(en==i-1) {
		if(changes[i]>=0) {
		    best = best+changes[i];
		    en = i;
		} 
	    } else
		if(best<bestEndAtI) {
		    best = bestEndAtI;
		    be = be2;
		    en = i;
		}
 	}
	return best;	
    }

public:
    int maxProfit(vector<int> &prices) {
	int n = prices.size();
	if(n<=1)
	    return 0;

	// changes
	vector<int> changes;
	for(int i=0;i<n-1;++i)
	    changes.push_back(prices[i+1]-prices[i]);
	int m = changes.size();

	int pmax = maxProfit1(changes,0,m-1);

	for(int i=0;i<=m-2;++i) {
	    int p1 = maxProfit1(changes,0,i);
	    int p2 = maxProfit1(changes,i+1,m-1);
	    if(p1+p2>pmax)
		pmax = p1+p2;
	}
	return pmax;
    }
};

int main() {

/* my solution gives 6  (13247), but it should be 13 247*/
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
  
    Solution s;
    cout << s.maxProfit(v) << endl;
}
