class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
	if(strs.empty())
	    return string("");

        // find the shortest size of strs
	string dummy;
	int shortest = dummy.max_size();
	for(int i=0;i<strs.size();++i)
	    if(strs[i].size()<shortest)
		shortest = strs[i].size();

	// 
	string ret;
	for(int z=0;z<shortest;++z) {
	    bool equal = true;
	    char cz = strs[0][z];
	    for(int i=1;i<strs.size();++i)
		if(strs[i][z]!=cz) {
		    equal = false;
		    break;
		}
	    if(equal)
		ret += strs[0].substr(z,1);
	    else
		break;
	}
	

	return ret;
    }
};
