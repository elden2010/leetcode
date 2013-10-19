class Solution {
    vector<int> masks; // 81 rows * 9 bits
public:
    bool isValidSudoku(vector<vector<char> > &board) {
	masks.clear();
	masks.resize(81,512);// 512=2^9

	for(int i=0;i<9;++i)
	    for(int j=0;j<9;++j)
		if(board[i][j]!='.') {
		    int c = board[i][j]-'0';
		    int tomask = ~(1 << (c-1));

		    // set all elements in the same row
                    // by disabling one bit (9...1)
		    for(int col=0;col<9;++col)
			masks[i*9+col] &= tomask;

		    // same column
		    for(int row=0;row<9;++row)
			masks[row*9+j] &= tomask;

		    // same block
		    int I=i/3,J=j/3; // block index
		    for(int row=0;row<3;row++)
			for(int col=0;col<3;++col)
			    masks[(3*I+row)*9+(3*J+col)] &= tomask;

		    // itself
		    masks[i*9+j] = ~tomask;
		}

	// check if any masks element is 0, meaning none choice for the cell = invalid
	for(int z=0;z<81;++z)
	    if(masks[z]==0)
		return false;

	return true;
        
    }
};
