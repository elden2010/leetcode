#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
	int m=strlen(s);
	int n=strlen(p);
        cout << m <<  " " << n << endl;



    }
};

int main() {
    Solution s;
    cout << s.isMatch("bad","d*a*c*c*asdasd*asd") << endl;
    
}
