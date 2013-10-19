/*
this one cannot pass large test, as it is essentially O(n^2) complexity
*/


#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
    int maxProfit(vector<int> &prices) {
	int n = prices.size();
	if(n<=1)
	    return 0;

	vector<int> past(n,0);
	int valley = prices[0];
	int best = 0; // cannot be negative
	for(int i=1;i<=n-1;++i) {
	    if(prices[i]<valley)
		valley = prices[i];
	    if(prices[i]-valley>best)
		best = prices[i]-valley;
	    past[i] = best;
	}

	vector<int> future(n,0);
	int peak = prices[n-1];
	best = 0; // cannot be negative
	for(int i=n-2;i>=0;--i) {
	    if(prices[i]>peak)
		peak = prices[i];
	    if(peak-prices[i]>best)
		best = peak-prices[i];
	    future[i] = best;
	}

	best = 0;
	for(int i=0;i<n;++i)
	    if (past[i]+future[i]>best)
		best = past[i]+future[i];
	return best;
    }
};

int main() {

/* my solution gives 6  (13247), but it should be 13 247*/
    vector<int> v;
    v.push_back(6);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
  
    Solution s;
    cout << s.maxProfit(v) << endl;
}
