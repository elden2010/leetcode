#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

template<class T>
void print(const vector<vector<T>> &bd) {
    int n=bd.size();
    for(int i=0;i<n;++i) {
	for(int j=0;j<bd[i].size();++j)
	    cout << bd[i][j];
	cout << endl;
    }
}


class Solution {
    map<int,set<char> > candid; // need to keep a candidate list for each empty cell
    queue<int> single; // those cells with only single choices

    void print2() {
	cout << "candid set is: " << endl;
	for(map<int,set<char>>::iterator it=candid.begin();
	    it!=candid.end();++it) {
	    int z=it->first;
	    cout << "z="<<z<<":";
	    set<char> sc=it->second;
	    for(set<char>::iterator it2=sc.begin();it2!=sc.end();++it2)
		cout << *it2;
	    cout << endl;
	}
	cout << endl;
    }
    
    bool fixOne(vector<vector<char>> &bd,int smallz) {
        // cell smallz only contains tcan

//	cout << "fixing:"<< smallz << endl;
//	print(bd);
	
	if(candid.count(smallz)==0) {
//	    cout << "somehow it is already fixed" << endl;
	    return true;
	} /*else 
	    if(candid[smallz].size()>1) {
		cout << "trying to fix non-single-choice" << endl;
		return false;
	    }
	  */
	
	int n=bd.size();
	int nn=sqrt(n);
	char tcan = *(candid[smallz].begin());
	candid.erase(smallz);
	bd[smallz/n][smallz%n] = tcan;

	// update all other cells that might be affected due to fixing of cell smallz
	int i=smallz/n, j=smallz%n, r=i/nn,c=j/nn;	    
	map<int,set<char> > candid2(candid);
	for(map<int,set<char>>::iterator it=candid.begin();it!=candid.end();++it) {
	    int herez = it->first;
	    set<char> sc = it->second;

	    if(sc.count(tcan)==0)
		continue; // must contain tcan
		
	    int ii=herez/n;
	    int jj=herez%n;
	    int rr=ii/nn;
	    int cc=jj/nn;
	    if(ii==i || jj==j || (r==rr && c==cc)) // same row or col or group
		if(sc.size()>2) // erase one char from set
		    candid2[herez].erase(tcan);
	        else if(sc.size()==2){// ==2
		    candid2[herez].erase(tcan);
		    single.push(herez);
		} else if(sc.size()==1) { // conflict: another cell has tcan as only choice as well
//		    cout << "(ii=" << ii<<",jj="<<jj<<") has same "<< tcan << endl;
//		    cout << "(i=" << i<<",j="<<j<<") has same "<< tcan << endl;
//		    cout << *(sc.begin()) << endl;
		    return false;
		} else
		    cout << "debug 4" << endl;
	    
	}

	candid = candid2;

	//cout << "after fixing:"<< smallz << endl;
	//print(bd);
	
	return true;
    }
    
    bool solve(vector<vector<char>> &bd) {
        // note that sets in candid have at least 2 chars 
//	cout << "solve bd: " << endl << endl;
//	print(bd);
//	cout << endl;

	if(candid.empty())
	    return true;

	// get rid of single-choice candidates
	while(!single.empty()) {
	    int z = single.front();
	    single.pop();
	    bool success = fixOne(bd,z);
	    if(!success)
		return false;
	}


//	cout << "resolved all single choice, bd: " << endl << endl;
//	print(bd);
//	print2();


//	cin.get();

	bool ret=true;
	int n = bd.size();
	int nn = sqrt(n);

	// look for a cell with the smallest number of candidates
	int smallest = n+1;
	int smallz = -1; // saving the cell index
	for(map<int,set<char>>::iterator it=candid.begin();it!=candid.end();++it) {
	    int tsz = it->second.size();
	    if(tsz<2)
		cout << "debug me too" << endl;
	    if(smallest>tsz) {
		smallest = tsz;
		smallz = it->first;
	    }	
	}	
	set<char> smallcan = candid[smallz];
 

	// try candidates in smallcan one by one, with location at smallz
	for(set<char>::iterator it=smallcan.begin();it!=smallcan.end();++it) {
	    char tcan = *it;
//	    cout << "at smallz="<< smallz << ",try tcan=" << tcan<< endl;
	    vector<vector<char>> bd2(bd);
	    map<int,set<char>> candid2(candid);

	    
	    // as we use candid, we just let caniud[smallz] be single-char-set
	    // it will force the change in fixOne
	    set<char> singlechar;
	    singlechar.insert(tcan);
	    candid[smallz] = singlechar;
	    while(!single.empty())
		single.pop();
	    single.push(smallz);

	    // try the new version
	    ret = solve(bd2);
	    if(ret) {
//		cout << "at smallz=" << smallz << ", successful tcan=" << tcan << endl;
		bd = bd2;
		break;
	    } else {// restore candid 
//		cout << "at smallz=" << smallz << ", failed tcan=" << tcan << endl;		
		candid = candid2;
//		print(bd);
	    }
	}

	return ret;
    }

public:
    void solveSudoku(vector<vector<char> > &board) {
	// clear variables
	candid.clear();
	while(!single.empty())
	    single.pop();

	int n = board.size();
	int nn = sqrt(n);
	set<char> fullchar;
	for(int i=0;i<9;++i)
	    fullchar.insert('1'+i);

        // read board to fill out 
	for(int i=0;i<n;++i)
	    for(int j=0;j<n;++j) {
		//	if(i==5 && j==2)
		//cout << "i=" <<i<<",j="<<j<<"board[i][j]="<<board[i][j] << endl;

		if(board[i][j]=='.') {
		    int z = n*i+j;		    
		    set<char> cd(fullchar);		    

		    // collect same row cells
		    for(int jj=0;jj<n;++jj) {
			char ch =board[i][jj];
			if(ch!='.') 
			    cd.erase(ch);
		    }

		    // collect same column cells
		    for(int ii=0;ii<n;++ii) {
			char ch =board[ii][j];
			if(ch!='.')
			    cd.erase(ch);
		    }

		    // collect same 3*3 group cells
		    int r=i/nn,c=j/nn;
		    for(int ii=0;ii<nn;++ii)
			for(int jj=0;jj<nn;++jj) {
			    char ch = board[r*nn+ii][c*nn+jj];
			    if(ch!='.') {
				//	cout << "erasing from group:" << ch<< endl;
				cd.erase(ch);
			    }
			}
		    
		    // check cd and save if possible
		    if(cd.empty())
			cout << "debug me"<< endl;
		    else {
			candid[z] = cd;
			if(cd.size()==1)
			    single.push(z);
		    }
		    //print(board);
		    //cin.get();
		}
	    }

	// solve it iteratively
	solve(board);
    }
};



int main() {

    vector<string> vs={"1...7..3.","83.6.....","..29..6.8","6....49.7",".9.....5.","3.75....4","2.3..91..",".....2.43",".4..8...9"};
    vector<vector<char> > mat;
    for(int i=0;i<9;++i) {
	vector<char> row;
	for(int j=0;j<9;++j)
	    row.push_back(vs[i][j]);
	mat.push_back(row);
    }

    print(mat);

    Solution s;
    s.solveSudoku(mat);

    print(mat);
}
