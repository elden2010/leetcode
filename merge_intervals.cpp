#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void print(const vector<Interval> &VI) {
    for(int i=0;i<VI.size();++i)
	cout << "[" <<VI[i].start <<","<< VI[i].end << "],";
    cout << endl;
}

bool mycomp(Interval I1,Interval I2) {
    bool tmp1 = I1.start < I2.start;
    bool tmp2 = I1.start == I2.start && I1.end<=I2.end;
    return tmp1 || tmp2;
}

class Solution {
    vector<Interval> merge2(vector<Interval> VI,Interval I) {
/*	cout << "entering merge2" << endl;
	cout << "VI=:" << endl;
	print(VI);
	cout << "I=[" << I.start <<","<< I.end <<"]"<< endl;
*/
	// assuming VI are all non-overlapping
	vector<Interval> ret;
	bool first = true;
	Interval accu;
	for(int i=0;i<VI.size();++i) {
	    Interval I1 = VI[i];
	    if(I1.end < I.start || I.end < I1.start) // I1, I not overlapping
		ret.push_back(I1);
	    else { // there is overlaping
		if(first) {
		    first = false;
		    accu = merge2overlap(I1,I);
		} else
		    accu = merge2overlap(I1,accu);
	    }
	}
	if(first) // never any overlap
	    ret.push_back(I);
	else // there is overlap
	    ret.push_back(accu);
	sort(ret.begin(),ret.end(),mycomp);

/*	cout << "exiting merge2 and ret=:" << endl;
	print(ret);
*/
	return ret;
    }

    Interval merge2overlap(Interval I1,Interval I2) {
	if (I1.start<=I2.start && I1.end>=I2.end) // 
	    return I1;
	else if (I1.start>=I2.start && I1.end<=I2.end) 
	    return I2;
	else if(I1.start<=I2.start && I1.end >= I2.start && I1.end <= I2.end)
	    return Interval(I1.start,I2.end);
	else if(I2.start<=I1.start && I2.end >= I1.start && I2.end<=I1.end)
	    return Interval(I2.start,I1.end);
	else {
	    cout << "debug" << endl;
	    return I1;
	}
    }
    

public:
    vector<Interval> merge(vector<Interval> &intervals) {
	if(intervals.size()<2)
	    return intervals;
	
	// at least two intervals
	Interval last = intervals.back();
	intervals.pop_back();
	vector<Interval> ret1 = merge(intervals);
	vector<Interval> ret2 = merge2(ret1,last);
	return ret2;
    }
};



int main() {
    Solution s;
    Interval I1(1,3);
    Interval I2(2,6);
    Interval I3(8,10);
    Interval I4(15,18);
    vector<Interval> VI{I1,I2,I3,I4};
    print(VI);
    
    vector<Interval> ret = s.merge(VI);
    print(ret);

}
