#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    static unordered_map<string,int> base;// cannot use map as const, so I removed const here
public:
  int romanToInt(string s);
};

unordered_map<string,int> Solution::base = { {"I",1},{"II",2},{"III",3},{"IV",4},{"V",5},{"VI",6},{"VII",7},{"VIII",8},{"IX",9},
				     {"X",10},{"XX",20},{"XXX",30},{"XL",40},{"L",50},{"LX",60},{"LXX",70},{"LXXX",80},{"XC",90},
				     {"C",100},{"CC",200},{"CCC",300},{"CD",400},{"D",500},{"DC",600},{"DCC",700},{"DCCC",800},{"CM",900},
				     {"M",1000},{"MM",2000},{"MMM",3000} }; 

int Solution::romanToInt(string s) {
  int ret = 0;
  int n = s.size();

  int i=0;
  while(i<n) {
      char ch = s[i];
      string group;
      bool found;
      int j;

      switch(ch) {

      case 'I':
      case 'V':
	  // no need to find next group, since I must be the last group
	  group = s.substr(i);
	  ret += base[group];
	  i = n;
	  break;

      case 'X':
      case 'L':
	  // find next group I/V
	  found=false;
	  j=i+1;
	  for(;j<n;++j)
	      if(s[j]=='I' || s[j]=='V') {
		  found = true;
		  break;
	      }
	  if(found) {
	      group = s.substr(i,j-i);
	      i = j;
	  } else {
	      group = s.substr(i);
	      i = n;
	  }
	  ret += base[group];	  
	  break;

      case 'C':
      case 'D':
	  // find next group I/V or X/L
	  found=false;
	  j=i+1;
	  for(;j<n;++j)
	      if(s[j]=='X' || s[j]=='L' || s[j]=='I' || s[j]=='V') {
		  found = true;
		  break;
	      }
	  if(found) {
	      group = s.substr(i,j-i);
	      i = j;
	  } else {
	      group = s.substr(i);
	      i = n;
	  }
	  ret += base[group];	  
	  break;

      case 'M':
	  // find next group I/V or X/L or C/D
	  found=false;
	  j=i+1;
	  for(;j<n;++j)
	      if(s[j]=='X' || s[j]=='L' || s[j]=='I' || s[j]=='V' || s[j]=='C' || s[j]=='D') {
		  found = true;
		  break;
	      }
	  if(found) {
	      group = s.substr(i,j-i);
	      i = j;
	  } else {
	      group = s.substr(i);
	      i = n;
	  }
	  ret += base[group];	 
	  break;
      }
  };  
  return ret;  
}

int main() {
  Solution s;
  cout << s.romanToInt("MDCCCLXXXIV") << endl;
}

