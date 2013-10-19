#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
	vector<Interval> ret,ret2;

	// convert intervals to numbers
	vector<int> nums;
	for(int i=0;i<intervals.size();++i) {
	    nums.push_back(intervals[i].start);
	    nums.push_back(intervals[i].end);
	}
	
	// find out where the start and end is for newInterval
	int i,j;
	for(i=0;i<nums.size();++i)
	    if(newInterval.start<nums[i])
		break;

	for(j=i;j<nums.size();++j)
	    if(newInterval.end<nums[j])
		break;

	// 
	if(i%2==0 && j%2==0) { // does not matter if j==j
	    copy(intervals.begin(),intervals.begin()+i/2,back_inserter(ret));
	    ret.push_back(newInterval);
	    copy(intervals.begin()+j/2,intervals.end(),back_inserter(ret));	
	} else if(i%2==1 && j%2==1) { // both odd: 
	    copy(intervals.begin(),intervals.begin()+(i-1)/2,back_inserter(ret));
	    Interval tmp(nums[i-1],nums[j]);
	    ret.push_back(tmp);
	    copy(intervals.begin()+(j+1)/2,intervals.end(),back_inserter(ret));
	} else if(i%2==1 && j%2==0) {
	    copy(intervals.begin(),intervals.begin()+(i-1)/2,back_inserter(ret));
	    Interval tmp(nums[i-1],newInterval.end);
	    ret.push_back(tmp);
	    copy(intervals.begin()+j/2,intervals.end(),back_inserter(ret));
	} else {
	    copy(intervals.begin(),intervals.begin()+i/2,back_inserter(ret));
	    Interval tmp(newInterval.start,nums[j]);
	    ret.push_back(tmp);
	    copy(intervals.begin()+(j+1)/2,intervals.end(),back_inserter(ret));
	}

	// merge if consecutive
	for(int i=0;i<ret.size();++i)
	    if(i==0)
		ret2.push_back(ret[0]);
	    else
		if(ret[i-1].end==ret[i].start)
		    ret2.back().end = ret[i].end;
		else
		    ret2.push_back(ret[i]);

        return ret2;
    }
};

int main() {

    Interval newInterval(5,7),tmp(1,5);
    vector<Interval> intervals;
    intervals.push_back(tmp);

    Solution s;
    s.insert(intervals,newInterval);
}
