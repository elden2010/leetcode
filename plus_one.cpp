class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
	vector<int> ret;
	int toadd = 1;
	for(int i=digits.size()-1;i>=0;--i) {
	    int tmp = digits[i] + toadd;	    
	    if(tmp>=10)
		ret.push_back(tmp - 10);
	    else {
		ret.push_back(tmp);
		toadd = 0;
	    }
	}
	if(toadd)
	    ret.push_back(1);
	reverse(ret.begin(),ret.end());
	return ret;
    }
};
