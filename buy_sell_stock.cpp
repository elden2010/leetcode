class Solution {
public:
    int maxProfit(vector<int> &prices) {

	if(prices.size()<=1)
	    return 0;

	vector<int> changes;
	for(int i=0;i<prices.size()-1;++i)
	    changes.push_back(prices[i+1]-prices[i]);

	// intialize
	int best1 = 0;  // cannot be negative
	int best2 = changes[0]; // sum of best sub array ending at i
	bool same=false;
	if(best2>best1) {
	    best1=best2;
	    same = true;
	}

	// loop
	for(int i=1;i<changes.size();++i) {
	    // best2 update
	    if(best2>=0)
		best2 = best2+changes[i];
	    else
		best2 = changes[i];
	    // best1 update
	    if(same) {
		if(changes[i]>=0) {
		    best1 = best2;
		    same = true;
		} else
		    same = false;
	    } else {
		if(best2>=best1) {
		    best1 = best2;
		    same = true;
		} else {
		    same = false;
		}
	    }
	}

	return best1;

    }
};
