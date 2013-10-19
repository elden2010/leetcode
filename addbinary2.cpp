/*
gonna add directly so it works for very large numbers
 */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    
    // swap so pa -> longer string
    string ret;
    int la = a.size();
    int lb = b.size();
    if(la<lb) {
      string tmp1 = a;
      a = b;
      b = tmp1;
      int tmp2 = la;
      la = lb;
      lb = tmp2;
    }
    
    bool carry = false;
    for(int i=0;i<la;++i) {
      if(i<lb) {// add a,b bits and carryover
	if(carry) {
	  if(a[la-1-i] != b[lb-1-i])
	    ret += '0';
	  else 
	    if(a[la-1-i]=='0' && b[lb-1-i]=='0') {
	      ret += '1';
	      carry = false;
	    } else
	      ret += '1';
	} else {
	  if(a[la-1-i] != b[lb-1-i])
	    ret += '1';
	  else
	    if(a[la-1-i]=='0' && b[lb-1-i]=='0')
	      ret += '0';
	    else {
	      ret += '0';
	      carry = true;
	    }
	}	  
      } else { // add a and carryover bit
	if(carry) {
	  if(a[la-1-i]=='0') {
	    ret += '1';
	    carry = false;
	  } else
	    ret += '0';
	} else
	  ret += a[la-1-i];
      }
      
    }
    
    if(carry)
      ret += '1';
    reverse(ret.begin(),ret.end());
    return ret;
  }
};

int main() {
  string a = "1";
  string b = "111";
  Solution s;
  cout << s.addBinary(a,b) << endl;
}
