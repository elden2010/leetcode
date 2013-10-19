/*
trick is to design the loop carefully and avoid dead loop
*/
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {

	if(n==0)
	    return 1;

	for(int i=0;i<n;++i)
	    if(A[i]<0 || A[i]>n)
		A[i] = 0;

	for(int i=0;i<n;++i) {
	    if(A[i]==i+1 || A[i]==0)
		continue;
	    else {
		int mv=A[i];
		A[i] = 0;		   
/*		for(int ii=0;ii<n;++ii)
		    cout << A[ii] << " " ;
		cout << endl;
*/		do {
		    int dst = mv-1; // where to put mv?
		    if(mv!=A[dst])
			swap(A[dst],mv);
		    else
			mv = 0;
		    // print A
/*		    for(int ii=0;ii<n;++ii)
			cout << A[ii] << " " ;
		    cout << endl;
		    cin.get();
*/		} while(mv!=0); // only stop when nothing to sort out in this loop
	    }

	    // move target to where it belongs
	}

	for(int i=0;i<n;++i)
	    if(A[i]==0)
		return i+1;

        return n+1;
    }
};

int main() {
    int A[7] = {7,6,5,4,-3,8,2},B[]={4,1,2,3};
    Solution s;
    int C[64] = {50,20,36,51,15,       -3,39,42,-10,20,
                 9,42,10,48,7,         -2,9,16,62,21,
                 45,39,57,30,20,              -3,-3,35,2,9,
                 -1,40,40,45,27,             -9,52,54,21,52,
                  10,18,9,8,54,               26,-6,-1,52,-8,
                  8,33,19,1,51,              49,9,58,-1,-1,
                  4,60,49,32};
    int D[] = {98,93,95,10,91,4,90,88,56,84,65,62,83,80,78,60,73,77,76,29,63,12,57,17,69,68,50,11,31,33,8,42,38,7,0,37,48,26,20,44,46,43,52,51,47,18,49,58,2,39,30,81,22,55,36,40,15,27,21,32,64,41,53,19,28,24,9,25,3,59,66,82,61,70,23,34,71,54,74,-1,1,45,14,79,5,35,13,72,75,85,87,6,16,86,67,89,94,92,96,97};
    cout << s.firstMissingPositive(D,sizeof(D)/sizeof(int)) << endl;
/*
    vector<string> 
    string line, blankline;
    while(getline(cin,line)) {
	cin >> line;
	// 
	istringstream iss(line);
	iss >> 

	getline(cin,blankline);
    }
*/
}
