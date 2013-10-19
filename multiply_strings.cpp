/*need to group numbers into 4-digit so 4-digit *4-digit can still be int */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    char digits[10] = {'0','1','2','3','4','5','6','7','8','9'};

    void add(vector<int> &vi,int z,int v) {
	while(v >0) {
	    int tmp = vi[z] + v;	    
	    if(tmp<10) {
		vi[z] = tmp;
		v = 0;
	    } else {
		vi[z] = tmp % 10;
		v = tmp/10;
		z ++;
	    }
	}
    }
public:
    string multiply(string num1, string num2) {
	int m = num1.size(),n=num2.size();

	// product is at most m+n digits
	vector<int> v1(m,0),v2(n,0),prod(m+n,0);
	for(int i=m-1;i>=0;--i)
	    v1[m-1-i] = num1[i]-'0';
	for(int i=n-1;i>=0;--i)
	    v2[n-1-i] = num2[i]-'0';

	for(int i=0;i<m;++i)
	    for(int j=0;j<n;++j) {
		int value = v1[i]*v2[j]; // 0-81
		int base = value % 10;
		int carry = value / 10;
		int targetind = i+j;
		
		add(prod,targetind, base);
		add(prod,targetind+1, carry);
	    }



	// vec to string: ignore leading 0's	
	string ret;
	bool leading = true;
	for(int i=m+n-1;i>=0;--i)
	    if(leading && prod[i]==0)
		continue;
	    else {
		leading = false;
		ret.push_back(digits[prod[i]]);
	    }

	if(ret.empty())
	    ret = "0";
	
	return ret;
    }
};

int main() {

    Solution s;
    string s1("12"),s2("0");
    string ret = s.multiply(s1,s2);
    cout << ret << endl;
}
