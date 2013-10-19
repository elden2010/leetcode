#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  static const vector<string> ones,tens,hundreds,thousands;
public:
  string intToRoman(int num);
};

const vector<string> Solution::ones{"","I","II","III","IV","V","VI","VII","VIII","IX"},
                     Solution::tens{"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                 Solution::hundreds{"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                Solution::thousands{"","M","MM","MMM"}; 

string Solution::intToRoman(int num) {
  string ret;
  if (num<1 || num>3999)
    return ret;
  
  ret += thousands[num/1000];
  ret += hundreds[num/100%10];
  ret += tens[num/10%10];
  ret += ones[num%10];
  
  return ret;  
}

int main() {
  Solution s;
  for(int i=0;i<100;i++)
    cout << s.intToRoman(i) << endl;
}

