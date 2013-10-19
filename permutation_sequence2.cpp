#include <string>
#include <iostream>
//#include <vector>

using namespace std;

class Solution {
    char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int nfact[10] = {1,1,2,6,24,120,720,5040,40320,362880};

    string doit(string &base, int k) {

	if(k==1)
	    return base.substr(k);

//	cout << "entry: base=" << base << ", k=" << k << endl;
	int n = base.size()-1; // coz I added 0 there for easy index
	int ind = (k-1)/nfact[n-1]+1; 
	string ret;
	ret.push_back(base[ind]);

//	cout << "erasing ind=" << ind << endl;

	base.erase(ind,1);
	k = k%nfact[n-1];
	if(k==0)
	    k = nfact[n-1];
//	cout << "exit: base=" << base << ", k=" << k << endl;
	string ret2 = doit(base,k);
	ret += ret2;
	return ret;
    }

public:
    string getPermutation(int n, int k) {

	string base;
	for(int i=0;i<=n;++i)
	    base.push_back(digits[i]);
//	cout << base << endl;

	string ret = doit(base,k);
	return ret;
    }
};

int main() {
    Solution s;
    for(int i=1;i<=24;++i)
	cout << s.getPermutation(4,i) << endl;
}
