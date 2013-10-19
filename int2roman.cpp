#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  vector<string> ones{"I","II","III","IV","V","VI","VII","VIII","IX"},
                 tens{"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
             hundreds{"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            thousands{"M","MM","MMM"}; 
public:
  string intToRoman(int num) {
    string ret;
    if (num<1 || num>3999)
      return ret;

    if(num>=1000) {
      ret += thousands[num/1000-1];
      num = num % 1000;
    }

    if(num>=100) {
      ret += hundreds[num/100-1];
      num = num % 100;
    }

    if(num>=10) {
      ret += tens[num/10-1];
      num = num % 10;
    }

    if(num>0)
      ret += ones[num-1];
    
    return ret;  
  }

  
};

int main() {
  Solution s;
  for(int i=0;i<100;i++)
    cout << s.intToRoman(i) << endl;
}

