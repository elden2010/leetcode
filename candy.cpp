#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

class Solution {
    vector<int> candyNoAdjacentEqual(const vector<int> &A) {
	int n = A.size();
	vector<int> num(n,0);

	// corner case
	if(n==1) {
	    num[0] = 1;
	    return num;
	}

	// find 1-point valley
	vector<int> valley;
	for(int i=0;i<n;++i)
	    if( (i==0 && A[i]<A[i+1]) || (i==n-1 && A[i] < A[i-1]) || (i!=0 && i!=n-1 && A[i]<A[i+1] && A[i]<A[i-1]) )
		valley.push_back(i);

	// VALIDATE
	if(valley.empty())
	    throw logic_error("debug me 1");

	// flood from 1-point valley
	for(int i=0;i<valley.size();++i) {
	    int ind = valley[i];
	    num[ind] = 1;

	    // go left, up
	    int ind1 = ind - 1;
	    int toassign = 2;
	    while(ind1>=0)
		if(A[ind1]>A[ind1+1] && num[ind1]<toassign )
		    num[ind1--] = toassign ++;
		else // not up any more
		    break;

	    // go right, up
	    int ind2 = ind + 1;
	    toassign = 2;
	    while(ind2<n)
		if(A[ind2]>A[ind2-1] && num[ind2]<toassign)
		    num[ind2++] = toassign ++;
		else // not up any more
		    break;		    
	}
	
	// VALIDATE
	for(auto v : num)
	    if(v==0)
		throw logic_error("debug me 2");

	return num;
    }
public:
    int candy(vector<int> &ratings) {
	if(ratings.empty())
	    return 0;

	int n = ratings.size();
        vector<int> num2(n,0);

	// remove adjacent duplicates
	vector<int> nodup;
	nodup.push_back(ratings[0]);
	int last = ratings[0];
	for(int i=1;i<n;++i)
	    if(ratings[i]!=last) {
		nodup.push_back(ratings[i]);
		last = ratings[i];
	    }

	// work on nodup
	vector<int> num = candyNoAdjacentEqual(nodup);
	
	
	// 
	int j=0;
	last = ratings[0];
	num2[0] = num[0];
	for(int i=1;i<n;++i)
	    if(ratings[i] == last) { // replicate
//		num2[i] = num[j];		
		num2[i] = 1; // equal means just get 1 for this		
	    } else {	
		++j;
		last = ratings[i];
		num2[i] = num[j];
	    }
	
	// 
	int sum = 0;
	for(auto v: num2)
	    sum += v;
	return sum;
    }
};

int main() {
    vector<int> vi{2,2,1};
    Solution s;
    cout << s.candy(vi) << endl;
}
