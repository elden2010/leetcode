class Solution {
    vector<string> map;
public:
    Solution() {
	map.push_back("");     //
	map.push_back("");     
	map.push_back("abc");  // 2
	map.push_back("def");
	map.push_back("ghi");
	map.push_back("jkl");
	map.push_back("mno");
	map.push_back("pqrs");
	map.push_back("tuv");
	map.push_back("wxyz"); // 9
    }
    vector<string> letterCombinations(string digits) {
        vector<string> vs;

	if(digits.empty()) {
	    vs.push_back("");
	    return vs;
	}


	for(int i=0;i<digits.size();++i) {
	    int digit = digits[i]-'1'+1;
	    string str = map[digit];
	    if(vs.empty()) {
		for(int j=0;j<str.size();++j)
		    vs.push_back(str.substr(j,1));
	    } else {
		int vsz = vs.size(); // vs will grow
		for(int ii=0;ii<vsz;++ii)
		    for(int j=0;j<str.size();++j)
			if(j==0) 
			    vs[ii].push_back(str[j]);
			else {
			    vs.push_back(vs[ii]);
			    vs[vs.size()-1][vs[ii].size()-1] = str[j];
			}
	    }
	}

        return vs;
    }
};
