#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
	int ret = 0;
	if(prices.empty())
	    return ret;

	for(int i=0;i<prices.size()-1;++i) {
	    int dif = prices[i+1]-prices[i];
	    if(dif>0)
		ret += dif;
	}

	return ret;
        
    }
};

int main() {
    vector<int> A;
    Solution s;
    cout << s.maxProfit(A) << endl;
}
