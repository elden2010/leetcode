#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
	int n = strlen(s);
	if(n==0)
	    return 0;

	int idx2 = -1; // store the last non-blank position
	for(int i=n-1;i>=0;--i)
	    if(*(s+i)!=' ') {
		idx2 = i;
		break;
	    }
	if(idx2==-1)
	    return 0;
	
	int idx = -1; // store the last blank before idx2
	for(int i=idx2-1;i>=0;--i)
	    if(*(s+i)==' ') {
		idx = i;
		break;
	    }

	if(idx==-1)
	    return idx2+1;
	else
	    return idx2-idx;
	    
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("hellow world") << endl;
}
