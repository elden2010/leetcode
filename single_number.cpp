#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
	int ret = 0;
	for(int i=0;i<n;++i)
	    ret = ret ^ A[i];
	return ret;        
    }
};

int main() {
    int A[] = {1,2,2,3,3,4,4,1,5};
    Solution s;
    cout << s.singleNumber(A,9) << endl;
}
