class Solution {
private:
	int row, col;
public:
	void solve(vector<vector<char>>& board) {
        int i,j;
        row=board.size();
        if(!row) return;
        col=board[0].size();

		for(i=0;i<row;i++){
			if(board[i][0]=='O')
				check(board,i,0);
			if(col>1 && board[i][col-1]=='O')
				check(board,i,col-1);
		}

		for(j=1;j+1<col;j++){
			if(board[0][j]=='O')
				check(board,0,j);
			if(row>1 && board[row-1][j]=='O')
				check(board,row-1,j);
		}

		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='O')
					board[i][j]='X';

		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='1')
					board[i][j]='O';
    }

	void check(vector<vector<char> >&vec,int i,int j){
		vec[i][j]='1';
		if(i>1 && vec[i-1][j]=='O')
			check(vec,i-1,j);
		if(j>1 && vec[i][j-1]=='O')
			check(vec,i,j-1);
		if(i+1<row && vec[i+1][j]=='O')
			check(vec,i+1,j);
		if(j+1<col && vec[i][j+1]=='O')
			check(vec,i,j+1);
	}
};

