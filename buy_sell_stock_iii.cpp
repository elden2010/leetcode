/* wrong version */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
    // given a integer array, find the maximum sub array sum
    int maxProfit1(vector<int> &changes,int &be,int &en) {
	// too few elements
	if(changes.empty())
	    return 0;

	// max sub array sum by dynamic programming
	
        // initialization
	int best = 0; // cannot be nagative
	be = en = -1;
	int bestEndAtI = changes[0];
	int be2=0,en2=0;
	if(bestEndAtI>best) {
	    best = bestEndAtI;
	    be = en = 0;
	}

	// loop
	for(int i=1;i<changes.size();++i) {
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
	if(prices.size()<=1)
	    return 0;

	// changes
	vector<int> changes;
	for(int i=0;i<prices.size()-1;++i)
	    changes.push_back(prices[i+1]-prices[i]);

	int be,en;
	int p1 = maxProfit1(changes,be,en);
	if(be==-1||en==-1)
	    return 0;

	vector<int> changesBefore,changesAfter;
	for(int i=0;i<be;++i)
	    changesBefore.push_back(changes[i]);
	for(int i=en+1;i<changes.size();++i)
	    changesAfter.push_back(changes[i]);


	int p2 = maxProfit1(changesBefore,be,en);
	int p3 = maxProfit1(changesAfter,be,en);
	if(p2>p3)
	    return p1+p2;
	else
	    return p1+p3;

	return 0;
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
    v.push_back(7)
;  
    Solution s;
    cout << s.maxProfit(v) << endl;
}
