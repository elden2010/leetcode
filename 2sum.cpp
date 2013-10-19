#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
	vector<int> ret(2,0);
	unordered_map<int,int> ht;
	for(int i=0;i<numbers.size();++i) {
	    int num = numbers[i];
	    int other = target-num;
	    if(ht.count(other)>0) {
		ret[0] = ht[other]+1; 
		ret[1] = i+1;
		break; // assuming unique solution
	    } else
		ht[num] = i;	    
	}
	return ret;
    }
};

int main() {
    vector<int> A{91,90,11,7};
    Solution s;
    vector<int> ret = s.twoSum(A,18);
    cout << ret[0] << " " << ret[1] << endl;
}
