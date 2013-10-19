#include <vector>
#include <iostream>

using namespace std;

class Solution {
    bool searchRow(vector<vector<int> > &matrix,int row, int be,int en,int target) {
       if(be==en)
	   if(matrix[row][be]==target)
	       return true;
	   else
	       return false;
       if(en-be==1)
	   if(matrix[row][be]==target || matrix[row][en]==target)
	       return true;
	   else
	       return false;
       int mid = (be+en)/2;
	if(matrix[row][mid] == target)
	    return true;
	else if(matrix[row][mid]> target)
	    return searchRow(matrix,row,be,mid-1,target);
	else
	    return searchRow(matrix,row,mid+1,en,target);
    }
		
    bool search(vector<vector<int> > & matrix, int be, int en,int target) {
	if(be==en)
	    return searchRow(matrix,be,0,matrix[0].size()-1,target);
	else if(en-be==1)
	    if(matrix[en][0]>target)
		return searchRow(matrix,be,0,matrix[0].size()-1,target);
	    else
		return searchRow(matrix,en,0,matrix[0].size()-1,target);
	else {
	    int mid = (be+en)/2;
	    if(matrix[mid][0]==target)
		return true;
	    else
		if(matrix[mid][0]>target)
		    return search(matrix,be,mid-1,target);
		else
		    return search(matrix,mid,en,target);		    
	}
    }
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
	return search(matrix,0,matrix.size()-1,target);
    }
};

int main() {
    vector<vector<int> > mat = {{1},{3},{5}};
    Solution s;
    cout << s.searchMatrix(mat,5) << endl;
}
