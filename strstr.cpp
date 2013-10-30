/*
the bruteforce way is O(mn) complexity
leetcode accepts it as well
*/

/*
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int m = strlen(haystack);
        int n = strlen(needle);
        for(int i=0;i<m-n+1;++i) {
            int j;            
            for(j=0;j<n;++j)
                if(haystack[i+j]!=needle[j])
                    break;
            if(j==n)
                return haystack+i;
        }
        return NULL;
    }
};
*/
#include <iostream>
#include <limits>

using namespace std;

// now the Robin-Karp method for O(m+n) complexity
class Solution {
    static const int base = 31;
    static const unsigned int prime = 100001;
    int hash(string str) {
	int h = 0;
	for(int i=0;i<str.size();++i) {
	    h = h*base + static_cast<int>(str[i]);
	    h %= prime;
	}
	return h;
    }
    
     int expMod(int base,int power,int Q) {
	 int ret = 1;
	int cc = 0;
	while(cc<power) {
	    ret *= base;
            ret %= Q;
            cc++;
	}
	return ret;
    }

public:
    char *strStr(char *haystack, char *needle) {
	string hay2(haystack), ned2(needle);
	int m = hay2.size();
        int n = ned2.size();

	int big = expMod(base,n-1,prime);
	
	int hashNed2 = hash(ned2);
	int hashHay2 = hash(hay2.substr(0,n));
	if(hashHay2==hashNed2)
	    return haystack;
	
        for(int i=1;i<m-n+1;++i) {
	    // now old char hay2[i-1] disappears
	    int tmp = hashHay2 - static_cast<int>(hay2[i-1])*big % prime;
	    if (tmp<0)
		tmp += prime;
            // new char hay2[i+n-1],
	    hashHay2 = tmp *base+ static_cast<int>(hay2[i+n-1]);	
	    hashHay2 %= prime;

//	    hashHay2 = hash(hay2.substr(i,n));
	    //
	    if (hashHay2==hashNed2)
		return haystack+i;
	}

	return NULL;
    }

};

int main() {
    Solution s;
    char haystack[] = "mississippi";
    char needle[] = "issi";

    //cout << (1<<31) -1 << endl;



    char *ret = s.strStr(haystack, needle);
    while(*ret!='\0')
	cout << *(ret++) << endl;

}
