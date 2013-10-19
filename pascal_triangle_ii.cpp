class Solution {
public:
    vector<int> getRow(int rowIndex) {
	vector<int> ret;
	
	for(int i=0;i<rowIndex+1;++i) {
	    vector<int> row(i+1,1);
	    if(i==0)
		row[i] = 1;
	    else
		for(int j=1;j<i;++j)
		    row[j] = ret[j-1]+ret[j];
	    ret = row;
        }
	return ret;

    }

};
