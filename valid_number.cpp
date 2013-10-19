/*
1. integer
2. float
3. scientifc representation
4. +/- before
5.6.7.8.

OMG: 2 hours! too many strange cases!

*/
#include <string>
#include <iostream>

using namespace std;

class Solution {
    bool isalldigit(string s) {
	for(int i=0;i<s.size();++i)
	    if(!isdigit(s[i]))
		return false;
	return true;
    }
public:
    bool isNumber(const char *s) {
	string s0(s);
	
	// 1. trim both ends
	int ii=0;
	for(;ii<s0.size();++ii)
	    if(s0[ii]!=' ')
		break;
	// extreme case: all blanks
	if(ii==s0.size())
	    return false;
	int jj=s0.size()-1;
	for(;jj>=0;--jj)
	    if(s0[jj]!=' ')
		break;
	string s1 = s0.substr(ii,jj-ii+1);
       
	// 2. find ind of first e
	int inde=-1;
	for(int i=0;i<s1.size();++i)
	    if(s1[i]=='e') {
		inde = i;
		break;
	    }
	
	// 3. break string s1 into s2 e s23
	string s23;
	if(inde!=-1) {
	    s23 = s1.substr(inde+1);
	    // make sure s23 is valid integer
	    if(s23[0]=='+'||s23[0]=='-')
		s23 = s23.substr(1);
	    if(s23.empty())
		return false;
	    if(!isalldigit(s23))
		return false;
	}
	
        // denote the part before e as s2
	string s2;
	if(inde!=-1)
	    s2 = s1.substr(0,inde);
	else
	    s2 = s1;
	
	// 3. check first . on s2
	int inddot = -1;
	for(int i=0;i<s2.size();++i)
	    if(s2[i]=='.') {
		inddot=i;
		break;
	    }
	// break s21 into s21 . s22
	string s21,s22;
	if(inddot!=-1) {
	    s22 = s2.substr(inddot+1);
	    s21 = s2.substr(0,inddot);
	} else
	    s21 = s2;


	//  make sure s21 is valid integer
	if(s21[0]=='+'||s21[0]=='-')
	    s21 = s21.substr(1);
	if(s21.empty() && s22.empty())
	    return false;
	if(!isalldigit(s21))
	    return false;
	if(!isalldigit(s22))
	    return false;


	return true;
    }
};

int main() {

    Solution s;
    cout << s.isNumber("+.1") << endl;
}
