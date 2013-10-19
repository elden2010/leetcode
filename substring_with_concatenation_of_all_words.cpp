#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void printme(vector<int> vi) {
    for(int i=0;i<vi.size();++i)
	cout << vi[i] << " ";
    cout << endl;
}

class Solution {
    bool valid(vector<int> ind, int i, const vector<string> &L3, const vector<int> &L4) {
	int m = ind.size();
	int n = L3[0].size();
	int K = L4.size();
	if(m-i<K*n)
	    return false;

	vector<int> ind2;
	for(int z=i;z<i+K*n;++z) {
	    int tmp = (z-i)%n;	    
	    if(tmp==0)
		if(ind[z]!=-1)
		    ind2.push_back(ind[z]);
		else
		    return false;
	}

//	cout << "i=" << i<< ", ind2:" << endl;
//	printme(ind2);
	
	sort(ind2.begin(),ind2.end());

//	cout << "after sorting, i=" << i<< ", ind2:" << endl;
//	printme(ind2);
	

	//verify ind2 sorted is the same as L3
//	cout << "L4:" << endl;
//	printme(L4);
	
	if(ind2.size()!=L4.size())
	    cout << "debug me 4" << endl;

	bool ret = true;
	for(int z=0;z<L4.size();++z)
	    if(ind2[z]!=L4[z]) {
		ret = false;
		break;
	    }

//	cout << "ret=" << ret << endl;
	return ret;
	
	
    }
public:
    vector<int> findSubstring(string S, vector<string> &L) {
	vector<int> ret;
	if(L.empty())
	    return ret;

	// make L unique
	map<string,int> L2;
	for(int i=0;i<L.size();++i)
	    L2[L[i]] ++;

	// also store L2 in L3 as vector
	vector<string> L3;
	for(map<string,int>::iterator it=L2.begin();it!=L2.end();++it)
	    L3.push_back(it->first);

	// also store index of L in L3
	vector<int> L4(L.size(),-1);
	for(int i=0;i<L.size();++i)
	    for(int j=0;j<L3.size();++j)
		if(L[i]==L3[j]) {
		    L4[i] = j;
		    break;
		}
	// sort L4, since we don't care order
	sort(L4.begin(),L4.end());	
	

	// verify
//	for(map<string,int>::iterator it=L2.begin();it!=L2.end();++it)
//	    cout << it->first << " has " << it->second << " repeat(s)!" << endl;
//	cout << "L has elements from L3:" << endl;
//	for(int i=0;i<L.size();++i)
//	    cout << L4[i] << " ";
//	cout<<endl;
	
	int m = S.size();
	int K = L.size();
	int n = L[0].size();

	// find each occurrence
	vector<int> ind(m,-1);
	for(int i=0;i<m;++i) {
	    string str = S.substr(i,n);
	    if(L2.count(str)>0) { // this is the most important line for speed, otherwise it won't pass large data test
		for(int j=0;j<L3.size();++j)
		    if(str==L3[j]) {
			ind[i] = j;
			break;
		    }
	    }
	}

//	cout << "ind:" << endl;
//	printme(ind);

	for(int i=0;i<m;++i)
	    if(valid(ind,i,L3,L4))
		ret.push_back(i);
	
	return ret;
     }
};

int main() {
    string S("abaababbaba"),l1("ba"),l2("ab"),l3("ab");
    vector<string> L;
    L.push_back(l1);
    L.push_back(l2);
    L.push_back(l3);

    Solution s;
    vector<int> ret = s.findSubstring(S,L);
    for(int i=0;i<ret.size();++i)
	cout << ret[i] << " ";
    cout << endl;
}
