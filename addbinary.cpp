/*
can only works for numbers within int range
 */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string dec2binstr(int v) {
  string ret;
  if(v==0)
    ret = "0";
  else
    while(v>0) {
      if(v & 1)
	ret += "1";
      else
	ret += "0";
      v = v>>1;
    }

  reverse(ret.begin(),ret.end());
  return ret;
}

int binstr2dec(string str) {
  int v = 0;
  for(int i=0;i<str.size();++i)
    if(str[str.size()-1-i]=='1')
      v += 1<<i;
  return v;
}

class Solution {
public:
  string addBinary(string a, string b) {
    int va = binstr2dec(a);
    int vb = binstr2dec(b);
    string ret = dec2binstr(va+vb);
    return ret;
  }
};

int main() {
  string a = "0";
  string b = "0";
  Solution s;
  cout << s.addBinary(a,b) << endl;
}
